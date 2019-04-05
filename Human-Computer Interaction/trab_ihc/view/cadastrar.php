<?php include $_SERVER['DOCUMENT_ROOT'].'/trab_ihc/view/header.php'; ?>

<h1>Cadastrar</h1>

<form action="?action=cadastroBD" method="post" enctype="multipart/form-data">
    <div class="mdl-grid">
        <div class="mdl-grid mdl-cell mdl-shadow--2dp mdl-cell--12-col">
            <!-- Informações pessoais -->
            <div class="mdl-grid mdl-cell mdl-shadow--2dp mdl-cell--6-col">
                <div class="mdl-cell mdl-cell--6-col">
                    <h6>Nome ou Razão Social:</h6>
                </div>
                <div class="mdl-cell mdl-cell--6-col">
                    <div class="mdl-textfield mdl-js-textfield">
                        <input class="mdl-textfield__input" type="text" id="sample1">
                        <label class="mdl-textfield__label" for="sample1">Nome Completo</label>
                    </div>
                </div>
                <div class="mdl-cell mdl-cell--6-col">
                    <h6>CPF/CNPJ:</h6>
                </div>
                <div class="mdl-cell mdl-cell--6-col">
                    <div class="mdl-textfield mdl-js-textfield">
                        <input class="mdl-textfield__input" type="text" id="sample1">
                        <label class="mdl-textfield__label" for="sample1">000.000.000-00/XX.XXX.XXX/YYYY-ZZ</label>
                    </div>
                </div>
                <div class="mdl-cell mdl-cell--6-col">
                    <h6>Telefone para contato:</h6>
                </div>
                <div class="mdl-cell mdl-cell--6-col">
                    <div class="mdl-textfield mdl-js-textfield">
                        <input class="mdl-textfield__input" type="text" id="sample1">
                        <label class="mdl-textfield__label" for="sample1">(DDD)0000-0000</label>
                    </div>
                </div>
            </div>
            <!-- Imagem -->
            <div class="mdl-grid mdl-cell mdl-shadow--2dp mdl-cell--6-col">
                <div class="mdl-cell mdl-cell--6-col">
                    <h6>Imagem:</h6>
                </div>
                <div class="mdl-cell mdl-cell--6-col">
                    <div class="mdl-textfield mdl-js-textfield">
                        <input type='file' id="imgInp" />
                        <img id="blah" src="#"/>
                    </div>
                </div>
            </div>
            <!-- E-mail e senhas -->
            <div class="mdl-grid mdl-cell mdl-shadow--2dp mdl-cell--6-col">
                <div class="mdl-cell mdl-cell--6-col">
                    <h6>E-mail:</h6>
                </div>
                <div class="mdl-cell mdl-cell--6-col">
                    <div class="mdl-textfield mdl-js-textfield">
                        <input class="mdl-textfield__input" type="text" id="sample1">
                        <label class="mdl-textfield__label" for="sample1">login@dominio</label>
                    </div>
                </div>
                <div class="mdl-cell mdl-cell--6-col">
                    <h6>Senha:</h6>
                </div>
                <div class="mdl-cell mdl-cell--6-col">
                    <div class="mdl-textfield mdl-js-textfield">
                        <input class="mdl-textfield__input" type="text" id="sample1">
                        <label class="mdl-textfield__label" for="sample1">...</label>
                    </div>
                </div>
                <div class="mdl-cell mdl-cell--6-col">
                    <h6>Confirmar senha:</h6>
                </div>
                <div class="mdl-cell mdl-cell--6-col">
                    <div class="mdl-textfield mdl-js-textfield">
                        <input class="mdl-textfield__input" type="text" id="sample1">
                        <label class="mdl-textfield__label" for="sample1">...</label>
                    </div>
                </div>
            </div>
            <!-- Confirmação de cadastro -->
            <div class="mdl-grid mdl-cell mdl-cell--6-col">
                <div class="relative mdl-cell mdl-cell--12-col">
                    <div class="absolute bottom-right-align">
                        <button class="mdl-button mdl-js-button mdl-js-ripple-effect" type="submit">
                            Cadastrar
                        </button>
                    </div>
                </div>
            </div>
        </div>
    </div>
</form>
<?php include $_SERVER['DOCUMENT_ROOT'].'/trab_ihc/view/footer.php'; ?>
