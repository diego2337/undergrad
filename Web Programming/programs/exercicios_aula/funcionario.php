<?php

class Funcionario{
    private $nome;
    private $salario;
    
    function __construct($_nome, $_salario){
        $this->nome = $_nome;
        $this->setSalario($_salario);
    }
    
    function getNome(){
        return $this->nome;
    }
    
    function setNome($_nome){
        $this->nome = $_nome;
    }
    
    function getSalario(){
        return $this->salario;
    }
    
    function setSalario($_salario){
        if($_salario < 0){
            $this->salario = 0;
        }else{
            $this->salario = $_salario;
        }
    }
    
    function __toString() {
        return 'Nome: '. $this->nome .' Salário: '. $this->salario;
    }
    
}

?>
