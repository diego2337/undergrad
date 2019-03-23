<!DOCTYPE html>
<html>

    <?php include('view/header.php'); ?>

    <div class="form2">
        <legend>Capturar novo Pokemon: </legend>
        <div class="lerge-form">
            
        <form class="form-horizontal" action="?action=capturaPokemonDB" method="post">
            <?php foreach ($pokemons as $poke):?>
            <label class="control-label">Numero: </label>
            <input class="form-control" name="num" type="text" readonly="readonly" value="<?php echo $poke->getNumber();?>">
            
            <label class="control-label">Nome:</label>
                <input name="nome" class="form-control" type="text" readonly="readonly" value="<?php echo $poke->getName();?>">
                
            <label class="control-label">Tipo:</label>
                <input name="tipo" class="form-control" type="text" readonly="readonly" value="<?php echo $poke->getType();?>">
                
            <label class="control-label">Região:</label>
		<input name="regiao" class="form-control" type="text" readonly="readonly" value="<?php echo $poke->getRegion();?>">

	    <label class="control-label">Apelido:</label>
                <input name="apelido" class="form-control" type="text" >
            
            <label class="control-label">Nível</label>
            <input name="nivel" class="form-control span2" type="number" value="1">
            
            
           <?php endforeach;
            ?>
            <button type="submit" class="btn btn-primary btn-lg">Enviar!</button>
        </form>
        </div>
    </div>

    <?php include('view/footer.php');