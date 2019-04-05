<?php include $_SERVER['DOCUMENT_ROOT'].'/trabalho_progweb/view/header.php' ?>

	<form action="?action=editarQuestaoDB"class="form-search" method="POST" enctype="multipart/form-data">
		<div class="panel panel-default">
			<div class="panel-heading">Insira abaixo as alterações ao exercício.</div>
			<div class="panel-body">
				<div class="container">
					<div class="row">
						<div class="panel panel-info col-xs-5 right-float">
							<div class="panel-heading">Dificuldade:</div>
							<div class="panel-body">
								<div class="radio-inline">
									<label>
										<?php 
											if($questoes[0]->getDificuldade() == 'Fácil')
												echo '<input type="radio" name="dificuldade" id="1" value="Fácil" checked>';
											else
												echo '<input type="radio" name="dificuldade" id="1" value="Fácil">';
										?>
										Fácil
									</label>
								</div>
								<div class="radio-inline">
									<label>
										<?php 
											if($questoes[0]->getDificuldade() == 'Média')
												echo '<input type="radio" name="dificuldade" id="2" value="Média" checked>';
											else
												echo '<input type="radio" name="dificuldade" id="2" value="Média">';
										?>
										Média
									</label>
								</div>
								<div class="radio-inline">
									<label>
										<?php 
											if($questoes[0]->getDificuldade() == 'Difícil')
												echo '<input type="radio" name="dificuldade" id="3" value="Difícil" checked>';
											else
												echo '<input type="radio" name="dificuldade" id="3" value="Difícil">';
										?>
										Difícil
									</label>
								</div>
							</div>
						</div>
						<div class="panel panel-info col-xs-5">
							<div class="panel-heading">Tipo da questão:</div>
							<div class="panel-body">
								<div class="radio-inline">
									<label>
										<?php 
											if($questoes[0]->getTipo() == 'Acadêmica')
												echo '<input type="radio" name="tipoQuestao" id="1" value="Acadêmica" checked>';
											else
												echo '<input type="radio" name="tipoQuestao" id="1" value="Acadêmica">';
										?>
										Acadêmica
									</label>
								</div>
								<div class="radio-inline">
									<label>
										<?php 
											if($questoes[0]->getTipo() == 'Poscomp')
												echo '<input type="radio" name="tipoQuestao" id="2" value="Poscomp" checked>';
											else
												echo '<input type="radio" name="tipoQuestao" id="2" value="Poscomp">';
										?>
										POSCOMP
									</label>
								</div>
								<div class="radio-inline">
									<label>
										<?php 
											if($questoes[0]->getTipo() == 'Concurso')
												echo '<input type="radio" name="tipoQuestao" id="3" value="Concurso" checked>';
											else
												echo '<input type="radio" name="tipoQuestao" id="3" value="Concurso">';
										?>
										Concurso
									</label>
								</div>
							</div>
						</div>
					</div>
				</div>
				<div class="input-group">
					<?php 
						echo '<input type="date" class="form-control" placeholder="Data (AAAA-MM-DD)" name="data" value="'
						.$questoes[0]->getAno().'"">'
					?>
				</div>	
				<br>
				<?php
						echo '<select class="form-control" name="m_id">';
						foreach($materias as $m)
						{
							if($m->getId() == $questoes[0]->getMId())
								echo '<option value="'.$m->getId().'" selected>'.$m->getNomeMateria().'</option>';
							else
								echo '<option value="'.$m->getId().'">'.$m->getNomeMateria().'</option>';
						}
						echo '</select>';
				?>
				<br>
				<div class="input-group">
					<textarea rows="20" cols="150" class="form-control" placeholder="Enunciado" name="enunciado"><?php echo trim($questoes[0]->getEnunciado()); ?></textarea>
				</div>
				<br>
				<div class="alert alert-warning" role="alert">
					Selecione o campo "Manter imagem" para não alterar a imagem já associada a questão, ou "Limpar imagem" para
					removê-la da questão. Se você inserir uma imagem no campo abaixo então marque "Limpar imagem".
				</div>
				<div class="radio-inline">
					<input type="radio" name="mudar" id="1" value="Manter imagem" checked> Manter imagem
				</div>
				<div class="radio-inline">
					<input type="radio" name="mudar" id="2" value="Limpar imagem"> Limpar imagem
				</div>
				<br><br>
				<!-- Nota: o campo "value" não pode ser povoado na edição por questões de segurança -->
				Inserir uma imagem (opcional): <input class="btn" type="file" name="imagem">
				<br>
				<div class="alert alert-warning" role="alert">Se você inserir uma imagem, não deixe de descrevê-la no campo abaixo, 
					por questões de acessibilidade. Se você não explicitar nada então o texto padrão "Nenhuma imagem associada" 
					será exibido caso a imagem falhe a carregar.</div>
				<div class="input-group">
					<textarea rows="3" cols="50" class="form-control" placeholder="Descrição (breve) da imagem" name="texto_alt"><?php echo trim($questoes[0]->getTextoAlt()); ?></textarea>
				</div>
				<br>
				<div class="input-group">
					<textarea rows="10" cols="90" class="form-control" placeholder="Alternativas" name="alternativas"><?php echo trim($questoes[0]->getAlternativas()); ?></textarea>
				</div>
				<br>
				<div class="input-group">
					<textarea rows="1" cols="60" class="form-control" placeholder="Resposta correta" name="resposta"><?php echo trim($questoes[0]->getResposta()); ?></textarea>
				</div>
				<!-- Como estamos tratando de edição, esses dois valores são passados silenciosamente ("hidden") via POST -->
				<input hidden name="q_id" value="<?php echo $questoes[0]->getId(); ?>">
				<input hidden name="imagemOriginal" value="<?php echo $questoes[0]->getImagem(); ?>">
				<br>
				<button class="btn" type="submit" id="insert">Editar</button>
			</div>
		</div>
	</form>

<?php include $_SERVER['DOCUMENT_ROOT'].'/trabalho_progweb/view/footer.php' ?>