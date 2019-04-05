<?php include $_SERVER['DOCUMENT_ROOT'].'/trabalho_progweb/view/header.php' ?>
	<form action="?action=confirmarLogin" class="form-search" method="POST">
		<div class="panel panel-primary">
			<div class="panel-heading"><h3>Por favor, insira o seu nome de usuário e sua senha:</h3></div>
			<div class="panel-body">
				<?php 
					if(isset($_GET['incorrect']) && $_GET['incorrect'] == 1)
						echo '<div class="alert alert-danger" role="alert">A senha ou o nome do usuário está incorreto. 
					Por favor tente novamente.</div>';
				?>
				<input type="text" class="form-control" placeholder="login" name="login">
				<br>
				<input type="password" class="form-control" placeholder="senha" name="password">
				<br>
				<button class="btn" type="submit" id="login">Entrar</button>
			</div>
		</div>
	</form>
<?php include $_SERVER['DOCUMENT_ROOT'].'/trabalho_progweb/view/footer.php' ?>