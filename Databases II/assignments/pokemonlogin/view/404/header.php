<head>
    <title>Pokedex data manager</title>
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta charset="utf-8">
    <!-- Bootstrap -->
    <link href="web/css/bootstrap.min.css" rel="stylesheet" media="screen">
    <link href="web/css/style.css" rel="stylesheet" media="screen" type="text/css">
    <!-- jQuery (necessary for Bootstrap's JavaScript plugins) -->
    <script src="web/js/jquery.js"></script>
    <script src="web/js/jquery-1.10.2.min.js"></script>
    <!-- Include all compiled plugins (below), or include individual files as needed -->
    <script src="web/js/bootstrap.min.js"></script>

</head>
<body>

    <div class="container">
        <header>
        <a href="index.php"><img src="web/img/pokemon_logo.png" alt="Logo do site pokemon"  /></a>
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
                <a class="navbar-brand" href="#">Eu escolho: </a>
            </div>

            <!-- Collect the nav links, forms, and other content for toggling -->
            <div class="collapse navbar-collapse navbar-ex1-collapse">
                <ul class="nav navbar-nav">

                    <li class="dropdown">
                        <a href="#" class="dropdown-toggle" data-toggle="dropdown">Pokemon <b class="caret"></b></a>
                        <ul class="dropdown-menu">
                            <li><a href="?action=buscaPokemon">Buscar</a></li>
                            <li><a href="?action=insertPokemon">Inserir</a></li>
                            <li><a href="?action=listarPokemon">Listar</a></li>

                        </ul>
                    </li>

                    <li class="dropdown">
                        <a href="#" class="dropdown-toggle" data-toggle="dropdown">Treinador <b class="caret"></b></a>
                        <ul class="dropdown-menu">
                            <li><a href="?action=buscaTreinador">Buscar</a></li>
                            <li><a href="?action=insertTreinador">Inserir</a></li>
                            <li><a href="?action=listarTreinador">Listar</a></li>

                        </ul>
                    </li>

                    <li class="dropdown">
                        <a href="#" class="dropdown-toggle" data-toggle="dropdown">Ataque <b class="caret"></b></a>
                        <ul class="dropdown-menu">
                            <li><a href="?action=insertAtaque">Inserir</a></li>
                            <li><a href="view/insere/inserir_ataque.php">Buscar</a></li>
                            <li><a href="?action=listarAtaque">Listar</a></li>

                        </ul>
                    </li>
                    
                    <li class="dropdown">
                        <a href="#" class="dropdown-toggle" data-toggle="dropdown">Itens <b class="caret"></b></a>
                        <ul class="dropdown-menu">
                            <li><a href="?action=insertItem">Inserir</a></li>
                            <li><a href="?action=insertItem">Buscar</a></li>
                            <li><a href="?action=listarItem">Listar</a></li>

                        </ul>
                    </li>
                    
                    <li class="dropdown">
                        <a href="#" class="dropdown-toggle" data-toggle="dropdown">Pokecenter <b class="caret"></b></a>
                        <ul class="dropdown-menu">
                            <li><a href="view/busca/buscar_pokecenter.php">Buscar</a></li>
                            <li><a href="view/insere/inserir_pokecenter.php">Inserir</a></li>
                            <li><a href="http://localhost/bd/remover_pokecenter.php">Remover</a></li>
                            <li><a href="#">Alterar</a></li>

                        </ul>
                    </li>

                    <li class="dropdown">
                        <a href="#" class="dropdown-toggle" data-toggle="dropdown">Pokemart <b class="caret"></b></a>
                        <ul class="dropdown-menu">
                            <li><a href="view/busca/buscar_pokemart.php">Buscar</a></li>
                            <li><a href="#view/insere/inserir_pokemart.php">Inserir</a></li>
                            <li><a href="http://localhost/bd/remove/remover_pokemart.php">Remover</a></li>
                            <li><a href="#">Alterar</a></li>

                        </ul>
                    </li>

                </ul>

            </div><!-- /.navbar-collapse -->
        </nav>