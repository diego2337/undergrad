<?php

class TreinadorPokemon
{
  private $id_treinador;
  private $id_pokemon;
  private $num_pokemon;
  private $apelido;
  private $nome;
  private $type;
  private $region;
  private $level;
  private $description;
  private $imagem;
  public function getId_treinador() {
      return $this->id_treinador;
  }

  public function setId_treinador($id_treinador) {
      $this->id_treinador = $id_treinador;
  }

  public function getId_pokemon() {
      return $this->id_pokemon;
  }

  public function setId_pokemon($id_pokemon) {
      $this->id_pokemon = $id_pokemon;
  }

  public function getNum_pokemon() {
      return $this->num_pokemon;
  }

  public function setNum_pokemon($num_pokemon) {
      $this->num_pokemon = $num_pokemon;
  }

  public function getApelido() {
      return $this->apelido;
  }

  public function setApelido($apelido) {
      $this->apelido = $apelido;
  }

  public function getNome() {
      return $this->nome;
  }

  public function setNome($nome) {
      $this->nome = $nome;
  }

  public function getType() {
      return $this->type;
  }

  public function setType($type) {
      $this->type = $type;
  }

  public function getRegion() {
      return $this->region;
  }

  public function setRegion($region) {
      $this->region = $region;
  }

  public function getLevel() {
      return $this->level;
  }

  public function setLevel($level) {
      $this->level = $level;
  }

  public function getDescription() {
      return $this->description;
  }

  public function setDescription($description) {
      $this->description = $description;
  }

  public function getImagem() {
      return $this->imagem;
  }

  public function setImagem($imagem) {
      $this->imagem = $imagem;
  }

    
  function __construct() {
    }

  
}

?>
