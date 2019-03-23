 <!DOCTYPE html>
<html>  
  <?php include 'view/header.php'; 
    if (isset($msg)){
        echo '<p class="alert alert-block">'. $msg. '</p>' ;
    } ?>
    <div class="form2">
    <legend>Lista de Ataques:</legend>
        <form action="?action=buscaAtaque" class="form-search" method="POST">
                    <input class="input-lg" id="search" type="text" name="nome" placeholder="Ember, Tackle, etc...">
                    <button class="btn btn-primary btn-lg" type="submit" id="button">Go!</button>
        </form>
        <table id="result" class="table table-striped table-hover">
            <thead>
                <tr>
                    <th>Nome Ataque</th>
                    <th>Tipo</th>
                    <th>Quantidade</th>
                    <th>Poder</th>
                </tr>
            </thead>
            <tbody>

              <?php
            foreach ($ataques as $atk):
                echo '<tr>';
                    echo '<td>'.$atk->getNome().'</td>';
                    echo '<td> '.$atk->getTipo().' </td>';
                    echo '<td> '.$atk->getQuantidade().' </td>';
                    echo '<td> '.$atk->getPoder().' </td>';
                    //echo '<td> '.$atk->getPrecisao().' </td>';
                   // echo '<td> '.$atk->getEfeito().' </td>';
                   // echo '<td> '.$atk->getUso_fora_batalha().' </td>';
                    echo '<td><a class="btn" href="?action=alterarPokemonAtaqueDB&idAtaque='.  $atk->getNome() .'&idPokemon='.$_GET['idPokemon'].'">Substituir</a></td>';
                echo '</tr>';
                endforeach;
             ?>
            </tbody>
        </table>
    </div>

    <?php include 'view/footer.php'; ?>