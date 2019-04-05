<?php

class Equipamento {

    var $ligado;

    function __construct() {
        $this->ligado = false;
    }

    public function liga() {
        $this->ligado = true;
    }

    public function desliga() {
        $this->ligado = false;
    }

    public function __toString() {
        if ($this->ligado) {
            return 'Este equipamento esta ligado ';
        } else {
            return 'Este equipamento esta desligado ';
        }
    }

}

class EquipamentoSonoro extends Equipamento {

    var $volume;
    var $stereo;

    function __construct() {
        parent::__construct();
        $this->volume = 0;
        $this->stereo = false;
    }

    public function getVolume() {
        return $this->volume;
    }

    public function setVolume($vol) {
        if ($vol > 10) {
            $this->volume = 10;
        } else if ($vol < 0) {
            $this->volume = 0;
        } else {
            $this->volume = $vol;
        }
    }

    public function mono() {
        $this->stereo = false;
    }

    public function stereo() {
        $this->stereo = true;
    }

    public function liga() {
        parent::liga();
        $this->setVolume(5);
    }
    
    public function __toString() {
        $ret = parent::__toString();
        return $ret. ' e o volume está em '. $this->getVolume(). ' decibéis';
    }

}

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

$equip1 = new Equipamento();
$equip1->liga();
$equip2 = new Equipamento();

$equip3 = new EquipamentoSonoro();
$equip3->liga();
$equip3->setVolume(12);
$equip4 = new EquipamentoSonoro();

$array = array($equip1, $equip2, $equip3, $equip4);

foreach ($array as $value){
    echo $value. '<br/>';
}