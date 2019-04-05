<?php include $_SERVER['DOCUMENT_ROOT'].'/trab_ihc/view/header.php'; ?>

<h1>Inserir um animal</h1>

<form action="?action=insereAnimalBD" method="post" enctype="multipart/form-data" runat="server">
    <div class="mdl-grid mdl-shadow--2dp">
        <div class="mdl-grid mdl-cell--6-col">
            <div class="mdl-cell mdl-cell--6-col">
                <h6>Sexo: </h6>
            </div>
            <div class="v-align mdl-grid mdl-cell mdl-cell--6-col">
                <div class="mdl-cell mdl-cell--6-col">
                    <label class="mdl-radio mdl-js-radio mdl-js-ripple-effect" for="option">
                        <input type="radio" id="option" name="Gênero" class="mdl-radio__button" >
                        <span class="mdl-radio__label">Masculino</span>
                    </label>
                </div>
                <div class="mdl-cell mdl-cell--6-col">
                    <label class="mdl-radio mdl-js-radio mdl-js-ripple-effect" for="option2">
                        <input type="radio" id="option2" name="Gênero" class="mdl-radio__button" >
                        <span class="mdl-radio__label">Feminino</span>
                    </label>
                </div>
            </div>
            <div class="mdl-cell mdl-cell--6-col">
                <h6>Espécie: </h6>
            </div>
            <div class="mdl-cell mdl-cell--6-col">
                <div class="mdl-textfield mdl-js-textfield">
                    <input class="mdl-textfield__input" type="text" id="sample1">
                    <label class="mdl-textfield__label" for="sample1">Espécie</label>
                </div>
            </div>
            <div class="mdl-cell mdl-cell--6-col">
                <h6>Raça: </h6>
            </div>
            <div class="mdl-cell mdl-cell--6-col">
                <div class="mdl-textfield mdl-js-textfield">
                    <input class="mdl-textfield__input" type="text" id="sample1">
                    <label class="mdl-textfield__label" for="sample1">Raça</label>
                </div>
            </div>
            <div class="mdl-cell mdl-cell--6-col">
                <h6>Nome: </h6>
            </div>
            <div class="mdl-cell mdl-cell--6-col">
                <div class="mdl-textfield mdl-js-textfield">
                    <input class="mdl-textfield__input" type="text" id="sample1">
                    <label class="mdl-textfield__label" for="sample1">Nome (caso haja)</label>
                </div>
            </div>
            <div class="mdl-cell mdl-cell--6-col">
                <h6>Idade: </h6>
            </div>
            <div class="mdl-cell mdl-cell--6-col">
                <div class="mdl-textfield mdl-js-textfield">
                    <input class="mdl-textfield__input" type="text" id="sample1">
                    <label class="mdl-textfield__label" for="sample1">Idade (10, 5...)</label>
                </div>
            </div>
            <div class="mdl-cell mdl-cell--6-col">
                <h6>Cor: </h6>
            </div>
            <div class="mdl-cell mdl-cell--6-col">
                <div class="mdl-textfield mdl-js-textfield">
                    <input class="mdl-textfield__input" type="text" id="sample1">
                    <label class="mdl-textfield__label" for="sample1">Cor (marfim, preto...)</label>
                </div>
            </div>
            <div class="mdl-cell mdl-cell--6-col">
                <h6>Natureza: </h6>
            </div>
            <div class="mdl-cell mdl-cell--6-col">
                <div class="mdl-textfield mdl-js-textfield">
                    <input class="mdl-textfield__input" type="text" id="sample1">
                    <label class="mdl-textfield__label" for="sample1">Natureza (dócil, enérgico...)</label>
                </div>
            </div>
        </div>
        <div class="mdl-grid mdl-cell--6-col">
            <div class="mdl-cell mdl-cell--6-col">
                <h6>Vacinas: </h6>
            </div>
            <div class="mdl-cell mdl-cell--6-col">
                <div class="mdl-textfield mdl-js-textfield">
                    <input class="mdl-textfield__input" type="text" id="sample1">
                    <label class="mdl-textfield__label" for="sample1">Lista de vacinas</label>
                </div>
            </div>    
            <div class="mdl-cell mdl-cell--6-col">
                <h6>Alimentação: </h6>
            </div>
            <div class="mdl-cell mdl-cell--6-col">
                <div class="mdl-textfield mdl-js-textfield">
                    <input class="mdl-textfield__input" type="text" id="sample1">
                    <label class="mdl-textfield__label" for="sample1">Comentários de alimentos</label>
                </div>
            </div>
            <div class="mdl-cell mdl-cell--6-col">
                <h6>Observações: </h6>
            </div>
            <div class="mdl-cell mdl-cell--6-col">
                <div class="mdl-textfield mdl-js-textfield">
                    <input class="mdl-textfield__input" type="text" id="sample1">
                    <label class="mdl-textfield__label" for="sample1">Comentários gerais</label>
                </div>
            </div>
            <div class="mdl-cell mdl-cell--6-col">
                <h6>Status: </h6>
            </div>
            <div class="v-align mdl-grid mdl-cell mdl-cell--6-col">
                <div class="mdl-cell mdl-cell--6-col">
                    <label class="mdl-radio mdl-js-radio mdl-js-ripple-effect" for="option3">
                        <input type="radio" id="option3" name="Status" class="mdl-radio__button" >
                        <span class="mdl-radio__label">Adotado</span>
                    </label>
                </div>
                <div class="mdl-cell mdl-cell--6-col">
                    <label class="mdl-radio mdl-js-radio mdl-js-ripple-effect" for="option4">
                        <input type="radio" id="option4" name="Status" class="mdl-radio__button" >
                        <span class="mdl-radio__label">Para adoção</span>
                    </label>
                </div>
            </div>
            <div class="mdl-cell mdl-cell--6-col">
                <h6>Imagem: </h6>
            </div>
            <div class="mdl-cell mdl-cell--6-col">
                <input type='file' id="imgInp" />
                <img id="blah" src="#"/>
                <!--<div class="mdl-textfield mdl-js-textfield">-->
                <!--    <input class="mdl-textfield__input" type="text" id="sample1">-->
                <!--    <label class="mdl-textfield__label" for="sample1">TODO</label>-->
                <!--</div>-->
            </div>
            <div class="relative mdl-cell mdl-cell--12-col">
                <div class="absolute bottom-right-align">
                    <button class="mdl-button mdl-js-button mdl-js-ripple-effect" type="submit">
                        Inserir
                    </button>
                </div>
            </div>
        </div>
    </div>
</form>

<?php include $_SERVER['DOCUMENT_ROOT'].'/trab_ihc/view/footer.php'; ?>
