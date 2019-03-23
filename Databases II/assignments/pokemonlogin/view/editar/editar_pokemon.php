<!DOCTYPE html>
<html>

    <?php include('view/header.php'); ?>
    <body>
        <div class="form2">
            <legend>Editar Pokémon: </legend>
        <form class="form lerge-form" action="?action=editPokemonDB" method="POST">
            <?php foreach ($pokemons as $poke):
                    $num = $poke->getNumber();
                    $nome = $poke->getName();
                    $tipoSelected = $poke->getType();
                    $regiaoSelected = $poke->getRegion();
                    $level = $poke->getLevel();
                    $descricao = $poke->getDescription();
                endforeach;
            ?>
            
            <label> 
                <input name="num" class="form-control" type="hidden" placeholder="1-256" value="<?php echo $num ?>">
            </label>
            <label>Nome:
                <input name="nome"  class="form-control" type="text" value="<?php echo $nome ?>">
            </label>
            
            <label>Tipo:
                <select name="tipo" class="form-control" >
                    <?php foreach ($tipo as $t => $t_value): ?>
                    <option selected="<?php if($t_value == $tipoSelected){ echo "selected"; }  ?>" value="<?php echo $t?>"><?php echo $t_value ?></option>
                    <?php endforeach;?>
                </select>
            </label>

             <label>Região:
                <select name="regiao" class="form-control">
                    <?php foreach ($regiao as $r => $r_value): ?>
                    <option selected="<?php if($r_value == $regiaoSelected){ echo "selected"; } ?>" value="<?php echo $r?>"><?php echo $r_value ?></option>
                    <?php endforeach;?>
                </select>
            </label>
            <label>Nível
                <input name="nivel" class="form-control span2" type="number" placeholder="0" value="<?php echo $level ?>">
            </label>
            
            <textarea name="descricao" class="form-control" rows="3" placeholder="Descrição"><?php echo $descricao; ?></textarea>

            <button type="submit" class="btn btn-primary btn-lg">Enviar!</button>
        </form>
        </div>
        <?php include 'view/footer.php'; ?>