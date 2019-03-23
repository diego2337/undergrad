<?php include 'view/header.php'; ?>


    <div class="form2">
    <legend>Procure pelo nome do ataque:</legend>
    
    
        <form action="?action=buscaAtaque" class="form-search" method="POST">
                <input class="input-lg" id="search" type="text" name="nome" placeholder="Water Gun, Tackle, etc...">
                <button class="btn btn-primary btn-lg" type="submit" id="button">Go!</button>
        </form>
        
        
        <table id="result" class="table table-striped">
            <thead>
                <tr>
                    <th>#</th>
                    <th>Nome do Ataque</th>
                    <th>Tipo</th>
                    <th>Poder</th>
                    <th>Editar</th>
                    <th>Excluir</th>
                </tr>
            </thead>
            <tbody>
              <?php
            foreach ($ataques as $ataque):
                echo '<tr>';
                    echo '<td> '.$ataque->getNumber().' </td>';
                    echo '<td> '.$ataque->getName().' </td>';
                    echo '<td> '.$ataque->getType().' </td>';
                    echo '<td> '.$ataque->getRegion().' </td>';
                    echo '<td> '.$ataque->getLevel().' </td>';
                    echo '<td><a class="btn" href="?action=editAtaque&nomeAtaque='.  $ataque->getNome() .'">Editar</a></td> <td><a class="btn" href="?action=deleteAtaque&nomeAtaque='.  $ataque->getNome() .'">Excluir</a></td>';
                echo '</tr>';
                endforeach;
             ?>
            </tbody>
        </table>
        
     </div>
  
     <?php include('view/footer.php'); ?>