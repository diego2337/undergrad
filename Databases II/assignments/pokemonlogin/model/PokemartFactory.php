<?php

require 'model/Pokemart.php';

class PokemartFactory extends AbstractFactory {
    
    public function __construct() {
        parent::__construct();
    }
    
    public function buscar($param) {
        $busca = $param;
        
        try {
            $sth = $this->database->prepare("SELECT * FROM Pokemon_mart WHERE local_pokemart LIKE :busca");
            
            $busca = "%".$busca."%";
            
            $sth->bindParam(":busca", $busca);
            
            $sth->execute();
            
            $pokemarts = array ();

            while ($obj =  $sth->fetchObject())
            {
                    $pokemart= new Pokemart();
                    $pokemart->setLocal($obj->local_pokemart);
                    $pokemart->setQtd_itens($obj->qtd_itens);
                    
                    $pokemarts []  = $pokemart;
            }
            
            return $pokemarts;
            
            
        } catch (Exception $exc) {
            echo $exc->getTraceAsString();
        }

    }
    

    public function listar() {
        
        try {
            
            $sth = $this->database->prepare("SELECT * FROM Pokemon_mart");
            $sth->execute();

            $pokemarts = array ();

            while ($obj =  $sth->fetchObject())
            {
                    $pokemart = new Pokemart();
                    $pokemart->setLocal($obj->local_pokemart);
                    $pokemart->setQtd_itens($obj->qtd_itens);
                    
                    $pokemarts []  = $pokemart;
            }
            
            return $pokemarts;
            
            
            
        } catch(PDOException $e) {
           echo $e->getMessage();
        }
    }

    /* @TODO */
    public function alterar($object) {
        
        $local = $object->getLocal();
        $qtd = $object->getQtd_itens();
        
         try {
            
            $sthe = $this->database->prepare("UPDATE Pokemon_mart SET local_pokemart = :local, qtd_itens = :qtd WHERE local_pokemart = :local2" );

    
            $sthe->bindParam(":local", $local);
            $sthe->bindParam(":qtd", $qtd);
            $sthe->bindParam(":local2", $local);
          
            return $sthe->execute();  
            
            
        } catch(PDOException $e) {
           echo $e->getMessage();
        }
        
        
        
    }
    
    /* @todo */
    public function inserir($object) {
        
        $local = $object->getLocal();
        $qtd = $object->getQtd_itens();
        
        try {
            
            $sthe = $this->database->prepare("INSERT INTO Pokemon_mart (local_pokemart, qtd_itens) VALUES (:local, :qtd_itens)");

            $sthe->bindParam(":local", $local);
            $sthe->bindParam(":qtd_itens", $qtd);
            
            $sthe->execute();  
            
            
        } catch(PDOException $e) {
           echo $e->getMessage();
        }       
    }
    
    public function remover($param) {
        try {
            
            $local = $param;
                
            $sth = $this->database->prepare("DELETE FROM Pokemon_mart WHERE local_pokemart = :local");
            $sth->bindParam(":local", $local);
        
            
            $sth->execute();

            
        } catch(PDOException $e) {
           echo $e->getMessage();
        }
        
    }
}


?>