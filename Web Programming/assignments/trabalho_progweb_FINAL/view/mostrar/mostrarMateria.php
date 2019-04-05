<?php include $_SERVER['DOCUMENT_ROOT'].'/trabalho_progweb/view/header.php';
	# var_dump($_GET['idMateria']);	
	$m = new MateriaDAO();
	$materia = $m->search($_GET['idMateria']);
?>
		
<?php include $_SERVER['DOCUMENT_ROOT'].'/trabalho_progweb/view/footer.php' ?>