<?php include $_SERVER['DOCUMENT_ROOT'].'/trab_ihc/view/header.php'; ?>

<br>
<div class="mdl-grid">
    <h1>Animais cadastrados pelo usuário</h1>
</div>
<!-- OBS: todos os divs aqui gerados são estáticos, devendo ser substituídos por buscas em banco de dados na versão final -->
<div class="margin mdl-grid mdl-shadow--2dp mdl-color--light-green">
    <img src="misc/images/growlithe.png" alt="Imagem do animal"></img>
    <h6 class="margin v-align">
        Espécie: Cachorro
        <br>
        Nome: Labareda
        <br>
        Status: Para adoção
    </h6>
    <h6 class="margin v-align">
        Raça: Poodle
        <br>
        Natureza: Dócil
        <br>
        Vacinas: Essa aqui o Jainor sabe
    </h6>
    <div class="mdl-grid">
        <div class="mdl-cell mdl-cell--6-col">
            <div>
                <a class="div-center mdl-button mdl-js-button mdl-js-ripple-effect" href="?action=mostrarAnimal">
                    Ver mais
                </a>
            </div>
        </div>
        <div class="mdl-cell mdl-cell--4-col">
            <div class="mdl-grid">
                <div class="mdl-cell mdl-cell--12-col">
                    <a class="div-center2 mdl-button mdl-js-button mdl-js-ripple-effect" href="?action=mostrarAnimal">
                        Excluir
                    </a>    
                </div>
                <div class="mdl-cell mdl-cell--12-col">
                    <a class="mdl-button mdl-js-button mdl-js-ripple-effect" href="?action=mostrarAnimal">
                        Editar
                    </a>
                </div>
            </div>
        </div>
    </div>
</div>
<br>
<div class="margin mdl-grid mdl-shadow--2dp mdl-color--light-green">
    <img src="misc/images/arcanine.png" alt="Imagem do animal"></img>
    <h6 class="margin v-align">
        Espécie: Cachorro
        <br>
        Nome: Leônidas
        <br>
        Status: Para adoção
    </h6>
    <h6 class="margin v-align">
        Raça: Labrador
        <br>
        Natureza: Energético
        <br>
        Vacinas: Essa aqui o Jainor sabe
    </h6>
    <div class="mdl-grid">
        <div class="mdl-cell mdl-cell--6-col">
            <div>
                <a class="div-center mdl-button mdl-js-button mdl-js-ripple-effect" href="?action=mostrarAnimal">
                    Ver mais
                </a>
            </div>
        </div>
        <div class="mdl-cell mdl-cell--4-col">
            <div class="mdl-grid">
                <div class="mdl-cell mdl-cell--12-col">
                    <a class="div-center2 mdl-button mdl-js-button mdl-js-ripple-effect" href="?action=mostrarAnimal">
                        Excluir
                    </a>    
                </div>
                <div class="mdl-cell mdl-cell--12-col">
                    <a class="mdl-button mdl-js-button mdl-js-ripple-effect" href="?action=mostrarAnimal">
                        Editar
                    </a>
                </div>
            </div>
        </div>
    </div>
</div>

<?php include $_SERVER['DOCUMENT_ROOT'].'/trab_ihc/view/footer.php'; ?>