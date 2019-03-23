<!DOCTYPE html>
<html>

    <?php include('view/header.php'); ?>

    <div class="form2">
        <legend>Cadastrar novo Pokemon: </legend>
        <div class="lerge-form">
            
        <form class="form-horizontal" action="?action=insertPokemonDB" method="post">
            
            <label class="control-label">Numero: </label>
            <input class="form-control" name="num" type="text" placeholder="1-386">
            
            <label class="control-label">Nome:</label>
                <input name="nome" class="form-control" type="text" >
                
            <label class="control-label">Tipo:</label>
                <select name="tipo" class="form-control">
                    <?php foreach ($tipo as $t => $t_value): ?>
                        <option value="<?php echo $t ?>"><?php echo $t_value ?></option>
                    <?php endforeach; ?>
                </select>
            

            <label class="control-label">Região:</label>
            <select name="regiao" class="form-control">
                <?php foreach ($regiao as $r => $r_value): ?>
                    <option value="<?php echo $r ?>"><?php echo $r_value ?></option>
                <?php endforeach; ?>
            </select>


            <label class="control-label">Nível</label>
            <input name="nivel" class="form-control span2" type="number" placeholder="0">
            <label class="control-label">Descrição:</label>
            <textarea name="descricao" class="form-control" rows="3" placeholder="Descrição"></textarea>
            <button type="submit" class="btn btn-primary btn-lg">Enviar!</button>
        </form>
        </div>
    </div>

    <?php include('view/footer.php');