<?php

class Ataque {
    
    /*Chave nome */
    private $nome;
    private $tipo;
    private $quantidade;
    private $poder;
    private $precisao;
    private $efeito;
    private $uso_fora_batalha;
    
    function __construct() {
        
    }
    
    public function getNome() {
        return $this->nome;
    }

    public function setNome($nome) {
        $this->nome = $nome;
    }

    public function getTipo() {
        return $this->tipo;
    }

    public function setTipo($tipo) {
        $this->tipo = $tipo;
    }

    public function getQuantidade() {
        return $this->quantidade;
    }

    public function setQuantidade($quantidade) {
        $this->quantidade = $quantidade;
    }

    public function getPoder() {
        return $this->poder;
    }

    public function setPoder($poder) {
        $this->poder = $poder;
    }

    public function getPrecisao() {
        return $this->precisao;
    }

    public function setPrecisao($precisao) {
        $this->precisao = $precisao;
    }

    public function getEfeito() {
        return $this->efeito;
    }

    public function setEfeito($efeito) {
        $this->efeito = $efeito;
    }

    public function getUso_fora_batalha() {
        return $this->uso_fora_batalha;
    }

    public function setUso_fora_batalha($uso_fora_batalha) {
        $this->uso_fora_batalha = $uso_fora_batalha;
    }

}


?>
