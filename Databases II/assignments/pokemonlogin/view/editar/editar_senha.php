<!DOCTYPE html>
<html>

    <?php include('view/header.php'); ?>
    <body>
        <div class="form2">
            <legend>Editar Senha: </legend>
            
   
        <form class="form lerge-form" action="?action=alterarSenhaDB" method="POST">
           
            <label> Senha Antiga:
                <input name="senhaVelha" class="form-control" type="text" value="">
            </label>
            <label>Senha Nova:
                <input name="senhaNova"  class="form-control" type="text" value="">
            </label>
            
          
            
        <br>

            <button type="submit" class="btn btn-primary btn-lg">Enviar!</button>
        </form>
        </div>
        <?php include 'view/footer.php'; ?>