<?php

require 'TreinadorItem.php';
class TreinadorItemFactory extends AbstractFactory
{
    public function __construct() {
        parent::__construct();
    }
   public function buscar($param) {
        $busca = (int)$param;
        
        try {
            $sth = $this->database->prepare("SELECT * FROM Treinador_item, Item  WHERE id_treinador LIKE :busca AND Treinador_item.codigo_item = Item.codigo_item AND quantidade > 0");
            
            $busca = "%".$busca."%";
            
            $sth->bindParam(":busca", $busca);
            
            $sth->execute();
            
//            $ataquepokes = array ();
            $treItens = array();
            while ($obj =  $sth->fetchObject())
            {
                    $treItem = new TreinadorItem();
                    $treItem->setNome_item($obj->nome_item);
                    $treItem->setPreco($obj->preco);
                    $treItem->setId_treinador ($obj->id_treinador);
                    $treItem->setCodigo_item($obj->codigo_item);
                    $treItem->setQuantidade($obj->quantidade);
                   // $ataquepoke->setRegion($obj->level_aprendido);
                    $treItens []  = $treItem;
                   
            }
            
            return $treItens;
            
            
        } catch (Exception $exc) {
            echo $exc->getTraceAsString();
        }

    }
    
     public function buscar2($param, $param2) {
        $busca = (int)$param;
        $nome = $param2;
        
        try {
            $sth = $this->database->prepare("SELECT * FROM Treinador_item, Item  
                                            WHERE id_treinador LIKE :busca AND 
                                            Treinador_item.codigo_item = Item.codigo_item AND 
                                            quantidade > 0 AND
                                            Item.nome_item = :nome ");
            
            $busca = "%".$busca."%";
            
            $sth->bindParam(":busca", $busca);
            $sth->bindParam(":nome", $nome);
            $sth->execute();
            
//            $ataquepokes = array ();
            $treItens = array();
            while ($obj =  $sth->fetchObject())
            {
                    $treItem = new TreinadorItem();
                    $treItem->setNome_item($obj->nome_item);
                    $treItem->setPreco($obj->preco);
                    $treItem->setId_treinador ($obj->id_treinador);
                    $treItem->setCodigo_item($obj->codigo_item);
                    $treItem->setQuantidade($obj->quantidade);
                   // $ataquepoke->setRegion($obj->level_aprendido);
                    $treItens []  = $treItem;
                   
            }
            
            return $treItens;
            
            
        } catch (Exception $exc) {
            echo $exc->getTraceAsString();
        }

    }
       
       
       public function alterar($object) {;}
       
       public function inserir($object) {
           
        $id = (int) $object->getId_treinador();
        $codigo = $object->getCodigo_item();       
      
         try {
            
            $sthe = $this->database->prepare("INSERT INTO Treinador_item (id_treinador, codigo_item, quantidade) VALUES (:id, :codigo, 1) ON DUPLICATE KEY UPDATE quantidade = quantidade + 1" );

            $sthe->bindParam(":id", $id);
            $sthe->bindParam(":codigo", $codigo);             
            return $sthe->execute();  
            
            
        } catch(PDOException $e) {
           echo $e->getMessage();
        }
           
           
           
           
           
           
       }
       public function remover($param) {
           $object = $param;
           
           
           $id = (int) $object->getId_treinador();
           $codigo = $object->getCodigo_item();  
           
         
              try {
            
            $sthe = $this->database->prepare("UPDATE Treinador_item SET quantidade = quantidade - 1 WHERE id_treinador = :id AND codigo_item = :codigo" );

            $sthe->bindParam(":id", $id);
            $sthe->bindParam(":codigo", $codigo);             
            return $sthe->execute();  
            
            
        } catch(PDOException $e) {
           echo $e->getMessage();
        }
           
           
       }
}

?>
