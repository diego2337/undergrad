<?php include $_SERVER['DOCUMENT_ROOT'].'/trabsd/view/header.php'; ?>
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
				<div class="pipi panel panel-warning navegacao">
					<div class="panel panel-warning panel-heading">Gerenciar sua conta</div>
					<div class="panel panel-warning panel-body">
					<a href="?action=editarSenha&usuario=<?php echo $_SESSION['u_id'] ?>" 
						class="list-group-item list-group-item-danger">
						Alterar minha senha</a>
					<a href="#" onclick="deletar(<?php echo $_SESSION['u_id']?>)" class="list-group-item list-group-item-danger">
						Deletar minha conta</a>
					</div>
				</div>
				<div class="pipi4 panel panel-info">
					<div class="panel panel-info clearfix panel-heading">
						<div class="half_div">
							Usuários
						</div>
					</div>
					<div class="panel panel-info panel-body">
						<table class="table browsefile">
							<tr>
							    <th><!--<a href="?action=ordenarPorNome&usuario=<?php echo $_SESSION['u_id']?>&path=<?php echo $pref?>">-->Nome<!--</a>--></th>
							    <th><!--<a href="?action=ordenarPorTipo&usuario=<?php echo $_SESSION['u_id'] ?>">-->Tamanho do bucket<!--</a>--></th>
							</tr>
							<!-- TODO - buscar todos os usuarios que tem buckets no s3 -->
              <?php 
                foreach ($users as $user)
                {
                	if($user['size'] < 0)
                		$user['size'] = 0;
                  echo'<tr><td>'.$user['login'].'</td><td>'.$user['size'].' KB</td></tr>';
                }
              ?>                                          
					  </table> 
					</div>
				</div>
			</div>
		</div>
<?php include $_SERVER['DOCUMENT_ROOT'].'/trabsd/view/footer.php' ?>
