<!DOCTYPE html>
<!--
  Material Design Lite
  Copyright 2015 Google Inc. All rights reserved.

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

      https://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License
-->


<?php include $_SERVER['DOCUMENT_ROOT'].'/trab_ihc/view/header.php'; ?>
  <main>
    <div class="mdl-grid">
      <div class="margin demo-card-wide mdl-card mdl-shadow--2dp ">
        <div class="mdl-card__dog mdl-card__title">
          <h2 class="mdl-card__title-text">Bem-Vindo!</h2>
        </div>
        <div class="mdl-card__supporting-text">
          Bem-vindo ao Animalia, adote um animal ou deixe um para adoção!
        </div>
      </div>
      <div class="margin demo-card-wide mdl-card mdl-shadow--2dp">
        <div class="mdl-card__pets mdl-card__title">
          <h2 class="mdl-card__title-text">Animais</h2>
        </div>
        <div class="mdl-card__supporting-text">
          Caẽs, gatos, aves, tartarugas... Procure agora mesmo animais que precisam de amparo!
        </div>
        <div class="mdl-card__actions mdl-card--border">
          <a href="?action=mostrar" class="mdl-button mdl-button--colored mdl-js-button mdl-js-ripple-effect">
            Procurar
          </a>
        </div>
      </div>
      <div class="margin demo-card-wide mdl-card mdl-shadow--2dp">
        <div class="mdl-card__people mdl-card__title">
          <h2 class="mdl-card__title-text">Doadores</h2>
        </div>
        <div class="mdl-card__supporting-text">
          Conheça mais os responsáveis por colaborar e manter o Animalia ativo!
        </div>
        <div class="mdl-card__actions mdl-card--border">
          <a class="mdl-button mdl-button--colored mdl-js-button mdl-js-ripple-effect">
            Veja mais
          </a>
        </div>
      </div>
    </div>
  </main>  
<?php include $_SERVER['DOCUMENT_ROOT'].'/trab_ihc/view/footer.php'; ?>
