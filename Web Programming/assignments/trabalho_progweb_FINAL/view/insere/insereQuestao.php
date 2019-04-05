<?php include $_SERVER['DOCUMENT_ROOT'].'/trabalho_progweb/view/header.php' ?>

	<form action="?action=inserirQuestaoDB"class="form-search" method="POST" enctype="multipart/form-data">
		<div class="panel panel-default">
			<div class="panel-heading">Insira abaixo as informações correspondentes ao exercício.</div>
			<div class="panel-body">
				<div class="container">
					<div class="row">
						<div class="panel panel-info col-xs-5 right-float">
							<div class="panel-heading">Dificuldade:</div>
							<div class="panel-body">
								<div class="radio-inline">
									<label>
										<input type="radio" name="dificuldade" id="1" value="Fácil" checked>
										Fácil
									</label>
								</div>
								<div class="radio-inline">
									<label>
										<input type="radio" name="dificuldade" id="2" value="Média">
										Média
									</label>
								</div>
								<div class="radio-inline">
									<label>
										<input type="radio" name="dificuldade" id="3" value="Difícil">
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
										<input type="radio" name="tipoQuestao" id="1" value="Acadêmica" checked>
										Acadêmica
									</label>
								</div>
								<div class="radio-inline">
									<label>
										<input type="radio" name="tipoQuestao" id="2" value="Poscomp">
										POSCOMP
									</label>
								</div>
								<div class="radio-inline">
									<label>
										<input type="radio" name="tipoQuestao" id="3" value="Concurso">
										Concurso
									</label>
								</div>
							</div>
						</div>
					</div>
				</div>
				<div class="input-group">
					<input type="date" class="form-control" placeholder="Data (AAAA-MM-DD)" name="data">
				</div>	
				<br>
				<?php
						echo '<select class="form-control" name="m_id">';
						foreach($materias as $m)
						{
							echo '<option value="'.$m->getId().'">'.$m->getNomeMateria().'</option>';
						}
						echo '</select>';
				?>
				<br>
				<div class="input-group">
					<textarea rows="20" cols="150" class="form-control" placeholder="Enunciado" name="enunciado"></textarea>
				</div>
				<br>
				Inserir uma imagem (opcional): <input class="btn" type="file" name="imagem">
				<br>
				<div class="alert alert-warning" role="alert">Se você inserir uma imagem, não deixe de descrevê-la no campo abaixo, 
					por questões de acessibilidade. Se você não explicitar nada então o texto padrão "Nenhuma imagem associada" 
					será exibido caso a imagem falhe a carregar.</div>
				<div class="input-group">
					<textarea rows="3" cols="50" class="form-control" placeholder="Descrição (breve) da imagem" name="texto_alt"></textarea>
				</div>
				<br>
				<div class="input-group">
					<textarea rows="10" cols="90" class="form-control" placeholder="Alternativas" name="alternativas"></textarea>
				</div>
				<br>
				<div class="input-group">
					<textarea rows="1" cols="60" class="form-control" placeholder="Resposta correta" name="resposta"></textarea>
				</div>
				<br>
				<button class="btn" type="submit" id="insert">Inserir</button>
			</div>
		</div>
	</form>

<?php include $_SERVER['DOCUMENT_ROOT'].'/trabalho_progweb/view/footer.php' ?>