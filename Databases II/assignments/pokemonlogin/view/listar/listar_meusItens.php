 <!DOCTYPE html>
<html>  
  <?php include 'view/header.php'; ?>
    <div class="form2">
    <legend>Lista de Itens:</legend>
        <form action="?action=buscaMeuItem" class="form-search" method="POST">
                    <input class="input-lg" id="search" type="text" name="nome" placeholder="Nome do Item...">
                    <button class="btn btn-primary btn-lg" type="submit" id="button">Go!</button>
        </form>
        <table id="result" class="table table-striped table-hover">
            <thead>
                <tr>
                    <th>Nome do Item</th>
                    <th>Código</th>
                    <th>Preço</th>
                    <th>Quantidade</th>
                </tr>
            </thead>
            <tbody>

              <?php
    
            foreach ($itens as $item):
                echo '<tr>';
                    echo '<td> '.$item->getNome_item().' </td>';
                    echo '<td> '.$item->getCodigo_item().' </td>';
                    echo '<td> '.$item->getPreco().' </td>';
                    echo '<td> '.$item->getQuantidade().' </td>';
                    echo '<td><a class="btn" href="?action=usarItem&idItem='.  $item->getCodigo_item() .'">Usar</a></td>';
                echo '</tr>';
                endforeach;
             ?>
            </tbody>
        </table>
    </div>

    <?php include 'view/footer.php'; ?>