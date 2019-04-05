<?php 
    header("Content-Type: text/html; charset=utf-8", true);
?>

<!DOCTYPE html>
<html>
    <head>
      
    <meta charset="utf-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="description" content="A front-end template that helps you build fast, modern mobile web apps.">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    
    <!-- Add to homescreen for Chrome on Android -->
    <meta name="mobile-web-app-capable" content="yes">
    
    <!-- <link rel="icon" sizes="192x192" href="/misc/images/android-desktop.png"> -->

    <!-- Add to homescreen for Safari on iOS -->
    <meta name="apple-mobile-web-app-capable" content="yes">
    <meta name="apple-mobile-web-app-status-bar-style" content="black">
    <meta name="apple-mobile-web-app-title" content="Material Design Lite">
    
    <!-- <link rel="apple-touch-icon-precomposed" href="/misc/images/ios-desktop.png"> -->

    <!-- Tile icon for Win8 (144x144 + tile color) -->
    <meta name="msapplication-TileImage" content="/misc/images/touch/ms-touch-icon-144x144-precomposed.png">
    <meta name="msapplication-TileColor" content="#3372DF">
    
    <title>Animalia</title>

    <!-- <link rel="shortcut icon" href="/misc/images/animalia.png"> -->

    <!-- SEO: If your mobile URL is different from the desktop URL, add a canonical link to the desktop page 
    https://developers.google.com/webmasters/smartphone-sites/feature-phones -->
    <!--
    <link rel="canonical" href="http://www.example.com/">
    -->

    <link href="https://fonts.googleapis.com/css?family=Roboto:regular,bold,italic,thin,light,bolditalic,black,medium&amp;lang=en" rel="stylesheet">
    <link href="https://fonts.googleapis.com/icon?family=Material+Icons" rel="stylesheet">
    <link rel="stylesheet" href="misc/css/styles.css" type="text/css">
	<link rel="stylesheet" href="misc/css/material.min.css">
	<script src="misc/css/material.min.js"></script>
<link rel="stylesheet" href="misc/css/material.css">
<script src="misc/css/material.js"></script>
    <script src="misc/css/utils.js"></script>

    <link rel="stylesheet" href="https://storage.googleapis.com/code.getmdl.io/1.0.6/material.indigo-pink.min.css">
    	<script src="https://storage.googleapis.com/code.getmdl.io/1.0.6/material.min.js"></script>
    <link rel="stylesheet" href="https://fonts.googleapis.com/icon?family=Material+Icons">
  </head>
  <!-- div que contém todos os elementos, centralizando a página -->
  <div class="center-page">
    <body class="index mdl-layout mdl-js-layout">
      <header class="align-center mdl-layout__header mdl-layout__header--transparent mdl-grid">
        <div class="margin">
          <a href="index.php"><img src="misc/images/animalia.png" height="90" width="110" alt="Logo do Animalia"/></a>
        </div>
        <nav class="mdl-navigation">
          <div>
            <a class="mdl-navigation__link" href="?action=mostrarCaes">
              <button class="nav-center mdl-button mdl-js-button mdl-button--raised mdl-js-ripple-effect mdl-button--accent
                mdl-color--light-green">Cães</button>
            </a>
            <a class="mdl-navigation__link" href="?action=mostrarGatos">
              <button class="nav-center-continued mdl-button mdl-js-button mdl-button--raised mdl-js-ripple-effect mdl-button--accent
                mdl-color--purple">Gatos</button>
            </a>
            <a class="mdl-navigation__link" href="?action=mostrarAves">
              <button class="nav-center-continued mdl-button mdl-js-button mdl-button--raised mdl-js-ripple-effect mdl-button--accent
                mdl-color--red">Aves</button>
            </a>
            <a class="mdl-navigation__link" href="?action=mostrarOutros">
              <button class="nav-center-continued mdl-button mdl-js-button mdl-button--raised mdl-js-ripple-effect mdl-button--accent
                mdl-color--cyan">
                Outros
              </button>
            </a>
          </div>
        </nav>
        <!--
        <div class="mdl-textfield mdl-js-textfield mdl-textfield--expandable
                    mdl-textfield--floating-label mdl-textfield--align-right">
          <label class="mdl-button mdl-js-button mdl-button--icon"
                 for="fixed-header-drawer-exp">
            <i class="material-icons">search</i>
          </label>
          <div class="mdl-textfield__expandable-holder">
            <input class="mdl-textfield__input" type="text" name="sample"
                   id="fixed-header-drawer-exp">
          </div>
        </div>
        -->
        <form class="nav-center-search-bar" action="#">
          <div class="nav-center mdl-textfield mdl-js-textfield mdl-textfield--floating-label">
            <input class="mdl-textfield__input" type="text" id="procurar"/>
            <label class="mdl-textfield__label" for="procurar">Procurar...</label>
          </div>
        </form>
        <nav>
          <div class="mdl-grid">
            <?php
              if(isset($_SESSION['d_id']))
              {
                echo '<a class="mdl-cell mdl-cell--2-col mdl-navigation__link" href="#">
                        <img class="user-photo" src="misc/images/user2.jpg"/>
                      </a>
                      <a class="mdl-cell mdl-cell--4-col mdl-navigation__link" href="?action=animaisCadastrados">
                        <button class="mdl-button mdl-js-button mdl-js-ripple-effect mdl-color--grey">
                          Animais
                        </button>
                      </a>
                      <a class="mdl-cell mdl-cell--4-col mdl-navigation__link" href="?action=inserirAnimal">
                        <button class="mdl-button mdl-js-button mdl-js-ripple-effect mdl-color--grey">
                          Inserir
                        </button>
                      </a>
                      <a class="mdl-cell mdl-cell--12-col mdl-navigation__link" href="?action=index">
                        <button class="mdl-button mdl-js-button mdl-js-ripple-effect mdl-color--grey">
                          Logout
                        </button>
                      </a>';
              }
              else
              {
                echo '<a class="mdl-navigation__link" href="#">
                        <button class="nav-center mdl-button mdl-js-button mdl-js-ripple-effect mdl-color--grey">
                          Login
                        </button>
                      </a>
                      <a class="mdl-navigation__link" href="?action=cadastrar">
                        <button class="nav-center-spacing mdl-button mdl-js-button mdl-js-ripple-effect mdl-color--grey">
                          Cadastrar-se
                        </button>
                      </a>';
              }
            ?>
          </div>
        </nav>
      </header>
      <body>
