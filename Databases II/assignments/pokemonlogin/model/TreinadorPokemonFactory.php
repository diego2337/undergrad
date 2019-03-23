<?php
  //require 'model/AbstractFactory.php';
  require 'model/TreinadorPokemon.php';
class TreinadorPokemonFactory extends AbstractFactory {
  
     public function __construct() {
        parent::__construct();
    }
    
    public function listar($param) {
      $busca = $param;
      
      try 
      {
	  //PENSAR NA BUSCA QUANDO TIVER MENOS CALOR
            $sth = $this->database->prepare("SELECT nome_pokemon, id_pokemon, apelido, level, Treinador_possui_Pokemon.numero_pokemon, tipo, regiao, descricao, imagem  
                                             FROM Treinador_possui_Pokemon, Treinador, Pokemon 
                                             WHERE Treinador.id_treinador = Treinador_possui_Pokemon.id_treinador AND Treinador.login = :busca AND Treinador_possui_Pokemon.numero_pokemon = Pokemon.numero_pokemon" );
      
            
            
	    $sth->bindParam(":busca", $busca);
            
            $sth->execute();
            
            $pokemonsT = array ();

            
            while ($obj =  $sth->fetchObject())
            {
                    $pokemonT = new TreinadorPokemon();

                    $pokemonT->setNome($obj->nome_pokemon);
                    $pokemonT->setId_pokemon($obj->id_pokemon);
                    $pokemonT->setApelido($obj->apelido);
                    $pokemonT->setLevel($obj->level);
                    $pokemonT->setNum_pokemon($obj->numero_pokemon);
                    $pokemonT->setRegion($obj->regiao);
                    $pokemonT->setImagem($obj->imagem);
                    $pokemonsT []  = $pokemonT;
            }
         return $pokemonsT;         
      } catch (Exception $exc) {
            echo $exc->getTraceAsString();
        }
      
        
    
    }
      
        public function listarCapturar() {
        
        try {
            
            $sth = $this->database->prepare("SELECT * FROM Pokemon");
            $sth->execute();

            $pokemons = array ();

            while ($obj =  $sth->fetchObject())
            {
                    $pokemon = new Pokemon();

                    
                    $pokemon->setNumber ($obj->numero_pokemon);
                    $pokemon->setType($obj->tipo);
                    $pokemon->setRegion($obj->regiao);
                    $pokemon->setName ($obj->nome_pokemon);
                    $pokemon->setLevel($obj->nivel);
                    $pokemons []  = $pokemon;

            }
            
            return $pokemons;
            
            
        } catch(PDOException $e) {
           echo $e->getMessage();
        }
    }  
      
    
    
    
   
    
    public function buscarId($param, $param2){     
        
        
      $busca = $param;
      $id = $param2;
      try 
      {
	  
            $sth = $this->database->prepare("SELECT nome_pokemon, id_pokemon, apelido, level, Treinador_possui_Pokemon.numero_pokemon, tipo, regiao, descricao, imagem  
                                             FROM Treinador_possui_Pokemon, Treinador, Pokemon 
                                             WHERE Treinador.id_treinador = Treinador_possui_Pokemon.id_treinador 
                                             AND Treinador.login = :busca 
                                             AND Treinador_possui_Pokemon.numero_pokemon = Pokemon.numero_pokemon 
                                             AND Treinador_possui_Pokemon.id_pokemon = :id" );
      
            
            
	    $sth->bindParam(":busca", $busca);
            $sth->bindParam(":id", $id);
            
            $sth->execute();
            
            $pokemonsT = array ();

            
            while ($obj =  $sth->fetchObject())
            {
                    $pokemonT = new TreinadorPokemon();

                    $pokemonT->setNome($obj->nome_pokemon);
                    $pokemonT->setId_pokemon($obj->id_pokemon);
                    $pokemonT->setApelido($obj->apelido);
                    $pokemonT->setLevel($obj->level);
                    $pokemonT->setNum_pokemon($obj->numero_pokemon);
                    $pokemonT->setRegion($obj->regiao);
                    $pokemonT->setImagem($obj->imagem);
                    $pokemonT->setType($obj->tipo);
                    $pokemonsT []  = $pokemonT;
            }
         return $pokemonsT;         
      } catch (Exception $exc) {
            echo $exc->getTraceAsString();
        }
        
    }
    
    public function inserir($object){
        
        
        $num = $object->getNum_pokemon();
        $apelido = $object->getApelido();
        $nivel = $object->getLevel();
        $id_treinador = $object->getId_treinador();
       
     
         try {
            
            $sthe = $this->database->prepare("INSERT INTO Treinador_possui_Pokemon (id_treinador, numero_pokemon, apelido, level) VALUES (:id, :num, :apelido, :nivel)" );

            $sthe->bindParam(":num", $num);
            $sthe->bindParam(":apelido", $apelido);           
            $sthe->bindParam(":nivel", $nivel);
            $sthe->bindParam(":id", $id_treinador);
            
            return $sthe->execute();  
            
            
        } catch(PDOException $e) {
           echo $e->getMessage();
        }
        
        
    }
    
    public function buscar($param){    ;    }
    
    
    
    public function buscar2($param, $param2){        
      $nome = $param;
      $login = $param2;
      try 
      {
	  
            $sth = $this->database->prepare("SELECT nome_pokemon, id_pokemon, apelido, level, Treinador_possui_Pokemon.numero_pokemon, tipo, regiao, descricao, imagem  
                                             FROM Treinador_possui_Pokemon, Treinador, Pokemon 
                                             WHERE Treinador.id_treinador = Treinador_possui_Pokemon.id_treinador 
                                             AND Treinador.login = :login 
                                             AND Treinador_possui_Pokemon.numero_pokemon = Pokemon.numero_pokemon 
                                             AND LOWER(Pokemon.nome_pokemon) = LOWER(:nome) " );
      
            
            
	    $sth->bindParam(":login", $login);
            $sth->bindParam(":nome", $nome);
            
            $sth->execute();
            
            $pokemonsT = array ();

            
            while ($obj =  $sth->fetchObject())
            {
                    $pokemonT = new TreinadorPokemon();

                    $pokemonT->setNome($obj->nome_pokemon);
                    $pokemonT->setId_pokemon($obj->id_pokemon);
                    $pokemonT->setApelido($obj->apelido);
                    $pokemonT->setLevel($obj->level);
                    $pokemonT->setNum_pokemon($obj->numero_pokemon);
                    $pokemonT->setRegion($obj->regiao);
                    $pokemonT->setImagem($obj->imagem);
                    $pokemonT->setType($obj->tipo);
                    $pokemonsT []  = $pokemonT;
            }
         return $pokemonsT;         
      } catch (Exception $exc) {
            echo $exc->getTraceAsString();
        }
   }
    
    public function alterar($object){echo 'lalala';} //nao vai ter
    
    public function remover($param){echo 'lalala';} //nao vai ter
  
  
  }
  
  
  ?>