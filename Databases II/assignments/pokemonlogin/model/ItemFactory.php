<?php

//require 'model/AbstractFactory.php';
require 'model/Item.php';

class ItemFactory extends AbstractFactory {
    
    public function __construct() {
        parent::__construct();
    }
    
    public function buscar($param) {
        $busca = $param;
        
        try {
            $sth = $this->database->prepare("SELECT * FROM Item WHERE nome_item LIKE :busca");
            
            $busca = "%".$busca."%";
            
            $sth->bindParam(":busca", $busca);
            
            $sth->execute();
            
            $itens = array ();

            while ($obj =  $sth->fetchObject())
            {
                    $item= new Item();
                    $item->setFuncao($obj->funcao);
                    $item->setCodigo($obj->codigo_item);
                    $item->setPreco($obj->preco);
                    $item->setNome($obj->nome_item);
                    
                    
                    $itens []  = $item;
            }
            
            return $itens;
            
            
        } catch (Exception $exc) {
            echo $exc->getTraceAsString();
        }

    }
    
    public function buscarId($param) {
        $busca = $param;
        
        try {
            $sth = $this->database->prepare("SELECT * FROM Item WHERE codigo_item LIKE :busca");
            
            $busca = "%".$busca."%";
            
            $sth->bindParam(":busca", $busca);
            
            $sth->execute();
            
            $itens = array ();

            while ($obj =  $sth->fetchObject())
            {
                    $item= new Item();
                    $item->setFuncao($obj->funcao);
                    $item->setCodigo($obj->codigo_item);
                    $item->setPreco($obj->preco);
                    $item->setNome($obj->nome_item);
                    
                    
                    $itens []  = $item;
            }
            
            return $itens;
            
            
        } catch (Exception $exc) {
            echo $exc->getTraceAsString();
        }

    }
    

    public function listar() {
        
        try {
            
            $sth = $this->database->prepare("SELECT * FROM Item");
            $sth->execute();

            $itens = array ();

            while ($obj =  $sth->fetchObject())
            {
                    $item= new Item();
                    $item->setFuncao($obj->funcao);
                    $item->setCodigo($obj->codigo_item);
                    $item->setPreco($obj->preco);
                    $item->setNome($obj->nome_item);
                    
                    $itens []  = $item;
            }
            
            return $itens;
            
            
            
        } catch(PDOException $e) {
           echo $e->getMessage();
        }
    }

    /* @TODO */
    public function alterar($object) {
        
     
        $nome = $object->getNome();
        $funcao = $object->getFuncao();
        $codigo = $object->getCodigo();
        $preco =  $object->getPreco();
         try {
            
            $sthe = $this->database->prepare("UPDATE Item SET nome_item = :nome, funcao = :funcao, codigo_item = :codigo, preco = :preco WHERE codigo_item = :codigo2" );

    
            $sthe->bindParam(":nome", $nome);
            $sthe->bindParam(":funcao", $funcao);
            $sthe->bindParam(":codigo", $codigo);
            $sthe->bindParam(":preco", $preco);
            $sthe->bindParam(":codigo2", $codigo); 
            return $sthe->execute();  
            
            
        } catch(PDOException $e) {
           echo $e->getMessage();
        }
        
        
        
    }
    
    /* @todo */
    public function inserir($object) {
                
        $nome = $object->getNome();
        $funcao = $object->getFuncao();
        $codigo = $object->getCodigo();
        $preco =  $object->getPreco();
        
        
        try {
            
            $sthe = $this->database->prepare("INSERT INTO Item (nome_item, funcao, codigo_item, preco) 
                VALUES (:nome, :funcao, :codigo, :preco)");
            
            
            $sthe->bindParam(":nome", $nome);
            $sthe->bindParam(":funcao", $funcao);
            $sthe->bindParam(":codigo", $codigo);
            $sthe->bindParam(":preco", $preco);
            
            $sthe->execute();  
            
            
        } catch(PDOException $e) {
           echo $e->getMessage();
        }
        
        
    }
    

    public function remover($param) {
        
        try {
            
            $codigo = (int)$param;
                
            $sth = $this->database->prepare("DELETE FROM Item WHERE codigo_item = :codigo");
            $sth->bindParam(":codigo", $codigo);
            
            $sth->execute();

            
        } catch(PDOException $e) {
           echo $e->getMessage();
        }
        
    }
}


?>
