<?php
header("Content-Type: text/html; charset=utf-8", true);
?>

<!DOCTYPE html>
<html>
	<head>

	    <title>H2S3</title>
	    <meta name="viewport" content="width=device-width, initial-scale=1.0">
	    <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
	    <!-- Bootstrap -->
	    <link href="web/css/bootstrap.min.css" rel="stylesheet" media="screen">
	    <link href="web/css/style.css" rel="stylesheet" media="screen" type="text/css">
	    <!-- jQuery (necessary for Bootstrap's JavaScript plugins) -->
	    <script src="web/js/jquery.js"></script>
	    <script src="web/js/jquery-1.10.2.min.js"></script>
	    <!-- Include all compiled plugins (below), or include individual files as needed -->
	    <script src="web/js/bootstrap.min.js"></script>
          

	</head>
	<body class="index">

	    <div class="container">
	        <header>
	        <a href="index.php"><img src="web/img/data_vault2.png"  height="100" width="90" alt="Logo da aplicação"  /></a>
	        <a href="http://aws.amazon.com/pt/"><img src="web/img/aws.png" height="130" width="430" alt="Logo da AWS"  /></a>
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
	                	<!-- <li><a href="?action=carregarArquivo" class="btn">Carregar arquivo</a></li> -->
	                	<?php
	                		if(isset($_SESSION['superuser']))
	                		{
	                			echo '<li><a href="?action=mostrarSuperPainel" class="btn">Exibir Painel de Super usuário</a></li>';	
	                		}
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
	                    <!-- <li class="dropdown">
	                        <a href="#" class="dropdown-toggle" data-toggle="dropdown">Pokemon <b class="caret"></b></a>
	                        <ul class="dropdown-menu">
	                            <li><a href="?action=buscaPokemon">Buscar</a></li>
	                            <li><a href="?action=insertPokemon">Inserir</a></li>
	                            <li><a href="?action=listarPokemon">Listar</a></li>

	                        </ul>
	                    </li> 
	                    -->
	                </ul>
	            </div><!-- /.navbar-collapse -->
	        </nav>