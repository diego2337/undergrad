<?php include $_SERVER['DOCUMENT_ROOT'].'/trabalho_progweb/view/header.php'; ?>
	<script type="text/javascript">
			function deletar (user)
			{
				if(confirm("Você tem certeza que deseja deletar a sua conta?") == true)
				{
					window.location.href = "?action=deletarConta&usuario="+user;
				}
				else
				{
					// Não faça nada
				}
			}
	</script>
	<div class="panel panel-primary">
			<?php echo '<div class="panel-heading"><h3>Bem-vindo, '.$_SESSION['usuario'].'</h3></div>' ?>
			<div class="panel-body">
				<ul class="list-group">
					<a href="?action=mostrarQuestoes&porUsuario=<?php echo $_SESSION['u_id'] ?>" 
						class="list-group-item list-group-item-success">Buscar minhas questões</a>
					<a href="?action=inserirQuestao" class="list-group-item list-group-item-info">Inserir uma questão</a>
					<a href="?action=mostrarQuestoes&porUsuario=<?php echo $_SESSION['u_id'] ?>" 
						class="list-group-item list-group-item-warning">
						Alterar uma das minhas questões</a>
					<a href="?action=mostrarQuestoes&porUsuario=<?php echo $_SESSION['u_id'] ?>" 
						class="list-group-item list-group-item-danger">
						Remover uma das minhas questões</a>
					<a href="?action=editarSenha&usuario=<?php echo $_SESSION['u_id'] ?>" 
						class="list-group-item list-group-item-danger">
						Alterar minha senha</a>
					<a href="#" onclick="deletar(<?php echo $_SESSION['u_id']?>)" class="list-group-item list-group-item-danger">
						Deletar minha conta</a>
				</ul>
			</div>
		</div>
<?php include $_SERVER['DOCUMENT_ROOT'].'/trabalho_progweb/view/footer.php' ?>