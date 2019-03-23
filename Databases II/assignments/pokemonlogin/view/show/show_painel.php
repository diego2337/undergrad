<!-- <!DOCTYPE html> -->
<html>

    <?php include('view/header.php'); ?>

     <body>
            <?php foreach ($treinadores as $tre):
                    $id = $tre->getId();
                    $nome = $tre->getNome();
                    $insignas = $tre->getNum_insignas();
                    $capturados = $tre->getQtd_pokemons_capturados();
                    $vistos = $tre->getQtd_pokemons_vistos();
                    $sexo = $tre->getSexo();
                    $login = $tre->getLogin();
                    
                endforeach;
            ?>
         
   <?php foreach ($treinadores as $tre):?>
        <div class="form2">
            <legend>Bem-vindo(a) <?php echo $tre->getNome(); ?></legend>
            <legend><a href="?action=verMeusPokemons">Meus pokemons</a></legend>
            <legend><a href="?action=listarCaptura">Capturar pokemons</a></legend>
            <legend><a href="?action=verMeusItens">Meus itens</a></legend>
            <legend><a href="?action=adicionarTreinadorItem">Adicionar novos itens</a></legend>
            <legend><a href="?action=alterarSenha">Alterar Senha</a></legend>
       
         
  <?php endforeach;
            ?>
       </div>                 
        <?php include ('view/footer.php') ?>