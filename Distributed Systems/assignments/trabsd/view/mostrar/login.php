<?php include $_SERVER['DOCUMENT_ROOT'].'/trabsd/view/header.php' ?>
	<?php
		if(isset($_GET['badPass']) && $_GET['badPass'] == 1)
		{
			echo '<div class="alert alert-danger" role="alert">Senha ou nome de usuário incorreta. Por favor tente novamente.</div>';
		}
	?>
	<form action="?action=confirmarLogin" class="form-search" method="POST">
		<div class="panel panel-primary">
			<div class="panel-heading"><h3>Por favor, insira o seu nome de usuário e sua senha:</h3></div>
			<div class="panel-body">
				<input type="text" class="form-control" placeholder="login" name="login">
				<br>
				<input type="password" class="form-control" placeholder="senha" name="password">
				<br>
				<button class="btn" type="submit" id="login">Entrar</button>
			</div>
		</div>
	</form>
<?php include $_SERVER['DOCUMENT_ROOT'].'/trabsd/view/footer.php' ?>