<?php
header("Content-Type: text/html; charset=utf-8", true);
?>

<!DOCTYPE html>
<html>
	<head>

	    <title>Repósitorio de questões de computação</title>
	    <meta name="viewport" content="width=device-width, initial-scale=1.0">
	    <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
	    <!-- Bootstrap -->
	    <link href="misc/css/bootstrap.min.css" rel="stylesheet" media="screen">
	    <link href="misc/css/style.css" rel="stylesheet" media="screen" type="text/css">
	    <!-- jQuery (necessary for Bootstrap's JavaScript plugins) -->
	    <script src="misc/js/jquery.js"></script>
	    <script src="misc/js/jquery-1.10.2.min.js"></script>
	    <!-- Include all compiled plugins (below), or include individual files as needed -->
	    <script src="misc/js/bootstrap.min.js"></script>

	</head>
	<body class="index">

	    <div class="container">
	        <header>
	        <a href="index.php"><img src="misc/imagens/computacao.png"  height="200" width="190" alt="Logo do repositório"/></a>
	        <a href="index.php"><img src="misc/imagens/repositorio.png" alt="Repositório institucional"/></a>
	        </header>
	        <nav class="navbar navbar-default" role="navigation">
	            <!-- Brand and toggle get grouped for better mobile display -->
	            <div class="navbar-header">
	                <button type="button" class="navbar-toggle" data-toggle="collapse" data-target=".navbar-ex1-collapse">
	                    <span class="sr-only">Toggle navigation</span>
	                    <span class="icon-bar"></span>
	                    <span class="icon-bar"></span>
	                    <span class="icon-bar"></span>
	                </button>
	                <a class="navbar-brand" href="#"> Opções: </a>
	            </div>

	            <!-- Collect the nav links, forms, and other content for toggling -->
	            <div class="collapse navbar-collapse navbar-ex1-collapse">
	                <ul class="nav nav-pills nav-justified">
	                	<li><a href="?action=buscarQuestoes&busca=1" class="btn">Pesquisar questões</a></li>
	                	<?php
	                		if(isset($_SESSION['usuario']))
	                		{
	                			echo '<li><a href="?action=mostrarPainel" class="btn">Exibir Painel</a></li>';
	                			echo '<li><a href="?action=fazerLogoff" class="btn">Fazer logoff</a></li>';
	                		}
	                		else
	                		{
	                			echo '<li><a href="?action=login" class="btn">Fazer login</a></li>';
	                			echo '<li><a href="?action=cadastro" class="btn">Cadastrar-se</a></li>';
	                		}
	                	?>
	                </ul>
	            </div>
	        </nav>