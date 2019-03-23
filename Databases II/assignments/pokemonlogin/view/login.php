<!DOCTYPE html>
<html>
    <head>
 <?php include 'header.php'; ?>
    <body>

        <div class="container">
           
            <div class="jumbotron">
                <h2>Seja bem-vindo à Pokedex!</h2>
                <form class="form-horizontal" action="?action=auth" method="POST" >
                    <div class="control-group">
                        <label class="control-label">Login</label>
                        <div class="controls">
                            <input type="text" name="login" id="login" placeholder="Login">
                        </div>
                    </div>
                    <div class="control-group">
                        <label class="control-label">Senha</label>
                        <div class="controls">
                            <input type="password" name="senha" id="senha" placeholder="Senha">
                        </div>
                    </div>
                    <div class="control-group">                     
                       <button type="submit" class="btn">Entrar</button>             
                    </div>
                </form>
            </div>

            <?php include 'footer.php'; ?>
        </div>
    </body>
</html>