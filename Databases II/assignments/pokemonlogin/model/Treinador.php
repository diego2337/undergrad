<?php


class Treinador {
    
    private $id;
    private $nome;
    private $num_insignas;
    private $qtd_pokemons_capturados;
    private $qtd_pokemons_vistos;
    private $sexo;
    private $login;
    private $senha;
    
    function __construct() {
        
    }
    
    
    public function getSenha() {
        return $this->senha;
    }
    
    public function setSenha($senha) {
        $this->senha = $senha;
    }   
    public function getId() {
        return $this->id;
    }

    public function setId($id) {
        $this->id = $id;
    }

    public function getNome() {
        return $this->nome;
    }

    public function setNome($nome) {
        $this->nome = $nome;
    }

    public function getNum_insignas() {
        return $this->num_insignas;
    }

    public function setNum_insignas($num_insignas) {
        $this->num_insignas = $num_insignas;
    }

    public function getQtd_pokemons_capturados() {
        return $this->qtd_pokemons_capturados;
    }

    public function setQtd_pokemons_capturados($qtd_pokemons_capturados) {
        $this->qtd_pokemons_capturados = $qtd_pokemons_capturados;
    }

    public function getQtd_pokemons_vistos() {
        return $this->qtd_pokemons_vistos;
    }

    public function setQtd_pokemons_vistos($qtd_pokemons_vistos) {
        $this->qtd_pokemons_vistos = $qtd_pokemons_vistos;
    }

    public function getSexo() {
        return $this->sexo;
    }

    public function setSexo($sexo) {
        $this->sexo = $sexo;
    }

    public function getLogin() {
        return $this->login;
    }

    public function setLogin($login) {
        $this->login = $login;
    }

    

    
}

?>