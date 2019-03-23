 <!DOCTYPE html>
<html>  
  <?php include 'view/header.php'; 
    if (isset($msg)){
        echo '<p class="alert alert-block">'. $msg. '</p>' ;
    } ?>
    <div class="form2">
     
    <legend>Lista de Pokémons:</legend>
        <form action="?action=buscaPokemon" class="form-search" method="POST">
                    <input class="input-lg" id="search" type="text" name="nome" placeholder="Charmander, Squirtle, etc...">
                    <button class="btn btn-primary btn-lg" type="submit" id="button">Go!</button>
        </form>
        <table id="result" class="table table-striped table-hover">
            <thead>
                <tr>
                    <th>#</th>
                    <th>Nome Pokémon</th>
                    <th>Tipo</th>
                    <th>Região</th>
                    <th>Level</th>
                    <th>Editar</th>
                    <th>Excluir</th>
                </tr>
            </thead>
            <tbody>
              <?php
            foreach ($pokemons as $poke):
                echo '<tr>';
                    echo '<td> '.$poke->getNumber().' </td>';
                    echo '<td><a href="?action=showPokemon&idPokemon='.  $poke->getNumber() .'"> '.$poke->getName().'</a></td>';
                    echo '<td> '.$poke->getType().' </td>';
                    echo '<td> '.$poke->getRegion().' </td>';
                    echo '<td> '.$poke->getLevel().' </td>';
                    echo '<td><a class="btn" href="?action=editPokemon&idPokemon='.  $poke->getNumber() .'">Editar</a></td> <td><a class="btn" href="?action=deletePokemon&idPokemon='.  $poke->getNumber() .'">Excluir</a></td>';
                echo '</tr>';
                endforeach;
             ?>
            </tbody>
        </table>
    </div>

    <?php include 'view/footer.php'; ?>