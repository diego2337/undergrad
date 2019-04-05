

<?php

require 'funcionario.php';

$_nome = $_POST['nome'];
$_salario = $_POST['salario'];

$funcionario = new Funcionario($_nome, $_salario);

require 'mostra.php';
?>


