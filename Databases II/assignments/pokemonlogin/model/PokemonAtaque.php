<?php

   
class PokemonAtaque{
    private $ataque;
    private $level_aprendido;
    private $id_pokemon;
    
    
    function __construct() {
    }
    
    public function getAtaque() {
        return $this->ataque;
    }

    public function setAtaque($ataque) {
        $this->ataque = $ataque;
    }

    public function getLevel_aprendido() {
        return $this->level_aprendido;
    }

    public function setLevel_aprendido($level_aprendido) {
        $this->level_aprendido = $level_aprendido;
    }

    public function getId_pokemon() {
        return $this->id_pokemon;
    }

    public function setId_pokemon($id_pokemon) {
        $this->id_pokemon = $id_pokemon;
    }

   
}

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
?>
