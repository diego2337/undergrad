<?php

require 'model/Ataque.php';

class AtaqueFactory extends AbstractFactory {
    
    public function __construct() {
        parent::__construct();
    }
    
    public function buscar($param) {
        $busca = $param;
        
        try {
            $sth = $this->database->prepare("SELECT * FROM Ataque WHERE nome_ataque LIKE :busca");
            
            $busca = "%".$busca."%";
            
            $sth->bindParam(":busca", $busca);
            
            $sth->execute();
            
            $ataques = array ();

            while ($obj =  $sth->fetchObject())
            {
                    $ataque = new Ataque();

                    $ataque->setNome($obj->nome_ataque);
                    $ataque->setTipo($obj->tipo_ataque);
                    $ataque->setQuantidade($obj->quantidade);
                    $ataque->setPoder($obj->poder);
                    $ataque->setPrecisao($obj->precisao);
                    $ataque->setEfeito($obj->efeito);
                    $ataque->setUso_fora_batalha($obj->uso_fora_da_batalha);
                    $ataques[] = $ataque;       
            }
            
            return $ataques;
            
            
        } catch (Exception $exc) {
            echo $exc->getTraceAsString();
        }

    }
    
    
    
   public function buscarTipo($param) {
        $busca = $param;
        echo "TIPO DO ATAQUE".$busca;
        
        if($busca == 'Água')
        {
            
            $busca = 'Ãgua';
            echo "TIPO DO ATAQUE".$busca;
        }
        
        try {
            $sth = $this->database->prepare("SELECT * FROM Ataque WHERE tipo_ataque LIKE :busca");
            
            $busca = "%".$busca."%";
            
            $sth->bindParam(":busca", $busca);     $sth->execute();
            
            $ataques = array ();

            while ($obj =  $sth->fetchObject())
            {
                    $ataque = new Ataque();

                    $ataque->setNome($obj->nome_ataque);
                    $ataque->setTipo($obj->tipo_ataque);
                    $ataque->setQuantidade($obj->quantidade);
                    $ataque->setPoder($obj->poder);
                    $ataque->setPrecisao($obj->precisao);
                    $ataque->setEfeito($obj->efeito);
                    $ataque->setUso_fora_batalha($obj->uso_fora_da_batalha);
                    $ataques[] = $ataque;       
            }
            
            return $ataques;
            
            
        } catch (Exception $exc) {
            echo $exc->getTraceAsString();
        }
    }


    public function listar() {
        
       try {
            $sth = $this->database->prepare("SELECT * FROM Ataque");
            
            $sth->execute();
            
            $ataques = array ();

            while ($obj =  $sth->fetchObject())
            {
                    $ataque = new Ataque();

                    $ataque->setNome($obj->nome_ataque);
                    $ataque->setTipo($obj->tipo_ataque);
                    $ataque->setQuantidade($obj->quantidade);
                    $ataque->setPoder($obj->poder);
                    $ataque->setPrecisao($obj->precisao);
                    $ataque->setEfeito($obj->efeito);
                    $ataque->setUso_fora_batalha($obj->uso_fora_da_batalha);
                    $ataques[] = $ataque;       
            }
            
            return $ataques;
            
            
        } catch (Exception $exc) {
            echo $exc->getTraceAsString();
        }
    }

    /* @TODO */
    public function alterar($object) {

        $nome = $object->getNome();
        $tipo = $object->getTipo();
        $qtd = $object->getQuantidade();
        $poder= $object->getPoder();
        $prec = $object->getPrecisao();
        $efeito = $object->getEfeito();
        $uso = $object->getUso_fora_batalha();
       
        
         try {
            
            $sthe = $this->database->prepare("UPDATE Ataque SET nome_ataque = :nome, tipo_ataque = :tipo, quantidade = :qtd, poder = :poder, precisao = :prec, efeito = :efeito, uso_fora_da_batalha = :uso WHERE nome_ataque = :nome2" );

            $sthe->bindParam(":nome", $nome);
            $sthe->bindParam(":tipo", $tipo);           
            $sthe->bindParam(":qtd", $qtd);
            $sthe->bindParam(":poder", $poder);
            $sthe->bindParam(":prec", $prec);
            $sthe->bindParam(":efeito", $efeito);
            $sthe->bindParam(":uso", $uso); 
            $sthe->bindParam(":nome2", $nome);

            return $sthe->execute();  
            
            
        } catch(PDOException $e) {
           echo $e->getMessage();
        }
    }
    
    /* @todo */
    public function inserir($object) {

        $nome = $object->getNome();
        $tipo = $object->getTipo();
        $qtd = $object->getQuantidade();
        $poder= $object->getPoder();
        $prec = $object->getPrecisao();
        $efeito = $object->getEfeito();
        $uso = $object->getUso_fora_batalha();
       
        
         try {
            
            $sthe = $this->database->prepare("INSERT INTO Ataque (nome_ataque, tipo_ataque, quantidade, poder, precisao,  efeito, uso_fora_da_batalha) VALUES (:nome, :tipo, :qtd, :poder, :prec, :efeito, :uso )" );

            $sthe->bindParam(":nome", $nome);
            $sthe->bindParam(":tipo", $tipo);           
            $sthe->bindParam(":qtd", $qtd);
            $sthe->bindParam(":poder", $poder);
            $sthe->bindParam(":prec", $prec);
            $sthe->bindParam(":efeito", $efeito);
             $sthe->bindParam(":uso", $uso); 
            return $sthe->execute();  
            
            
        } catch(PDOException $e) {
           echo $e->getMessage();
        }
    }
    

    public function remover($param) {
        $ataque = $param;
        
        try {
            
            $sth = $this->database->prepare("DELETE FROM Ataque WHERE nome_ataque = :ataque");
            $sth->bindParam(":ataque", $ataque);
            
            $sth->execute();

            
        } catch(PDOException $e) {
           echo $e->getMessage();
        }
        
    }
}


?>

