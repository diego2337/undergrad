 <!DOCTYPE html>
<html>  
  <?php include 'view/header.php'; 
    if (isset($msg)){
        echo '<p class="alert alert-block">'. $msg. '</p>' ;
    } ?>
    <div class="form2">
     
    <legend>Lista dos meus Pokémons:</legend>
        <form action="?action=buscaMeusPokemons" class="form-search" method="POST">
                    <input class="input-lg" id="search" type="text" name="nome" placeholder="Charmander, Squirtle, etc...">
                    <button class="btn btn-primary btn-lg" type="submit" id="button">Go!</button>
        </form>
        <table id="result" class="table table-striped table-hover">
            <thead>
                <tr>
                    <th>#</th>
                    <th>Nome Pokémon</th>
                    <th>Apelido</th>
                    <th>Nivel</th>
                    
                </tr>
            </thead>
            <tbody>
              <?php
            foreach ($treinadores_poke as $poke):
                echo '<tr>';
                    echo '<td> '.$poke->getId_pokemon().' </td>';
                    echo '<td><a href="?action=showMyPokemon&idPokemon='. $poke->getId_pokemon() .'"> '.$poke->getNome().'</a></td>';
                    echo '<td> '.$poke->getApelido().' </td>';
                    echo '<td> '.$poke->getLevel().' </td>';
                   // echo '<td><a class="btn" href="?action=editPokemon&idPokemon='.  $poke->getNumber() .'">Editar</a></td> <td><a class="btn" href="?action=deletePokemon&idPokemon='.  $poke->getNumber() .'">Excluir</a></td>';
                echo '</tr>';
                endforeach;
             ?>
            </tbody>
        </table>
    </div>

    <?php include 'view/footer.php'; ?>