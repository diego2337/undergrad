<?php include('view/header.php'); ?>
<div class="form2">
    <div class="lerge-form">
        <form class="form-horizontal" action="?action=insertAtaqueDB" method="POST">
            <legend>Cadastrar novo ataque: </legend>
            <label>Nome:  </label>      
            <input  name="nome" class="form-control" type="text" id="nome"  >

            <label>Tipo:</label>
            <select class="form-control" id="tipo" name="tipo">
                <option value="Agua" >Água</option>
                <option value="Fogo">Fogo</option>
                <option value="Planta">Planta</option>
                <option value="Psiquico">Psiquico</option>
                <option value="Gelo">Gelo</option>
                <option value="Dragão">Dragão</option>
                <option value="Inseto">Inseto</option>
                <option value="Normal">Normal</option>
                <option value="Elétrico">Elétrico</option>
                <option value="Lutador">Lutador</option>
                <option value="Fantasma">Fantasma</option>
                <option value="Venenoso">Venenoso</option>
                <option value="Pedra">Pedra</option>
                <option value="Terrestre">Terrestre</option>
                
            </select>
            <label >Poder:  </label>

            <input class="form-control" type="text" placeholder="" name="poder">
            <label >Precisão:  </label>

            <input class="form-control" type="text" placeholder="" name="precisao">


            <label >Quantidade (PP):  </label>

            <input class="form-control" type="text" placeholder="" name="quantidade">


            <label>Efeito:</label>
            <textarea class="form-control" rows="3" name="efeito"></textarea>

            <label> Uso fora da batalha?</label>
            <select class="form-control" name="uso_fora_batalha">
                <option value="Nao" >Não</option>
                <option value="Sim">Sim</option>
            </select>



            <label> <button type="submit" class="btn">Enviar!</button> </label>
        </form>
    </div>
</div>

<?php include 'view/footer.php'; ?>
