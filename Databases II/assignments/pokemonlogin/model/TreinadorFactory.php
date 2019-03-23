<?php

//require 'model/AbstractFactory.php';
require 'model/Treinador.php';

class TreinadorFactory extends AbstractFactory {
    
    
    public function alterar($object) {
        
        $id =  (int)$object->getId();
        $nome = $object->getNome();
        $insignas = $object->getNum_insignas();
        $capturados =  $object->getQtd_pokemons_capturados();
        $vistos =  $object->getQtd_pokemons_vistos();
        $sexo = $object->getSexo();
        $login =  $object->getLogin();
        $senha = $object->getSenha();
        
         try {
            
            $sthe = $this->database->prepare("UPDATE Treinador SET senha = :senha 
                                                WHERE id_treinador = :id" );

            $sthe->bindParam(":senha", $senha);          
             $sthe->bindParam(":id", $id); 
            return $sthe->execute();  
            
            
        } catch(PDOException $e) {
           echo $e->getMessage();
        }
        
       
    }
    
    public function listar(){
        
        try {
            $sth = $this->database->prepare("SELECT * FROM Treinador");

            $sth->execute();
            
            $treinadores = array ();

            while ($obj =  $sth->fetchObject())
            {
                    $treinador = new Treinador();


                    $treinador->setId ($obj->id_treinador);
                    $treinador->setNome($obj->nome_treinador);
                    $treinador->setNum_insignas($obj->num_insignas);
                    $treinador->setQtd_pokemons_capturados ($obj->qtd_pokemons_capturados);
                    $treinador->setQtd_pokemons_vistos ($obj->qtd_pokemons_vistos);
                    $treinador->setSexo($obj->sexo);
                    $treinador->setLogin($obj->login);
                    $treinadores []  = $treinador;
            }
            
            return $treinadores;
            
            
        } catch (Exception $exc) {
            echo $exc->getTraceAsString();
        }
        
    }

    public function buscar($param) {
        $busca = $param;
        
        try {
            $sth = $this->database->prepare("SELECT * FROM Treinador WHERE login LIKE :busca");
            
            $busca = "%".$busca."%";
            
            $sth->bindParam(":busca", $busca);
            
            $sth->execute();
            
            $treinadores = array ();

            while ($obj =  $sth->fetchObject())
            {
                    $treinador = new Treinador();


                    $treinador->setId ($obj->id_treinador);
                    $treinador->setNome($obj->nome_treinador);
                    $treinador->setNum_insignas($obj->num_insignas);
                    $treinador->setQtd_pokemons_capturados ($obj->qtd_pokemons_capturados);
                    $treinador->setQtd_pokemons_vistos ($obj->qtd_pokemons_vistos);
                    $treinador->setSexo($obj->sexo);
                    $treinador->setLogin($obj->login);
                    $treinadores []  = $treinador;
            }
            
            return $treinadores;
            
            
        } catch (Exception $exc) {
            echo $exc->getTraceAsString();
        }

    }

    public function inserir($object) {
        
      //  $id =  $object->getId();
        $nome = $object->getNome();
        $insignas = $object->getNum_insignas();
        //$capturados =  $object->getQtd_pokemons_capturados();
        $vistos = $object->getQtd_pokemons_vistos();
        $sexo =  $object->getSexo();
        $login =  $object->getLogin();
        $senha =  $object->getSenha();
        $senha = md5($senha);
        if($vistos > 386)
            $vistos = 386;
        try {
            
            $sthe = $this->database->prepare("INSERT INTO Treinador (nome_treinador, num_insignas, qtd_pokemons_vistos , sexo, login, senha, qtd_pokemons_capturados ) VALUES (:nome, :insignas, :vistos, :sexo, :login, :senha, 0)");

//            $sthe->bindParam(":num", $id);
            $sthe->bindParam(":nome", $nome);
            $sthe->bindParam(":insignas", $insignas);
  //          $sthe->bindParam(":capturados", $capturados);
            $sthe->bindParam(":vistos", $vistos);
            $sthe->bindParam(":sexo", $sexo);
            $sthe->bindParam(":login", $login);
            $sthe->bindParam(":senha", $senha);
            
            $sthe->execute();  
            
            
        } catch(PDOException $e) {
           echo $e->getMessage();
        }
        
        
    }
    public function remover($param) {
        try {
            
            $id = (int)$param;
                
            $sth = $this->database->prepare("DELETE FROM Treinador WHERE id_treinador = :id");
            $sth->bindParam(":id", $id);
            
            $sth->execute();

            
        } catch(PDOException $e) {
           echo $e->getMessage();
        }
        
        
        
    }    
    
    public function incrementaPokemon($param)
    {
        
        $id = $param;
        echo 'ID'.$id;
        
         try {
            
            $sthe = $this->database->prepare("UPDATE Treinador SET qtd_pokemons_capturados = qtd_pokemons_capturados + 1 WHERE id_treinador = :id" );
            
            $sthe->bindParam(":id", $id); 
            return $sthe->execute();  
            
            
        } catch(PDOException $e) {
           echo $e->getMessage();
        }
    }
    
    public function buscarLogin($param) {
        $busca = $param;
        
        try {
            $sth = $this->database->prepare("SELECT * FROM Treinador WHERE login = :busca");
                       
            $sth->bindParam(":busca", $busca);
            
            $sth->execute();
            
            $pokemons = array ();

            while ($obj =  $sth->fetchObject())
            {
                    $treinador = new Treinador();

                    $treinador->setId($obj->id_treinador);
                    $treinador->setNome($obj->nome_treinador);
                    $treinador->setNum_insignas($obj->num_insignas);
                    $treinador->setQtd_pokemons_capturados($obj->qtd_pokemons_capturados);
                    $treinador->setQtd_pokemons_vistos($obj->qtd_pokemons_vistos);
                    $treinador->setLogin($obj->login);
                    $treinadores []  = $treinador;
            }
            
            return $treinadores;
            
            
        } catch (Exception $exc) {
            echo $exc->getTraceAsString();
        }
    
    
    }
}

?>
