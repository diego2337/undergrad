<?php include $_SERVER['DOCUMENT_ROOT'].'/trabsd/view/header.php' ?>
	<form action="?action=editarSenhaDB" class="form-search" method="POST">
		<div class="panel panel-primary">
			<div class="panel-heading"><h3>Por favor, insira as informações necessárias:</h3></div>
			<div class="panel-body">
				<?php 
					if(isset($_GET['incorrect']) && $_GET['incorrect'] == 1)
						echo '<div class="alert alert-danger" role="alert">A senha atual está incorreta.</div>';
					else if(isset($_GET['incorrect']) && $_GET['incorrect'] == 2)
						echo '<div class="alert alert-danger" role="alert">A inserção da nova senha difere da 
					inserção da confirmação da nova senha.</div>';
				?>
				<input type="password" class="form-control" placeholder="senha atual" name="password">
				<br>
				<input type="password" class="form-control" placeholder="senha nova" name="newPassword">
				<br>
				<input type="password" class="form-control" placeholder="confirmar senha" name="newPasswordCheck">
				<br>
				<button class="btn" type="submit" id="login">Entrar</button>
			</div>
		</div>
	</form>
<?php include $_SERVER['DOCUMENT_ROOT'].'/trabsd/view/footer.php' ?>