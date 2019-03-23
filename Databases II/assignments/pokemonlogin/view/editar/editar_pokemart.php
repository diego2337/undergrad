<?php include('view/header.php'); 
    
 foreach ($pokemarts as $pokemart) {
     $local = $pokemart->getLocal();
     $qtd = $pokemart->getQtd_itens();
    
}

?>
    <div class="form2">
        <div class="lerge-form">
            <form class="form-horizontal" action="?action=editPokemartDB" method="POST">
                <legend>Editar pokermart: <?php echo $local ?></legend>

                <label>Local:  </label>      
                <input  class="form-control" type="text" name="local" value="<?php echo $local ?>"  >

                <label >Quantidade de Itens:  </label>
                <input class="form-control" type="text" placeholder="" name="qtd" value="<?php echo $qtd ?>">

                <label> <button type="submit" class="btn">Enviar!</button> </label>

            </form>
        </div>
    </div> 
<?php include 'view/footer.php'; ?>