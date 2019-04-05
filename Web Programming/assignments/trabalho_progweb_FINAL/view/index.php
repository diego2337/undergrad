<!DOCTYPE html>
<html>

    <?php 
        include 'header.php';  
        if(isset($_SESSION['success']) && $_SESSION['success'] == 1)
        {
            include 'success.php';   
        }
        else if(isset($_SESSION['edit']) && $_SESSION['edit'] == 1)
        {
            echo '<div class="alert alert-success" role="alert">A questão foi alterada com sucesso.</div>';
        }
        else if(isset($_SESSION['remove']) && $_SESSION['remove'] == 1)
        {
            echo '<div class="alert alert-success" role="alert">A questão foi removida com sucesso.</div>';
        }
        else if(isset($_GET['signIn']))
        {
            echo '<div class="alert alert-success" role="alert">Você se cadastrou com sucesso.</div>';   
        }
        else if(isset($_GET['fimConta']))
        {
            echo '<div class="alert alert-success" role="alert">A conta foi excluída. Todas as questões associadas a ela foram
            removidas.</div>';
        }
        else if(isset($_GET['updateSenha']))
        {
            echo '<div class="alert alert-success" role="alert">A senha foi alterada com sucesso.</div>';   
        }
        /* Essa posição de "session" será responsável por manipular a progressão das questões ao entrarmos no arquivo "mostrarQuestao.php */
        $_SESSION['materia'] = 1;
    ?>
        <div class="panel panel-info">
                <p>Seja muito bem-vindo. Esse pequeno sistema tem como finalidade facilitar a busca por questões relacionadas à 
                	computação, seja de concursos, questões aplicadas no âmbito acadêmico ou até mesmo aquelas para ingresso 
                	no mestrado em território nacional (POSCOMP). Não obstante, você, caso queira, pode colaborar com o site,
                	inserindo as suas próprias questões. Fique à vontade!</p>

        </div>

    <?php include 'footer.php'; ?>
    </div>
    </body>
</html>