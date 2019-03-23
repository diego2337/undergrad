<!DOCTYPE html>
<html>

    <?php include('view/header.php'); ?>
    <body>
            <?php foreach ($pokemons as $poke):
                    $num = $poke->getNumber();
                    $nome = $poke->getName();
                    $tipoSelected = $poke->getType();
                    $regiaoSelected = $poke->getRegion();
                    $level = $poke->getLevel();
                    $descricao = $poke->getDescription();
                    $img = $poke->getImagem();
                    
                endforeach;
            ?>
        <div class="form2" style="display: table; width: 90%;">
            <legend>Detalhes do Pokemon: </legend>
	<div id="showPokemon">	
        <?php foreach ($pokemons as $poke):?>
          <label><h4>Nome do pokemon: </label> <?php echo $poke->getName(); ?>             </h4> 
	  <label><h4>Numero: </label> <?php echo $poke->getNumber(); ?>  </h4>           
	
	  <label><h4> Tipo : </label> <?php echo $poke->getType();?> </h4> 
	  <label><h4> Nível: </label>   <?php echo $poke->getLevel();?> </h4> 
	  <label><h4> Descrição: </label>   <?php echo $poke->getDescription();?> </h4> 
	 
            
            
           <?php endforeach;
            ?>
            
        </div>
        
        <div class="pokemonCap">
	<img src='web/img/pokemon/<?php echo $poke->getImagem()?>'>
          </div>
      </div>
        
        
            
        <?php include ('view/footer.php') ?>