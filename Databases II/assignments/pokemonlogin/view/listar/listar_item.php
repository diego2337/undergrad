 <!DOCTYPE html>
<html>  
  <?php include 'view/header.php'; ?>
    <div class="form2">
    <legend>Lista de Itens:</legend>
        <form action="?action=buscaItem" class="form-search" method="POST">
                    <input class="input-lg" id="search" type="text" name="nome" placeholder="Nome do Item...">
                    <button class="btn btn-primary btn-lg" type="submit" id="button">Go!</button>
        </form>
        <table id="result" class="table table-striped table-hover">
            <thead>
                <tr>
                    <th>Nome do Item</th>
                    <th>Código</th>
                    <th>Preço</th>
                    <th>Função</th>
                </tr>
            </thead>
            <tbody>

              <?php
    
            foreach ($itens as $atk):
                echo '<tr>';
                    echo '<td> '.$atk->getNome().' </td>';
                    echo '<td> '.$atk->getCodigo().' </td>';
                    echo '<td> '.$atk->getPreco().' </td>';
                    echo '<td> '.$atk->getFuncao().' </td>';
                    echo '<td><a class="btn" href="?action=editItem&idItem='.  $atk->getCodigo() .'">Editar</a></td> <td><a class="btn" href="?action=deleteItem&idItem='.  $atk->getCodigo() .'">Excluir</a></td>';
                echo '</tr>';
                endforeach;
             ?>
            </tbody>
        </table>
    </div>

    <?php include 'view/footer.php'; ?>