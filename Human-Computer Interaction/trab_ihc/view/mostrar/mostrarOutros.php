<?php include $_SERVER['DOCUMENT_ROOT'].'/trab_ihc/view/header.php'; ?>

<br>
<div class="mdl-grid">
    <h1>Resultados da busca</h1>
        <form class="margin v-align float-right" action="index.php" method="post">
            <dialog></dialog>
            <button id="demo-menu-lower-right" class="mdl-button mdl-js-button mdl-button--icon" type="button">
              <i class="material-icons">search</i>
            </button>
            <span class="mdl-tooltip mdl-tooltip--large" for="demo-menu-lower-right">
                Filtros de busca
            </span>
            <ul class="mdl-menu mdl-js-menu mdl-js-ripple-effect" for="demo-menu-lower-right">
                <table class="mdl-data-table mdl-js-data-table mdl-data-table--selectable mdl-shadow--2dp">
                  <thead>
                    <tr>
                      <th class="mdl-data-table__cell--non-numeric">Filtro</th>
                    </tr>
                  </thead>
                  <tbody>
                    <tr>
                      <td class="mdl-data-table__cell--non-numeric">Ordem Alfabética</td>
                    </tr>
                    <tr>
                      <td class="mdl-data-table__cell--non-numeric">Espécie</td>
                    </tr>
                    <tr>
                      <td class="mdl-data-table__cell--non-numeric">Adotado</td>
                    </tr>
                  </tbody>
                </table>
            </ul>
            <!--<ul class="mdl-menu mdl-js-menu mdl-js-ripple-effect" for="demo-menu-lower-right">
              <li class="mdl-menu__item">
                  <button class="mdl-radio mdl-js-radio" type="radio">
                      Ordem alfabética
                  </button>
              </li>
              <li disabled class="mdl-menu__item">Disabled Action</li>
            </ul>-->
        </form>
</div>
<!-- OBS: todos os divs aqui gerados são estáticos, devendo ser substituídos por buscas em banco de dados na versão final -->
<div class="margin mdl-grid mdl-shadow--2dp mdl-color--cyan">
    <img class="threehundredpx" src="misc/images/torkoal.png" alt="Imagem do animal"></img>
    <h6 class="margin v-align">
        Espécie: Tartaruga
        <br>
        Nome: Sopa
        <br>
        Status: Para adoção
    </h6>
    <h6 class="margin v-align">
        Raça: Não informado
        <br>
        Natureza: Amigável
        <br>
        Vacinas: Essa aqui o Jainor sabe
    </h6>
    <div class="relative mdl-cell">
        <div class="absolute bottom-right-align">
            <a class="mdl-button mdl-js-button mdl-js-ripple-effect" href="?action=mostrarAnimal">
                Ver mais
            </a>
        </div>
    </div>
</div>

<?php include $_SERVER['DOCUMENT_ROOT'].'/trab_ihc/view/footer.php'; ?>