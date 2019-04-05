<?php include $_SERVER['DOCUMENT_ROOT'].'/trabalho_progweb/view/header.php' ?>
		<script type="text/javascript">
			function mostrar ()
			{
				document.getElementById("Resposta").innerHTML = "<?php echo 'A resposta é: <br>'.nl2br($questoes[0]->getResposta())?>";
			}
		</script>
		<div class="panel panel-warning">
			<?php echo '<div class="panel-heading">Questão '.$questoes[0]->getId().'</div>'; ?>
			<div class="panel-body">
				<?php 
					echo 'Tipo de questão: <a href="?action=mostrarQuestoes&tipo_questao='.$questoes[0]->getTipo().
						'">'.$questoes[0]->getTipo().'</a><br><br>'; 
					echo 'Matéria: <a href="?action=mostrarQuestoes&idMateria='.$questoes[0]->getMId().
						'">'.$questoes[0]->getNomeMateria().'</a><br><br>'; 
					echo 'Dificuldade: <a href="?action=mostrarQuestoes&dificuldade='.$questoes[0]->getDificuldade().
						'">'.$questoes[0]->getDificuldade().'</a><br><br>'; 
					echo '<br>';
					echo '<ul class="list-group">';
						echo nl2br('<li class="list-group-item">'.$questoes[0]->getEnunciado().'</li>');
						echo '<br>';
						echo '<li class="list-group-item">';
						if($questoes[0]->getTextoAlt() != NULL)
						{
							echo '<img alt="'.$questoes[0]->getTextoAlt().'" src="'.
							str_replace("/var/www/trabalho_progweb/", "", $questoes[0]->getImagem()).'"/></li>';
							echo nl2br('<li class="list-group-item">'.$questoes[0]->getAlternativas().'</li>');
						}
						else
						{
							echo '<img alt="Nenhuma imagem associada." src="'.
							str_replace("/var/www/trabalho_progweb/", "", $questoes[0]->getImagem()).'"/></li>';
							echo nl2br('<li class="list-group-item">'.$questoes[0]->getAlternativas().'</li>');
						}
					echo '</ul>';
				?>
				<button class="btn" onclick="mostrar()">Resposta</button>
				<ul class="list-group">
					<li class="list-group-item" id="Resposta"></li>
				</ul>
				<?php echo ' <a class="btn" href="?action=buscarEMostrarQuestao&anterior=1&idQuestao='
				.$questoes[0]->getId().'&tipo_questao='.$questoes[0]->getTipo().'&idMateria='.$questoes[0]->getMId().'
				&dificuldade='.$questoes[0]->getDificuldade().'">Questão anterior</a>'; ?>
				<?php echo ' <a class="btn" href="?action=buscarEMostrarQuestao&anterior=0&idQuestao='
				.$questoes[0]->getId().'&tipo_questao='.$questoes[0]->getTipo().'&idMateria='.$questoes[0]->getMId().'
				&dificuldade='.$questoes[0]->getDificuldade().'">Próxima questão</a>'; ?>
			</div>
		</div>

<?php include $_SERVER['DOCUMENT_ROOT'].'/trabalho_progweb/view/footer.php' ?>