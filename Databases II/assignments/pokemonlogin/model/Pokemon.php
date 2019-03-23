<?php

class Pokemon {
    
    private $number;
    private $name;
    private $type;
    private $region;
    private $level;
    private $description;
     private $imagem;
    function __construct() {
    }

    public function getNumber() {
        return $this->number;
    }

    public function setNumber($number) {
        $this->number = $number;
    }

    public function getName() {
        return $this->name;
    }

    public function setName($name) {
        $this->name = $name;
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
     
    public function setImagem($imagem)
    {
      $this->imagem = $imagem;
    }
    
    public function getImagem()
    {
      return $this->imagem;
    }
    
}

?>
