<?php include $_SERVER['DOCUMENT_ROOT'].'/trabalho_progweb/view/header.php' ?>

    <ul class="nav nav-tabs" role="tablist">
        <li><a href="?action=buscarQuestoes&busca=1">Matérias</a></li>
        <li><a href="?action=buscarQuestoes&busca=2">Área</a></li>
        <li><a href="?action=buscarQuestoes&busca=3">Dificuldade</a></li>
        <li><a href="?action=mostrarQuestoes&busca=4">Novas</a></li>
        <?php if(isset($_SESSION['usuario']))
                echo '<li><a href="?action=mostrarQuestoes&porUsuario='.$_SESSION['u_id'].'">Minhas Questões</a></li>' ?>
    </ul>
    <?php
        if(isset($_GET['busca']) && $_GET['busca'] == 1)
        {
            $question = new QuestaoDAO();
        	echo '<div class="form">';
                echo '<legend>Busque por matéria</legend>';
                        foreach ($materias as $m) 
                        {
                            echo '<div class="panel panel-success"> ';
                                echo '<div class="panel-heading">';
                                    echo '<a href="?action=mostrarQuestoes&idMateria='.$m->getId().'">'.$m->getNomeMateria().'</a>';
                                echo '</div>';
                                echo '<div class="panel-body">';
                                    echo $m->getDescricao() . '<br>';
                                    echo 'Número de questões: ' . $question->countNumQuestoes($m->getId(), 0);
                                echo '</div>';
                            echo '</div>';
                        }
            echo '</div>';
        }
        else if(isset($_GET['busca']) && $_GET['busca'] == 2)
        {
            $question = new QuestaoDAO();
            echo '<div class="form">';
                echo '<legend>Busque por área</legend>';
                        foreach ($questoes as $q) 
                        {
                            echo '<div class="panel panel-warning"> ';
                                echo '<div class="panel-heading">';
                                    echo '<a href="?action=mostrarQuestoes&tipo_questao='.$q->getTipo().'">'.$q->getTipo().'</a>';
                                echo '</div>';
                                echo '<div class="panel-body">';
                                    echo 'Número de questões: ' . $question->countNumQuestoes($q->getTipo(), 1);
                                echo '</div>';
                            echo '</div>';
                        }
            echo '</div>';
        }
        else if(isset($_GET['busca']) && $_GET['busca'] == 3)
        {
            $question = new QuestaoDAO();
            echo '<div class="form">';
                echo '<legend>Busque por dificuldade</legend>';
                        foreach ($questoes as $q) 
                        {
                            echo '<div class="panel panel-danger"> ';
                                echo '<div class="panel-heading">';
                                    echo '<a href="?action=mostrarQuestoes&dificuldade='.$q->getDificuldade().'">'
                                    .$q->getDificuldade().'</a>';
                                echo '</div>';
                                echo '<div class="panel-body">';
                                    echo 'Número de questões: ' . $question->countNumQuestoes($q->getDificuldade(), 2);
                                echo '</div>';
                            echo '</div>';
                        }
            echo '</div>';
        }
    ?>

<?php include $_SERVER['DOCUMENT_ROOT'].'/trabalho_progweb/view/footer.php' ?>