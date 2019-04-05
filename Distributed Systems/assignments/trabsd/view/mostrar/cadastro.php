<?php include $_SERVER['DOCUMENT_ROOT'].'/trabsd/view/header.php' ?>
	<form action="?action=cadastrar" class="form-search" method="POST">
		<div class="panel panel-info">
			<div class="panel-heading"><h3>Insira abaixo as informações (obrigatórias) referentes a seu cadastro:</h3></div>
			<div class="panel-body">
				<?php 
					if(isset($_GET['incorrect']) && $_GET['incorrect'] == 1)
						echo '<div class="alert alert-danger" role="alert">As senhas digitadas diferiram, ou o nome de 
							usuário já existe.</div>';
					else if(isset($_GET['incorrect']) && $_GET['incorrect'] == 2)
						echo '<div class="alert alert-danger" role="alert">Erro na execução do cadadstro.</div>';
				?>
				<input type="text" class="form-control" placeholder="login" name="login">
				<br>
				<input type="password" class="form-control" placeholder="senha" name="password">
				<br>
				<input type="password" class="form-control" placeholder="confirmar senha" name="passwordcheck">
				<br>
				<button class="btn" type="submit" id="login">Confirmar cadastro</button>
			</div>
		</div>
	</form>
<?php include $_SERVER['DOCUMENT_ROOT'].'/trabsd/view/footer.php' ?>