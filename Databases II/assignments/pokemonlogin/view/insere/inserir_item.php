    <?php include('view/header.php'); ?>
    <div class="form2">
        <div class="lerge-form">
            <form class="form-horizontal" action="?action=insertItemDB" method="POST">
                <legend>Cadastrar novo item </legend>

                <label>Nome:  </label>      
                <input  class="form-control" type="text" name="nome"  >

                <label >Código do ítem:  </label>
                <input class="form-control" type="text" placeholder="" name="codigo">

                <label >Preço:  </label>
                <input class="form-control" type="text" placeholder="50" name="preco">
                
                <label>Função:</label>
                <textarea class="form-control" rows="3" name="funcao"></textarea>


                <label> <button type="submit" class="btn">Enviar!</button> </label>

            </form>
        </div>
    </div> 
    <?php include 'view/footer.php'; ?>