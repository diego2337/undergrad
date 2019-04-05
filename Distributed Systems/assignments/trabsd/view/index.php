<!DOCTYPE html>
<html>

    <?php include 'header.php'; ?>
    <?php
    	if(isset($_GET['signIn']) && $_GET['signIn'] == 1)
        {
            echo '<div class="alert alert-success" role="alert">Você entrou com sucesso.</div>';   
        }
        else if(isset($_GET['logged']) && $_GET['logged'] == 1)
        {
            echo '<div class="alert alert-danger" role="alert">Já existe um usuário conectado.</div>';   
        }
        else if(isset($_GET['updateSenha']))
        {
            echo '<div class="alert alert-success" role="alert">A senha foi alterada com sucesso.</div>';   
        }
        else if(isset($_GET['signUp']) && $_GET['signUp'] == 1)
        {
            echo '<div class="alert alert-success" role="alert">Você se cadastrou com sucesso.</div>';   
        }
        else if(isset($_GET['fimConta']))
        {
            echo '<div class="alert alert-success" role="alert">A conta foi excluída. Todas os arquivos associadas a ela foram
            removidos.</div>';
        }
    ?>
    
    	<div class="panel panel-info pipi2">
    		<div class="panel-heading"><h3>Sobre o H2S3</h3></div>
    		<div class="panel-body">
		        <div class="panel panel-info">
		                <p>Seja muito bem-vindo. Esse pequeno sistema tem como objetivo facilitar a manipulação de arquivos, permitindo o acesso de seus
		                	arquivos de qualquer lugar, de maneira transparente e segura, através da utilização do serviço S3, de computação em nuvem, 
		                	provido pela Amazon Web Services. Para começar a utilizá-lo, realize seu login (caso você seja um usuário) ou então cadastre-se.
		                	Fique à vontade!</p>
		        </div>
	    	</div>
    	</div>
    
     <?php
		if(isset($_SESSION['usuario']))
		{
            $user = new UsuarioDAO();
            $u = $user->checar2($_SESSION['usuario']);
                 echo '<div class="panel panel-primary pipi2">
			<div class="panel-heading"><h3>Olá, '.$_SESSION['usuario'].'</h3></div>
			<div class="panel-body">
                        <div class="panel panel-info">
                          <p>  Você está usando '.$u->getSize().' KB do espaço total de armazenamento. Clique na opção Exibir painel para acessar seus arquvios.
</p>
                ';
        echo '</div>
        </div>
		</div>';
                }else
                echo '<div class="panel panel-primary pipi2">
			<div class="panel-heading"><h3>Por favor, insira o seu nome de usuário e sua senha:</h3></div>
			<form action="?action=confirmarLogin" class="form-search pipi" method="POST">
				<div class="panel-body pipi2">
					<input type="text" class="form-control" placeholder="login" name="login">
					<br>
					<input type="password" class="form-control" placeholder="senha" name="password">
					<br>
						<button class="btn" type="submit" id="login">Entrar</button>
				</div>
			</form>
		</div>';
	    ?>
		
    <?php include 'footer.php'; ?>
    </div>
    </body>
</html>
