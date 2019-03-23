<?php 

    include('view/header.php');

    foreach ($ataques as $ataque) {
        $nome = $ataque->getNome();
        $tipo = $ataque->getTipo();
        $quantidade = $ataque->getQuantidade();
        $poder = $ataque->getPoder();
        $precisao = $ataque->getPrecisao();
        $uso = $ataque->getUso_fora_batalha();
        $efeito = $ataque->getEfeito();
        
    }
    
    $tipos = array("Agua" => "Água", "Fogo" => "Fogo",  "Planta" => "Planta", 
        "Psiquico" => "Psiquico", "Gelo"=>"Gelo", "Dragao" => "Dragão", "Inseto" => "Inseto");
    
    $usos = array("1"=>"Sim", "0"=>"Não");

?>

<div class="form2">
    <div class="lerge-form">
        <form class="form-horizontal" action="?action=editAtaqueDB" method="POST">
            <legend>Editar ataque: <?php echo $nome ?> </legend>
            <input  name="nome" class="form-control" type="hidden" id="nome" value="<?php echo $nome  ?>"  >

            <label>Tipo:</label>
            <select class="form-control" id="tipo" name="tipo">
                <?php 
                foreach ($tipos as $t => $t_value) {
                    if($tipo == $t_value) {
                        echo '<option selected="selected" value='.$t.'>'.$t_value.'</option>';
                    } else {
                        echo '<option value='.$t.'>'.$t_value.'</option>';
                    }
                }
                ?>
            </select>
            <label >Poder:  </label>

            <input class="form-control" type="text" placeholder="" name="poder" value="<?php echo $poder  ?>">
            <label >Precisão:  </label>

            <input class="form-control" type="text" placeholder="" name="precisao" value="<?php echo $precisao  ?>">


            <label>Quantidade (PP):</label>

            <input class="form-control" type="text" placeholder="" name="quantidade" value="<?php echo $quantidade  ?>">


            <label>Efeito:</label>
            <textarea class="form-control" rows="3" name="efeito" > <?php echo $efeito ?> </textarea>

            <label> Uso fora da batalha?</label>
            <select class="form-control" name="uso_fora_batalha">
               <?php foreach ($usos as $u => $u_value) {
                        if($uso == $u){
                        echo '<option selected="selected" value='.$u.'>'.$u_value.'</option>'; 
                        }
                        else {
                            echo '<option value='.$u.'>'.$u_value.'</option>';
                        }
                    } 
                ?>
            </select>

            <label> <button type="submit" class="btn">Enviar!</button> </label>
        </form>
    </div>
</div>

<?php include 'view/footer.php'; ?>