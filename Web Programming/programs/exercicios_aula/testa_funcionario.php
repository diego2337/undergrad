<?php

require 'funcionario.php';

$func1 = new Funcionario('Wellynnson', 15000);

$func2 = new Funcionario('Diego', 10000);

$func3 = new Funcionario('Daniel', -500);

$lista_funcionarios = array($func1, $func2, $func3);

foreach($lista_funcionarios as $value){
    echo $value. '<br/>';
}