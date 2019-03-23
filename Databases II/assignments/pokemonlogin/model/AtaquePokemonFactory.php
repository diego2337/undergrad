<?php
require 'model/PokemonAtaque.php';

class AtaquePokemonFactory extends AbstractFactory
{
    
    public function __construct() {
        parent::__construct();
    }
    
    
    public function buscar($param) {
        $busca = $param;
        
        try {
            $sth = $this->database->prepare("SELECT * FROM Treinador_treina_Pokemon WHERE id_pokemon LIKE :busca");
            
            $busca = "%".$busca."%";
            
            $sth->bindParam(":busca", $busca);
            
            $sth->execute();
            
            $ataquepokes = array ();

            while ($obj =  $sth->fetchObject())
            {
                    $ataquepoke = new PokemonAtaque();

                    $ataquepoke->setId_pokemon ($obj->id_pokemon);
                    $ataquepoke->setAtaque($obj->nome_ataque);
                   // $ataquepoke->setRegion($obj->level_aprendido);
                    $ataquepokes []  = $ataquepoke;
                   
            }
            
            return $ataquepokes;
            
            
        } catch (Exception $exc) {
            echo $exc->getTraceAsString();
        }

    }
    
    
    
    
    
    public function inserir($object)
    {
        $num = (int) $object->getId_pokemon();
        $apelido = $object->getAtaque();
       
        //echo 'numero e ataque'.$num.$apelido;
         try {
            
            $sthe = $this->database->prepare("INSERT INTO Treinador_treina_Pokemon (id_pokemon, nome_ataque) VALUES (:id, :nome)" );

            $sthe->bindParam(":id", $num);
            $sthe->bindParam(":nome", $apelido);           
            //$sthe->bindParam(":nivel", $nivel);
            
            
            return $sthe->execute();  
            
            
        } catch(PDOException $e) {
           echo $e->getMessage();
        }
        
        
    }
    
    public function getQtd($param)
    {
        
          $busca = $param;
        
        try {
            $sth = $this->database->prepare("SELECT * FROM Treinador_treina_Pokemon WHERE id_pokemon LIKE :busca");
            
            $busca = "%".$busca."%";
            
            $sth->bindParam(":busca", $busca);
            
            $sth->execute();
            
            $ataquepokes = array ();

            while ($obj =  $sth->fetchObject())
            {
                    $ataquepoke = new PokemonAtaque();

                    $ataquepoke->setId_pokemon ($obj->id_pokemon);
                    $ataquepoke->setAtaque($obj->nome_ataque);
                   // $ataquepoke->setRegion($obj->level_aprendido);
                    $ataquepokes []  = $ataquepoke;
                   
            }
            
            
            return sizeof($ataquepokes);
            
            
            
        } catch (Exception $exc) {
            echo $exc->getTraceAsString();
        }
    }
    
    public function alterar($object){
        
    }
    
    public function remover($param){
        
        
        
    }
}

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
?>
