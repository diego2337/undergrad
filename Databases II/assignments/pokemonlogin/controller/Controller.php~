<?php

require 'model/PokemonFactory.php';
require 'model/TreinadorFactory.php';
require 'model/AtaqueFactory.php';
require 'model/AtaquePokemonFactory.php';
require 'model/ItemFactory.php';
require 'model/PokemartFactory.php';
require 'model/UserFactory.php';
require 'model/TreinadorPokemonFactory.php';
require 'model/TreinadorItemFactory.php';

class Controller {

    public function __construct() {
        session_start();
    }

    public function start() {
        
        
       $action = isset($_GET['action']) ? $_GET['action'] : 'index';
       
       if($action=='login'){
           if(isset($_SESSION['User'])){
               $this->indexAction();
           } else {
               $this->loginAction();
           }
           return;
           
       }
       
       if($action=='logoff'){
           $this->logoffAction();
           return;           
       }
       
       if($action=='auth') {
           if(isset($_SESSION['User'])){
               $this->indexAction();
           } else {
               $this->authAction();
           }
           return;
       }
       
    
            switch ($action) {
                case 'index':
                    $this->indexAction();
                    break;
                  
                case 'showPainel':
		  if(isset($_SESSION['User'])){	    
                    $this->showPainelAction();
                 }else 
                 {
			require 'view/login.php';
		  }
		    
		    break;
                    
                case 'insertPokemon':
		  if(isset($_SESSION['User']) && $_SESSION['User'] == 'professor'){	    
                    $this->insertPokemonAction();
                 }else 
                 {
			require 'view/login.php';
		  }
                    break;
                case 'insertPokemonDB':
                    $this->insertPokemonActionDB();
                    break;
                case 'buscaPokemon':
                    $this->buscaPokemonAction();
                    break;
                case 'deletePokemon':
                 if(isset($_SESSION['User']) && $_SESSION['User'] == 'professor'){	    
                    $this->deletePokemonAction();
                 }else 
                 {
			require 'view/login.php';
		  }
                    break;
                case 'listarPokemon':
                    $this->listarPokemonAction();
                    break;
                case 'showPokemon':
                    $this->showPokemonAction();
                    break;
                case 'editPokemon':
                 if(isset($_SESSION['User']) && $_SESSION['User'] == 'professor')
                    $this->editPokemonAction();
                 else 
		    require 'view/login.php';
		  
                    break;
                case 'editPokemonDB':
                if(isset($_SESSION['User']) && $_SESSION['User'] == 'professor')
                    $this->editPokemonActionDB();
                 else 
		    require 'view/login.php';          
                    break;
                case 'listarAtaque':
                    $this->listarAtaqueAction();
                    break;
                case 'deleteAtaque':
		  if(isset($_SESSION['User']) && $_SESSION['User'] == 'professor')
                    $this->deleteAtaqueAction();
		  else 
		    require 'view/login.php';       
		  break;
                case 'insertAtaque':
		  if(isset($_SESSION['User']) && $_SESSION['User'] == 'professor')
                    $this->insertAtaqueAction();
		  else 
		    require 'view/login.php';       
		  break;
                case 'insertAtaqueDB':
                if(isset($_SESSION['User']) && $_SESSION['User'] == 'professor')
                    $this->insertAtaqueActionDB();
		  else 
		    require 'view/login.php';       
		  break;
                case 'editAtaque':
		  if(isset($_SESSION['User']) && $_SESSION['User'] == 'professor')
                    $this->editAtaqueAction();
		  else 
		    require 'view/login.php';       
		  break;
                case 'editAtaqueDB':
		  if(isset($_SESSION['User']) && $_SESSION['User'] == 'professor')
		    $this->editAtaqueActionDB();
		  else 
		    require 'view/login.php';       
		  break;
                case 'buscaAtaque':
                    $this->buscaAtaqueAction();
                    break;
                case 'insertTreinador':
                    $this->insertTreinadorAction();
                    break;
                case 'insertTreinadorDB':
                    $this->insertTreinadorActionDB();
                    break;
                case 'buscaTreinadorDB':
                    $this->insertTreinadorActionDB();
                    break;
                case 'deleteTreinador':
		  if(isset($_SESSION['User']) && $_SESSION['User'] == 'professor')
		   $this->deletePokemonAction();
		  else 
		    require 'view/login.php';       
		  break;  
                case 'listarTreinador':
                    $this->listarTreinadorAction();
                    break;
                case 'buscaTreinador':
                    $this->buscaTreinadorAction();
                    break;
                case 'insertItem':
		  if(isset($_SESSION['User']) && $_SESSION['User'] == 'professor')
		   $this->insertItemAction();
		  else 
		    require 'view/login.php';       
		  break;  
                case 'insertItemDB':
		  if(isset($_SESSION['User']) && $_SESSION['User'] == 'professor')
		   $this->insertItemActionDB();
		  else 
		    require 'view/login.php';       
		  break;  
                case 'listarItem':
		    $this->listarItemAction();
		  break;  
                case 'buscaItem':
                    $this->buscarItemAction();
                    break;
                case 'editItem':
                if(isset($_SESSION['User']) && $_SESSION['User'] == 'professor')
		   $this->editItemAction();
		  else 
		    require 'view/login.php';       
		  break; 
                case 'editItemDB':
                  if(isset($_SESSION['User']) && $_SESSION['User'] == 'professor')
		   $this->editItemActionDB();
		  else 
		    require 'view/login.php';       
		  break; 
                case 'deleteItem':
                if(isset($_SESSION['User']) && $_SESSION['User'] == 'professor')
		   $this->deleteItemAction();
		  else 
		    require 'view/login.php';       
		  break; 
                case 'insertPokermart':
                  if(isset($_SESSION['User']) && $_SESSION['User'] == 'professor')
		   $this->insertPokemartAction();
		  else 
		    require 'view/login.php';       
		  break;
                case 'insertPokermartDB':
                if(isset($_SESSION['User']) && $_SESSION['User'] == 'professor')
		   $this->insertPokemartActionDB();
		  else 
		    require 'view/login.php';       
		  break; 
                case 'listarPokermart':
                    $this->listarPokemartAction();
                    break;
                case 'buscaPokermart':
                    $this->buscarPokemartAction();
                    break;
                case 'editPokermart':
		  if(isset($_SESSION['User']) && $_SESSION['User'] == 'professor')
		   $this->editPokemartAction();
		  else 
		    require 'view/login.php';       
		  break; 
                case 'editPokemartDB':
		  if(isset($_SESSION['User']) && $_SESSION['User'] == 'professor')
		   $this->editPokemartActionDB();
		  else 
		    require 'view/login.php';       
		  break; 
		case 'showPainel':
		  if(isset($_SESSION['User']))
		    $this->showPainelAction();
		  else 
		    require 'view/login.php';       
		  break; 
		case 'verMeusPokemons':
		  if(isset($_SESSION['User']))
		    $this->verMeusPokemonsAction();
		  else 
		    require 'view/login.php';       
		  break;
                case 'listarCaptura':
                  if(isset($_SESSION['User']))
		    $this->listarCapturaAction();
		  else 
		    require 'view/login.php';  
                    break;
                case 'capturaPokemon':
                    if(isset($_SESSION['User']))
		    $this->capturaPokemonAction();
		  else 
		    require 'view/login.php';  
                    break;
                case 'capturaPokemonDB':
                    if(isset($_SESSION['User']))
                     $this->capturaPokemonActionDB();
		  else 
		    require 'view/login.php';  
                    break;    
                case 'vinculaAtaque':
                    if(isset($_SESSION['User']))
                     $this->vinculaAtaqueAction();
		  else 
		    require 'view/login.php';  
                    break;    
                case 'vinculaAtaqueDB':
                    if(isset($_SESSION['User']))
                     $this->vinculaAtaqueActionDB();
                    else 
                        require 'view/login.php';  
                    break;
                case 'showMyPokemon':
                    if(isset($_SESSION['User']))
                        $this->showMyPokemonAction();
                     else 
                        require 'view/login.php'; 
                    break;
                case 'adicionarTreinadorItem':
                     if(isset($_SESSION['User']))
                         $this->adicionaItemTreinadorAction ();
                     else
                        require 'view/login.php';  
                     break; 
                case 'adicionarTreinadorItemDB':
                     if(isset($_SESSION['User']))
                         $this->adicionaItemTreinadorActionDB();
                     else
                        require 'view/login.php';  
                     break;
                     
                case 'verMeusItens':
                     if(isset($_SESSION['User']))
                         $this->verItemTreinadorAction();
                     else
                        require 'view/login.php';  
                     break;
                case 'usarItem':
                     if(isset($_SESSION['User']))
                         $this->usarItemAction();
                     else
                        require 'view/login.php';  
                     break;
                case 'buscaMeusPokemons':
                     if(isset($_SESSION['User']))
                         $this->buscaMeusPokemonsAction();
                     else
                        require 'view/login.php';  
                     break;     
                case 'buscaMeuItem':
                    if(isset($_SESSION['User']))
                         $this->buscarMeusItensAction();
                     else
                        require 'view/login.php';  
                     break;     
                case 'alterarSenha':
                    if(isset($_SESSION['User']))
                         $this->alterarSenhaAction();
                     else
                        require 'view/login.php';  
                     break;   
                case 'alterarSenhaDB':
                    if(isset($_SESSION['User']))
                         $this->alterarSenhaActionDB();
                     else
                        require 'view/login.php';  
                     break;
                case 'alterarPokemonAtaque':
                    if(isset($_SESSION['User']))
                         $this->alterarPokemonAtaqueAction();
                     else
                        require 'view/login.php';  
                     break;
                       
                 case 'alterarPokemonAtaqueDB':
                    if(isset($_SESSION['User']))
                         $this->alterarPokemonAtaqueActionDB();
                     else
                        require 'view/login.php';  
                     break;
                default:
                    $this->notFound();
                    //throw new Exception("Undefined Controller...", 1);
                    break;
            } 
        
      
    }

    public function indexAction() {
        require 'view/index.php';
    }
    
    public function loginAction() {
        require 'view/login.php';
    }
    
    public function logoffAction(){
         session_unset();
        session_destroy();
        require 'view/login.php';
    }
    
    public function authAction() {
        $login = $_POST["login"];
        $pass = $_POST["senha"];
        
        $userfactory = new UserFactory();
        
        if($userfactory->authenticate($login, $pass)){
            $_SESSION['User'] = $login;
            $this->indexAction();
        } else {
            require "view/login.php";
        }
        
    }

    /* ########################## POKEMON ############################# */

    public function insertPokemonAction() {
     $tipo = array('Água' => 'Água', 'Fogo' => 'Fogo', 'Planta' => 'Planta', 'Elétrico'=> 'Elétrico', 'Psiquico' => 'Psiquico', 'Gelo' => 'Gelo', 'Dragão' => 'Dragão', 'Inseto' => 'Inseto', 'Noturno'=>'Noturno', 'Terrestre'=>'Terrestre', 'Pedra'=>'Pedra', 'Venenoso'=>'Venenoso', 'Normal'=>'Normal', 'Lutador'=>'Lutador', 'Voador'=>'Voador', 'Fantasma'=>'Fantasma');
        $regiao = array('Kanto' => 'Kanto', 'Johto' => 'Johto', 'Hoenn' => 'Hoenn', 'Sinnoh' => 'Sinnoh', 'Unova' => 'Unova', 'Sevii islands' => 'Sevii Islands');

        require 'view/insere/inserir_pokemon.php';
    }

    public function insertPokemonActionDB() {

        $num = isset($_POST['num']) ? (int) $_POST['num'] : 0;
        $nome = isset($_POST['nome']) ? $_POST['nome'] : 'Pokemon sem nome';
        $tipo = isset($_POST['tipo']) ? $_POST['tipo'] : '';
        $nivel = isset($_POST['nivel']) ? (int) $_POST['nivel'] : 0;
        $regiao = isset($_POST['regiao']) ? $_POST['regiao'] : '';
        $descricao = isset($_POST['descricao']) ? $_POST['descricao'] : '';

        $pokemon = new Pokemon();

        $pokemon->setNumber($num);
        $pokemon->setName($nome);
        $pokemon->setType($tipo);
        $pokemon->setLevel($nivel);
        $pokemon->setRegion($regiao);
        $pokemon->setDescription($descricao);

        $pokemonFactory = new PokemonFactory();

        $pokemonFactory->inserir($pokemon);

        $this->listarPokemonAction();
    }

    public function buscaPokemonAction() {

        $pokemon = new PokemonFactory();
        $busca = isset($_POST['nome']) ? $_POST['nome'] : "";

        $pokemons = $pokemon->buscar($busca);

        require 'view/listar/listar_pokemon.php';
    }

    public function deletePokemonAction() {
        $pokemon = new PokemonFactory();
        $param = isset($_GET["idPokemon"]) ? $_GET["idPokemon"] : "";
        $pokemon->remover($param);

        $this->listarPokemonAction();
    }

    public function listarPokemonAction() {
        $pokemon = new PokemonFactory();

        $pokemons = $pokemon->listar();

        require 'view/listar/listar_pokemon.php';
    }

    public function showPokemonAction() {

        $pokemon = new PokemonFactory();
        $param = isset($_GET["idPokemon"]) ? $_GET["idPokemon"] : "";

        $pokemons = $pokemon->buscarId($param);

        require 'view/show/show_pokemon.php';
    }

    public function editPokemonAction() {

        $pokemon = new PokemonFactory();
        $param = isset($_GET["idPokemon"]) ? $_GET["idPokemon"] : "";

        $pokemons = $pokemon->buscarId($param);

        if ($pokemons) {
            $tipo = array('agua' => 'Água', 'fogo' => 'Fogo', 'planta' => 'Planta', 'psico' => 'Psico', 'gelo' => 'Gelo', 'dragao' => 'Dragão', 'inseto' => 'Inseto');
            $regiao = array('kanto' => 'Kanto', 'hoenn' => 'Hoenn', 'sinnoh' => 'Sinnoh', 'unova' => 'Unova', 'sevii_islands' => 'Sevii Islands');

            require 'view/editar/editar_pokemon.php';
        } else {
            $this->listarPokemonAction();
        }
    }

    public function editPokemonActionDB() {

        $num = isset($_POST['num']) ? (int) $_POST['num'] : 0;
        $nome = isset($_POST['nome']) ? $_POST['nome'] : 'Pokemon sem nome';
        $tipo = isset($_POST['tipo']) ? $_POST['tipo'] : '';
        $nivel = isset($_POST['nivel']) ? (int) $_POST['nivel'] : 0;
        $regiao = isset($_POST['regiao']) ? $_POST['regiao'] : '';
        $descricao = isset($_POST['descricao']) ? $_POST['descricao'] : '';

        $pokemon = new Pokemon();

        $pokemon->setNumber($num);
        $pokemon->setName($nome);
        $pokemon->setType($tipo);
        $pokemon->setLevel($nivel);
        $pokemon->setRegion($regiao);
        $pokemon->setDescription($descricao);

        $pokemonFactory = new PokemonFactory();
        if ($pokemonFactory->alterar($pokemon))
            $msg = "Alterado com sucesso";
        else
            $msg = "Não foi alterado com sucesso";

        $this->listarPokemonAction();
    }

    /* ####################### TREINADOR ##################### */

    public function insertTreinadorAction() {

        require 'view/insere/inserir_treinador.php';
    }

    public function insertTreinadorActionDB() {

      //  var_dump($_POST);
   
      //  $num = isset($_POST['num']) ? (int) $_POST['num'] : 0;
        $nome = isset($_POST['nome']) ? $_POST['nome'] : 'Treinador sem nome';
        $login = isset($_POST['login']) ? $_POST['login'] : 'Treinador sem login';
        $senha = isset($_POST['senha']) ? $_POST['senha'] : 'lalala';
        $vistos = isset($_POST['vistos']) ?  (int)$_POST['vistos'] : '';
        $insignas = isset($_POST['insignas']) ? (int) $_POST['insignas'] : 0;
        $sexo = isset($_POST['sexo']) ? $_POST['sexo'] : '';
       
	//$senha = md5($senha);
        $treinador = new Treinador();

        $treinador->setLogin($login);
        $treinador->setNome($nome);
        $treinador->setNum_insignas($insignas);
        $treinador->setQtd_pokemons_vistos($vistos);
        $treinador->setSexo($sexo);
        $treinador->setSenha($senha);

        $treinadorFactory = new TreinadorFactory;
        
      //  var_dump($treinador);
        
        $treinadorFactory->inserir($treinador);

        $this->logoffAction();
    }

    public function deleteTreinadorAction() {

        require 'view/insere/inserir_treinador.php';
    }

    public function listarTreinadorAction() {
        $treinador = new TreinadorFactory();

        
        $treinadores = $treinador->listar();
        

        require 'view/listar/listar_treinador.php';
    }

    public function buscaTreinadorAction() {

        $treinador = new TreinadorFactory();
        $busca = isset($_POST['nome']) ? $_POST['nome'] : "";


        // Verifica se a busca não contém nada
        if ($busca != "") {
            $treinadores = $treinador->buscar($busca);
        } else {
            $treinadores = array();
        }

        require 'view/busca/buscar_treinador.php';
    }

    /* ####################### ATAQUE ##################### */

    public function listarAtaqueAction() {
        $ataque = new AtaqueFactory();

        $ataques = $ataque->listar();

        require 'view/listar/listar_ataque.php';
    }
    
    public function deleteAtaqueAction() {
        $ataque = new AtaqueFactory();
        $param = isset($_GET["idAtaque"]) ? $_GET["idAtaque"] : "";
        $ataque->remover($param);

        $this->listarAtaqueAction();
    }

    public function insertAtaqueAction() {
        require 'view/insere/inserir_ataque.php';
    }

    public function insertAtaqueActionDB() {

       // var_dump($_POST);

        $nome = isset($_POST['nome']) ? $_POST['nome'] : 'Ataque sem nome';
        $tipo = isset($_POST['tipo']) ? $_POST['tipo'] : '';
        $quantidade = isset($_POST['quantidade']) ? (int) $_POST['quantidade'] : 0;
        $poder = isset($_POST['poder']) ? (int) $_POST['poder'] : 0;
        $precisao = isset($_POST['precisao']) ? (int) $_POST['precisao'] : 0;

        if (isset($_POST['uso_fora_batalha'])) {
            if ($_POST['uso_fora_batalha'] == "Sim") {
                $uso = 1;
            } else {
                $uso = 0;
            }
        } else {
            $uso = 0;
        }

        $efeito = isset($_POST['efeito']) ? $_POST['efeito'] : '';

        $ataque = new Ataque();

        $ataque->setNome($nome);
        $ataque->setTipo($tipo);
        $ataque->setQuantidade($quantidade);
        $ataque->setPoder($poder);
        $ataque->setPrecisao($precisao);
        $ataque->setUso_fora_batalha($uso);
        $ataque->setEfeito($efeito);

        $ataqueFactory = new AtaqueFactory();
        $ataqueFactory->inserir($ataque);
        $this->listarAtaqueAction();
    }

    public function editAtaqueAction() {

        $ataque = new AtaqueFactory();
        $param = isset($_GET["idAtaque"]) ? $_GET["idAtaque"] : "";

        $ataques = $ataque->buscar($param);

        if ($ataques) {
            require 'view/editar/editar_ataque.php';
        } else {
            $this->listarAtaqueAction();
        }
    }

    public function editAtaqueActionDB() {

        $nome = isset($_POST['nome']) ? $_POST['nome'] : 'Ataque sem nome';
        $tipo = isset($_POST['tipo']) ? $_POST['tipo'] : '';
        $quantidade = isset($_POST['quantidade']) ? (int) $_POST['quantidade'] : 0;
        $poder = isset($_POST['poder']) ? (int) $_POST['poder'] : 0;
        $precisao = isset($_POST['precisao']) ? (int) $_POST['precisao'] : 0;

        if (isset($_POST['uso_fora_batalha'])) {
            if ($_POST['uso_fora_batalha'] == "1") {
                $uso = 1;
            } else {
                $uso = 0;
            }
        } else {
            $uso = 0;
        }

        $efeito = isset($_POST['efeito']) ? $_POST['efeito'] : '';

        $ataque = new Ataque();


        $ataque->setNome($nome);
        $ataque->setTipo($tipo);
        $ataque->setQuantidade($quantidade);
        $ataque->setPoder($poder);
        $ataque->setPrecisao($precisao);
        $ataque->setUso_fora_batalha($uso);
        $ataque->setEfeito($efeito);

        $ataqueFactory = new AtaqueFactory();

        $ataqueFactory->alterar($ataque);
        $this->listarAtaqueAction();
    }
    
    public function buscaAtaqueAction(){
        $ataque = new AtaqueFactory();
        $busca = isset($_POST['nome']) ? $_POST['nome'] : "";    

        $ataques = $ataque->buscar($busca);
        
        require 'view/listar/listar_ataque.php';
    }

    /* ############################# ITEM ############################## */

    public function insertItemAction() {
        require 'view/insere/inserir_item.php';
    }

    public function insertItemActionDB() {
	// var_dump($_POST);
        $nome = isset($_POST['nome']) ? $_POST['nome'] : 'Ataque sem nome';
        $codigo = isset($_POST['codigo']) ? $_POST['codigo'] : 0;
        $preco = isset($_POST['preco']) ? (int) $_POST['preco'] : 0;
        $funcao = isset($_POST['funcao']) ? $_POST['funcao'] : '';


        $item = new Item();


        $item->setNome($nome);
        $item->setCodigo($codigo);
        $item->setPreco($preco);
        $item->setFuncao($funcao);

        $itemFactory = new ItemFactory();
        $itemFactory->inserir($item);
        $this->listarItemAction();
    }

    public function listarItemAction() {
        $item = new ItemFactory();

        $itens = $item->listar();

        require 'view/listar/listar_item.php';
    }
    
    public function buscarItemAction() {
        $item = new ItemFactory();
        
        $busca = isset($_POST['nome']) ? $_POST['nome'] : "";
        
        $itens = $item->buscar($busca);

        require 'view/listar/listar_item.php';
    }

    public function deleteItemAction() {
        $item = new ItemFactory();
        $param = isset($_GET["idItem"]) ? $_GET["idItem"] : "";
        $item->remover($param);

        $this->listarItemAction();
    }
    
    public function  editItemAction(){
        $item = new ItemFactory();
        $param = isset($_GET["idItem"]) ? $_GET["idItem"] : "";

        $itens = $item->buscarId($param);
        
        require 'view/editar/editar_item.php';
        
    }

        public function editItemActionDB() {

        $nome = isset($_POST['nome']) ? $_POST['nome'] : 'Ataque sem nome';
        $codigo = isset($_POST['codigo']) ? $_POST['codigo'] : 0;
        $preco = isset($_POST['preco']) ? (int) $_POST['preco'] : 0;
        $funcao = isset($_POST['funcao']) ? $_POST['funcao'] : '';

        $item = new Item();


        $item->setNome($nome);
        $item->setCodigo($codigo);
        $item->setPreco($preco);
        $item->setFuncao($funcao);

        $itemFactory = new ItemFactory();
        $itemFactory->alterar($item);
        $this->listarItemAction();
    }
    
    
    /*#######################Pokermart###########################3*/
    
    public function insertPokemartAction() {
        require 'view/insere/inserir_pokemart.php';
    }

    public function insertPokemartActionDB() {

        $local = isset($_POST['local']) ? $_POST['local'] : 'Pokecenter sem local';
        $qtd = isset($_POST['qtd']) ? (int) $_POST['qtd'] : 0;

        $pokemart = new Pokemart();


        $pokemart->setLocal($local);
        $pokemart->setQtd_itens($qtd);

        $pokemartFactory = new PokemartFactory();
        $pokemartFactory->inserir($pokemart);
        $this->listarPokemartAction();
    }
    
    public function listarPokemartAction() {
        $pokemart = new PokemartFactory();

        $pokemarts = $pokemart->listar();

        require 'view/listar/listar_pokermart.php';
    }
    
    public function buscarPokemartAction(){
        $pokemart = new PokemartFactory();
        
        $busca = isset($_POST['nome']) ? $_POST['nome'] : "";

        $pokemarts = $pokemart->buscar($busca);

        require 'view/listar/listar_pokermart.php';
    }

    public function deletePokemartAction() {
        $pokemart = new PokemartFactory();
        $param = isset($_GET["idPokermart"]) ? $_GET["idPokermart"] : "";
        $pokemart->remover($param);

        $this->listarPokemartAction();
    }
    
    public function  editPokemartAction(){
        $pokemart = new PokemartFactory();
        $param = isset($_GET["idPokermart"]) ? $_GET["idPokermart"] : "";

        $pokemarts = $pokemart->buscar($param);
        
        require 'view/editar/editar_pokemart.php';
    }
    
    public function editPokemartActionDB() {

        $local = isset($_POST['local']) ? $_POST['local'] : 'Pokecenter sem local';
        $qtd = isset($_POST['qtd']) ? (int) $_POST['qtd'] : 0;

        $pokemart = new Pokemart();


        $pokemart->setLocal($local);
        $pokemart->setQtd_itens($qtd);

        $pokemartFactory = new PokemartFactory();
        $pokemartFactory->alterar($pokemart);
        $this->listarPokemartAction();
    }

    
    
    ############################Painel######################33
    public function showPainelAction() {
      $treinador = new TreinadorFactory();
      //$treinador_pokemon = new TreinadorPokemonFactory();
      //$treinador_pokemon->buscarLogin($_SESSION['User']);
      //$pokemons = $pokemon->buscarId($param);
      $treinadores = $treinador->buscarLogin($_SESSION['User']);
      
      require 'view/show/show_painel.php';
    }
    
    public function verMeusPokemonsAction() {
     
     $treinador_pokemon = new TreinadorPokemonFactory();
     $treinadores_poke = $treinador_pokemon->listar($_SESSION['User']);
      
      require 'view/listar/listar_poketreinador.php';
    }
    
    public function listarCapturaAction() {
        $pokemon = new TreinadorPokemonFactory();

        $pokemonsCap = $pokemon->listarCapturar();

        require 'view/listar/listar_pokemonCapturar.php';
    }
    
    
    public function capturaPokemonAction()
    {
        $pokemon = new PokemonFactory();
        $param = isset($_GET["idPokemon"]) ? $_GET["idPokemon"] : "";

        $pokemons = $pokemon->buscarId($param);
        require 'view/insere/insert_capturaPokemon.php';
        
    }




    public function capturaPokemonActionDB() {
        $num = isset($_POST['num']) ? (int) $_POST['num'] : 0;
        $nivel = isset($_POST['nivel']) ? (int) $_POST['nivel'] : 0;
        $apelido = isset($_POST['apelido']) ? $_POST['apelido'] : '';
      
        
        $treinador = new TreinadorFactory();
        
        $pokemon = new TreinadorPokemon();

         $treinadores = $treinador->buscarLogin($_SESSION['User']);
         foreach ($treinadores as $tre) {
           $pokemon->setId_treinador($tre->getId());
           $id = $tre->getId();
         }
        
        $treinador->incrementaPokemon($id);
        
        $pokemon->setNum_pokemon($num);
        $pokemon->setLevel($nivel);
        $pokemon->setApelido($apelido);

        $pokemonTreinadorFactory = new TreinadorPokemonFactory();

        $pokemonTreinadorFactory->inserir($pokemon);

        $this->listarPokemonAction();
    }
    
    
     public function showMyPokemonAction() {
        $ataquepokemon = new AtaquePokemonFactory(); 
        $pokemonT = new TreinadorPokemonFactory();
        $param = isset($_GET["idPokemon"]) ? $_GET["idPokemon"] : "";
        $qtdAtaque = $ataquepokemon->getQtd($_GET["idPokemon"]);
        $pokemonsT = $pokemonT->buscarId($_SESSION['User'], $param);
        
        $ataquepokemonF = $ataquepokemon->buscar($_GET["idPokemon"]);
        
        require 'view/show/show_pokemonCapturado.php';
    }
    
    
    
     public function vinculaAtaqueAction() {
        $tipo = new PokemonFactory();
        $ataque = new AtaqueFactory();
        
       // $tipo = $tipo->buscaTipo();
        $ataques = $ataque->buscarTipo($_GET['tipoPokemon']);

        
        
        require 'view/listar/listarAtaqueVincular.php';
    }
    
    public function vinculaAtaqueActionDB() {
        $ataquePk = new PokemonAtaque();
        $atpkFactory = new AtaquePokemonFactory();
        $ataquePk->setId_pokemon($_GET['idPokemon']);
        $ataquePk->setAtaque($_GET['idAtaque']);
        $atpkFactory->inserir($ataquePk);
        $this->showPainelAction();
      
    }
    
    
    
    #************************Vincular ataque *#######################
    
    public function adicionaItemTreinadorAction()
    {
        $item = new ItemFactory();

        $itens = $item->listar();
        require 'view/listar/listar_AdicionarTreinadorItem.php';
        
    }
    public function adicionaItemTreinadorActionDB()
    {               
        $treItem = new TreinadorItem();
        $treItemFactory = new TreinadorItemFactory();
        $treinador = new TreinadorFactory();
        
        
        
         $treinadores = $treinador->buscarLogin($_SESSION['User']);
         foreach ($treinadores as $tre) {
           $treItem->setId_treinador($tre->getId());
         }
        
         $treItem->setCodigo_item($_GET['idItem']);
         $treItemFactory->inserir($treItem);
         $this->verItemTreinadorAction();
      //  require 'view/listar/listar_meusItens.php';
                             
    }
    
    public function verItemTreinadorAction()
    {
        $treinadorItem = new TreinadorItemFactory();
        $treinador = new TreinadorFactory();
        
        $treinadores = $treinador->buscarLogin($_SESSION['User']);
         foreach ($treinadores as $tre) {
           $id = (int)$tre->getId();
         }
         
         $itens = $treinadorItem->buscar($id);
         
        require 'view/listar/listar_meusItens.php';
        
        
    }
    
    public function usarItemAction()
    {
        $treinadorItem = new TreinadorItem();
        $treinadorItens = new TreinadorItemFactory();
        $treinador = new TreinadorFactory();
        
        $treinadores = $treinador->buscarLogin($_SESSION['User']);
         foreach ($treinadores as $tre) {
           $id = (int)$tre->getId();
         }
         
         $treinadorItem->setId_treinador($id);
         $treinadorItem->setCodigo_item($_GET['idItem']);
         $itens = $treinadorItens->remover($treinadorItem);
          $this->verItemTreinadorAction();
    }
    
    public function buscaMeusPokemonsAction()
    {
        $pokemon = new TreinadorPokemonFactory();
        $busca = isset($_POST['nome']) ? $_POST['nome'] : "";

        $treinadores_poke = $pokemon->buscar2($busca, $_SESSION['User']);
         require 'view/listar/listar_poketreinador.php';
    }
    
    public function buscarMeusItensAction()
    {
        $treItem = new TreinadorItemFactory();
        $busca = isset($_POST['nome']) ? $_POST['nome'] : "";
        
         $treinador = new TreinadorFactory();
        
        $treinadores = $treinador->buscarLogin($_SESSION['User']);
         foreach ($treinadores as $tre) {
           $id = (int)$tre->getId();
         }
        $itens = $treItem->buscar2($id, $busca);
         require 'view/listar/listar_meusItens.php';
    }
    
    public function alterarSenhaAction()
    {
                 
        require 'view/editar/editar_senha.php';
        
    }
    
    public function alterarSenhaActionDB()
    {
        $treinadorFactory = new TreinadorFactory();
        $treinador = $treinadorFactory->buscar($_SESSION['User']);
        
        var_dump($treinador);
        $treinadorNovo = new Treinador();
        
        foreach ($treinador as $tre):
            
                    //echo 'senha'.$tre->getSenha();
                    $treinadorNovo->setId($tre->getId());
                    $treinadorNovo->setNome($tre->getNome());
                    $treinadorNovo->setNum_insignas($tre->getNum_insignas());
                    $treinadorNovo->setQtd_pokemons_capturados($tre->getQtd_pokemons_capturados());
                    $treinadorNovo->setQtd_pokemons_vistos($tre->getQtd_pokemons_vistos());
                    $treinadorNovo->setSexo($tre->getSexo());
                    $treinadorNovo->setLogin($tre->getLogin());
                    $treinadorNovo->setSenha($tre->getSenha());
                    
                    
        endforeach;
        
        echo 'Senha velha: '.$_POST['senhaVelha'];
        echo 'Senha antigaa:'.$treinadorNovo->getSenha();
        echo 'Senha nova: '.$_POST['senhaNova'];
        
        if(md5($_POST['senhaVelha']) == md5($treinadorNovo->getSenha()))
        {
            $treinadorNovo->setSenha(md5($_POST['senhaNova']));
            echo 'entrou no if';
        }
        
        $treinadorFactory->alterar($treinadorNovo);
        $this->showPainelAction();
        
    }
    
    public function alterarPokemonAtaqueAction()
    {
        $tipo = new PokemonFactory();
        $ataque = new AtaqueFactory();
        
       // $tipo = $tipo->buscaTipo();
        $ataques = $ataque->buscarTipo($_GET['tipoPokemon']);

        
        
        require 'view/listar/listar_alteraPokemonAtaque.php';
    }
    
    public function alterarPokemonAtaqueActionDB()
    {

        
        $ataque = isset($_GET['idAtaque']);


        $ataque->setNome_ataque($nome);
        
        $ataque->setEfeito($efeito);

        $ataqueFactory = new AtaqueFactory();

        $ataqueFactory->alterar($ataque);
        $this->listarAtaqueAction();
        
        
    }
    
    
    public function notFound(){
        require 'view/404/not_found.php';
    }
    
    
    
    

}

?>

