<?php

class Pokemart {
    
    /*Chave nome */
    private $local;
    private $qtd_itens;
    
    function __construct() {
        
    }
    
    public function getLocal() {
        return $this->local;
    }

    public function setLocal($local) {
        $this->local = $local;
    }
    public function getQtd_itens() {
        return $this->qtd_itens;
    }

    public function setQtd_itens($qtd_itens) {
        $this->qtd_itens = $qtd_itens;
    }



};

?>