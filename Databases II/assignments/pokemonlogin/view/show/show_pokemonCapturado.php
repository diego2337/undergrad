<!DOCTYPE html>
<html>

    <?php include('view/header.php'); ?>
    <body>
            <?php foreach ($pokemonsT as $poke):
                    $num = $poke->getNum_pokemon();
                    $id = $poke->getId_pokemon();
                    $nome = $poke->getNome();
                    $tipoSelected = $poke->getType();
                    $regiaoSelected = $poke->getRegion();
                    $level = $poke->getLevel();
                    $descricao = $poke->getDescription();
                    $img = $poke->getImagem();
                    
                endforeach;
            ?>
   <div class="form2" style="display: table; width: 90%;">
            <legend>Detalhes do meu Pokemon: </legend>
      <div id="showPokemon">	
        <?php foreach ($pokemonsT as $poke):?>
          <label><h4>Numero: </label> <?php echo $poke->getNum_pokemon(); ?>  </h4>        
          <label><h4>Id: </label> <?php echo $poke->getId_pokemon(); ?>  </h4>        
          <label><h4>Nome do pokemon: </label> <?php echo $poke->getNome(); ?>             </h4> 
	  <label><h4>Apelido: </label> <?php echo $poke->getApelido(); ?>  </h4>           
	     
	  
	  <label><h4> Tipo : </label> <?php echo $poke->getType();?> </h4> 
	  <label><h4> Nível: </label>   <?php echo $poke->getLevel();?> </h4> 
         
         <label><h4> Ataques do Pokemon : </h4> </label> 
         <?php endforeach;
            ?>
           <table id="result" class="table table-striped table-hover">
            <thead>
                <tr>
                    <th>Nome Ataque</th>
                    <th>Tipo</th>                 
                </tr>
            </thead>  
            <tbody>

              <?php
            foreach ($ataquepokemonF as $ap):
                echo '<tr>';
                    echo '<td>'.$ap->getAtaque().'</td>';
                    echo '<td> '.$tipoSelected.' </td>';
		    //echo '<td> '.$atk->getPrecisao().' </td>';
                   // echo '<td> '.$atk->getEfeito().' </td>';
                   // echo '<td> '.$atk->getUso_fora_batalha().' </td>';
                    //echo '<td><a class="btn" href="?action=editAtaque&idAtaque='.  $atk->getNome() .'">Editar</a></td> <td><a class="btn" href="?action=deleteAtaque&idAtaque='.  $atk->getNome() .'">Excluir</a></td>';
                echo '</tr>';
                endforeach;
             ?>
            </tbody>
            
             </table>
    
                 
   
              <?php if($qtdAtaque < 4)echo '<a class="btn btn-primary btn-large" href="?action=vinculaAtaque&tipoPokemon='. $tipoSelected.'&idPokemon='. $id.'">Adicionar Ataque</a></td>';   ?>
	  </div>
	 
	 <div class="pokemonCap">
	    <img src='web/img/pokemon/<?php echo $poke->getImagem()?>'>
         </div>
     </div>
        
        
        
        
            
        <?php include ('view/footer.php') ?>