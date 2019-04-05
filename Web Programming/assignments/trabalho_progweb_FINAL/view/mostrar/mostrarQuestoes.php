<?php include $_SERVER['DOCUMENT_ROOT'].'/trabalho_progweb/view/header.php'; ?>
	<script type="text/javascript">
			function confirmar (q, m)
			{
				if(confirm("Você tem certeza que deseja deletar essa questão?") == true)
				{
					window.location.href = "?action=apagarQuestaoDB&idQuestao="+q+"&idMateria="+m;
				}
				else
				{
					// Não faça nada
				}
			}
	</script>
	<ul class="nav nav-tabs" role="tablist">
        <li><a href="?action=buscarQuestoes&busca=1">Matérias</a></li>
        <li><a href="?action=buscarQuestoes&busca=2">Área</a></li>
        <li><a href="?action=buscarQuestoes&busca=3">Dificuldade</a></li>
        <li><a href="?action=mostrarQuestoes&busca=4">Novas</a></li>
        <?php if(isset($_SESSION['usuario']))
                echo '<li><a href="?action=mostrarQuestoes&porUsuario='.$_SESSION['u_id'].'">Minhas Questões</a></li>' ?>
    </ul>
<?php
	if($flg == 0)
	{
		$_SESSION['materia'] = 1;
		echo '<div class="panel panel-primary">';
		if(isset($questoes[0]))
		{
			echo '<div class="panel-heading"><h3>Mostrando questões de '.$questoes[0]->getNomeMateria().':</h3></div>';
			echo '<div class="list-group"> ';
			foreach ($questoes as $q) 
			{
			    echo '<a class="list-group-item" href="?action=mostrarQuestao&idQuestao='.$q->getId().'">'.$q->getId().' '.
			    $q->getTipo().' '.$q->getAno().' '.$q->getDificuldade().'</a>';
			}
			echo '</div>';
		}
		else
		{
			echo '<div class="panel-heading"><h3>Nenhuma questão inserida nessa matéria ainda.</h3></div>';
			echo '<div class="list-group alert alert-danger" role="alert"> Por favor, faça o login ou cadastre-se (nos botões acima) 
			e ajude-nos sendo o primeiro a inserir uma questão! </div>';
		}
		echo '</div>';
	}
	else if($flg == 4)
	{
		$_SESSION['materia'] = 2;
		echo '<div class="panel panel-primary">';
			echo '<div class="panel-heading"><h3>Mostrando questões do tipo \''.$questoes[0]->getTipo().'\':</h3></div>';
			echo '<div class="list-group"> ';
			foreach ($questoes as $q) 
			{
			    echo '<a class="list-group-item" href="?action=mostrarQuestao&idQuestao='.$q->getId().'">'.$q->getId().' '.
		    	$q->getNomeMateria().' '.$q->getAno().' '.$q->getDificuldade().'</a>';
			}
			echo '</div>';
		echo '</div>';	
	}
	else if($flg == 5)
	{
		$_SESSION['materia'] = 3;
		echo '<div class="panel panel-primary">';
			echo '<div class="panel-heading"><h3>Mostrando questões de dificuldade \''.$questoes[0]->getDificuldade().'\':</h3></div>';
			echo '<div class="list-group"> ';
			foreach ($questoes as $q) 
			{
			    echo '<a class="list-group-item" href="?action=mostrarQuestao&idQuestao='.$q->getId().'">'.$q->getId().' '.
			    $q->getNomeMateria().' '.$q->getAno().' '.$q->getTipo().'</a>';
			}
			echo '</div>';
		echo '</div>';		
	}
	else if($flg == 6)
	{
		$_SESSION['materia'] = 4;
		echo '<div class="panel panel-primary">';
		if(isset($questoes[0]))
		{
			echo '<div class="panel-heading"><h3>Mostrando questões por ordem decrescente:</h3></div>';
			echo '<div class="list-group"> ';
			foreach ($questoes as $q) 
			{
			    echo '<a class="list-group-item" href="?action=mostrarQuestao&idQuestao='.$q->getId().'">'.$q->getId().' '.
			    $q->getNomeMateria().' '.$q->getAno().' '.$q->getTipo().' '.$q->getDificuldade().'</a>';
			}
			echo '</div>';
		}
		else
		{
			echo '<div class="panel-heading"><h3>Nenhuma questão foi inserida.</h3></div>';
			echo '<div class="list-group alert alert-danger" role="alert"> Por favor, faça o login ou cadastre-se (nos botões acima) 
			e ajude-nos sendo o primeiro a inserir uma questão! </div>';
		}
		echo '</div>';	
	}
	else if($flg == 7)
	{
		$_SESSION['materia'] = 5;
		echo '<div class="panel panel-primary">';
			if(isset($questoes[0]))
			{
				echo '<div class="panel-heading"><h3>Mostrando questões de sua autoria:</h3></div>';
				echo '<div class="list-group"> ';
				foreach ($questoes as $q) 
				{
				    echo '<a class="list-group-item" href="?action=mostrarQuestao&idQuestao='.$q->getId().'">'.$q->getId().' '.
				    $q->getNomeMateria().' '.$q->getAno().' '.$q->getTipo().' '.$q->getDificuldade().'</a>';
				    if(isset($_SESSION['usuario']))
				    {
				    	echo '<ol class="breadcrumb">';
				    		echo '<li><a href="?action=editarQuestao&idQuestao='.$q->getId().'">Editar</a>';
				    		echo '<li><a href="#" onclick="confirmar('.$q->getId().', '.$q->getMId().')">Apagar</a>';
				    	echo '</ol>';
				    }
				}
				echo '</div>';
			}
			else
			{
				echo '<div class="panel-heading"><h3>Você ainda não inseriu nenhuma questão.</h3></div>';
				echo '<div class="list-group alert alert-danger" role="alert"> Por favor, clique em "Exibir painel" e logo em seguida
				em "Inserir uma questão", e ajude-nos a ampliar a quantidade de questões! </div>';
			}
		echo '</div>';	
	}
include $_SERVER['DOCUMENT_ROOT'].'/trabalho_progweb/view/footer.php'; ?>