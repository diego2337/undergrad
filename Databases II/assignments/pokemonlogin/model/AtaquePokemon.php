<?php
class AtaquePokemon
{
    
    private $nome_ataque;
    private $id_pokemon;
    private $tipo;
    
    public function getNome_ataque() {
        return $this->nome_ataque;
    }

    public function setNome_ataque($nome_ataque) {
        $this->nome_ataque = $nome_ataque;
    }

    public function getId_pokemon() {
        return $this->id_pokemon;
    }

    public function setId_pokemon($id_pokemon) {
        $this->id_pokemon = $id_pokemon;
    }

    public function getTipo() {
        return $this->tipo;
    }

    public function setTipo($tipo) {
        $this->tipo = $tipo;
    }


    
}
?>
