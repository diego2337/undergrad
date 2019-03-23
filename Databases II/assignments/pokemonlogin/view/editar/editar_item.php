<?php 
    
    include('view/header.php'); 
    
    foreach ($itens as $item) {
        $nome = $item->getNome();
        $codigo = $item->getCodigo();
        $preco = $item->getPreco();
        $funcao = $item->getFuncao();        
    }
    
?>
    <div class="form2">
        <div class="lerge-form">
            <form class="form-horizontal" action="?action=editItemDB" method="POST">
                <legend>Editar item <?php echo $nome ?> </legend>

                <label>Nome:  </label>      
                <input  class="form-control" type="text" name="nome" value="<?php echo $nome ?>"  >

                <label >Código do ítem:  </label>
                <input class="form-control" type="hidden" placeholder="" value="<?php echo $codigo ?>" name="codigo">

                <label >Preço:  </label>
                <input class="form-control" type="text" placeholder="50" value ="<?php echo $preco ?>"name="preco">
                
                <label>Função:</label>
                <textarea class="form-control" rows="3" name="funcao"><?php echo $funcao ?></textarea>


                <label> <button type="submit" class="btn">Enviar!</button> </label>

            </form>
        </div>
    </div> 
    <?php include 'view/footer.php'; ?>