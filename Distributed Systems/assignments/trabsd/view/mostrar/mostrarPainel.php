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
                        
                        function getFile(){
                  document.getElementById("upfile").click();
                }
                function sub(obj){
                   var file = obj.value;
                   var fileName = file.split("\\");
                   document.getElementById("upbuttom").innerHTML = fileName[fileName.length-1];
                   document.myForm.submit();
                   event.preventDefault();
                 }
                      
                function criarPasta(dir) {
                    var person = prompt("Digite o nome da sua nova pasta", "");

                    if (person != null) {
                        window.location.href = "?action=criarPasta&nome="+person+"&dir="+dir;
                    }
                }
                function renomearArquivo(dir, name) 
                {
                  var person = prompt("Digite o novo nome da sua pasta/arquivo", "");

                  if (person != null) 
                  {
                    window.location.href = "?action=renomearArquivo&nome="+person+"&dir="+dir+"&name="+name;
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
							Arquivos
						</div>
						<div class="pipi_right little-space">
                                                    
                                                    <form action="?action=enviarArquivo&dir=<?php echo $pref; ?>" method="POST" enctype="multipart/form-data" name="myForm">
                                                      <!--    <div id="yourBtn" style="height: 50px; width: 100px;border: 1px dashed #BBB; cursor:pointer;" onclick="getFile()">Click to upload!</div> -->
                                                        <span class="glyphicon glyphicon-floppy-open little_space" id="upbuttom" onclick="getFile()" style="cursor: pointer;" title="Enviar arquivo"></span>                 
                                                        <!-- this is your file input tag, so i hide it!-->
                                                        
                                                        <div style='height: 0px;width: 0px; overflow:hidden; cursor: hand;'><input style="cursor: hand;" id="upfile" type="file" name="fileToUpload" onchange="sub(this)"/></div>
                                                        <!-- here you can have file submit button or you can write a simple script to upload the file automatically-->
                                                        <?php
                                                        
                                                        /* Aqui, trata-se o caso em que queremos retornar um nível acima */
                                                        if($pref != '')
                                                        {
                                                          $previous_dir = '';
                                                          $tok = strtok($pref,"/");
                                                          $prev = $tok;
                                                          $tok = strtok("/");
                                                          while ($tok !== false) 
                                                          {
                                                              $previous_dir = $previous_dir.$prev;
                                                              $prev = "/".$tok;
                                                              $tok = strtok("/");
                                                          }
                                                          $previous_dir = $previous_dir."/";
                                                          if(strcmp($previous_dir, "/") == 0)
                                                          {
                                                            echo '<a href="?action=mostrarPainel&usuario='.$_SESSION['u_id'].'" title="Um nível acima">
                                                            <span class="glyphicon glyphicon-eject little_space margin_down" id="oneFolderUp"></span></a>';  
                                                          }
                                                          else
                                                          {
                                                            echo '<a href="?action=verPasta&usuario='.$_SESSION['u_id'].'&dir='.$previous_dir.'" title="Um nível acima">
                                                            <span class="glyphicon glyphicon-eject little_space margin_down" id="oneFolderUp"></span></a>';
                                                          }
                                                        }
                                                        ?>
                                                        
                                                        
                                                    </form>
						<!--	<a href=" " title="Enviar arquivo"><span class="glyphicon glyphicon-floppy-open little_space"></span></a> -->
						</div>
						<div class="pipi_right">
						<a href="#" onclick="criarPasta('<?php if($pref == '/') echo ''; else  echo $pref; ?>')">	<span title="Criar nova pasta"  class="glyphicon glyphicon-folder-close little_space"></span></a>
						</div>
					</div>
					<div class="panel panel-info panel-body">
						<table class="table browsefile">
							<tr>
							    <th><!--a href="?action=ordenarPorNome&usuario=<?php echo $_SESSION['u_id']?>&path=<?php echo $pref?>">-->Nome<!--</a>--></th>
							    <th><!--<a href="?action=ordenarPorTipo&usuario=<?php echo $_SESSION['u_id'] ?>">-->Tipo<!--</a>--></th>
							    <th><!--<a href="?action=ordenarPorData&usuario=<?php echo $_SESSION['u_id'] ?>">-->Atualizado em<!--</a>--></th>
							    <th>Opções</th>
							</tr>
							<!-- TODO - buscar todos os arquivos contidos no s3 -->
                                                        
                                                        
                                                        
                                                        <?php 
                                                            foreach($objects as $object)
                                                            {
                                                                     // print_r($object);
                                                                      
                                                                 // die();                                     
                                                                if($pref != '')
                                                                {  //echo "objeto1: ".$object['Key'] ."     ";
                                                                  //echo $pref;
                                                                    if (isset($object['Prefix'])) 
                                                                    {
                                                           // For Common Prefixes
                                                                  //     echo 'oi'. $object['Prefix']; 
                                                                    // $exp = explode($pref, $object['Prefix']);
                                                                      $object['Key'] = $object['Prefix'];
                                                                      $object['Size'] = 0;
                                                                      $object['LastModified'] = '';

                                                                    } /*else {
                                                                       echo 'oi'. $object['Key'].'para'; 
                                                                       echo $pref;
                                                                       // For Objects
                                                                        //$exp = explode($pref, $object['Key']);
                                                                                                                             
                                                                     
                                                                        /* Se exp tiver mais que 2 elementos entao eh pasta com
                                                                         * mesmo nome
                                                                         * Se posicao 0 for vazia assumo como subpasta
                                                                         * Else eh raiz
                                                                         * Na hora de exibir os icones verificar se existe barra  
                                                                        * no nome do objeto
                                                                         * 
                                                                       
                                                                   }     */

                                                                }
                                                                
                                                                
                                                                
                                                              $exp = explode($pref, $object['Key']);
                                                             //   $exp = explode('aaa/', $object['Key']);
                                                              //print_r($exp);
                                                              $size = sizeof($exp);
                                                            
                                                             if(isset($exp[0]) && $exp[0]!='' ) //raiz
                                                             {
                                                                 
                                                                 $object['Key'] = $exp[0];
                                                                 if($object['Size'] == 0)
                                                                     $object['Key'] = $object['Key'].'/';
                                                                    $path = $object['Key'];
                                                                    $dir = '';
                                                             }
                                                             else //subpasta
                                                             {
                                                                if(isset($exp[1]) && $exp[1]!='') 
                                                                  $object['Key'] = $exp[1];
                                                                
                                                                else if(sizeof($exp) > 2)
                                                                  $object['Key'] = $pref;
                                                              else {
                                                                   $object['Key'] = '';
                                                                }
                                                                $path = $_GET['dir'].$object['Key'];
                                                                $dir = $_GET['dir'];
                                                             }
                                                                
                                                                
                                                                
                                                                
                                                    
                                                                if( $object['Key'] != '') 
                                                                {
                                                               // echo count($exp);
                                                               
                                                                    if($object['Size']>0) {
                                                                        echo'<tr><td><a href="?action=baixarArquivo&usuario='.$_SESSION['u_id'].'&file='.$object['Key'].'&dir='.$pref.'" title="Baixar arquivo">'; 

                                                                        echo '<span class="glyphicon glyphicon-file little_space"></span>';     
                                                                    }
                                                                    else{
                                                                        echo'<tr><td><a href="?action=verPasta&usuario='.$_SESSION['u_id'].'&dir='.$path.'" title="Explorar pasta">'; 
                                                                        echo '<span class="glyphicon glyphicon-folder-open little_space"></span> ';
                                                                    }
                                                                    echo '<span>'.$object['Key'].'</span>
                                                                            </a>
                                                                         </td>
                                                                         <td>';
                                                                    if($object['Size']>0) 
                                                                    {        
                                                                             
                                                                          echo 'arquivo </td> <td> '.date("H:i d M, Y",strtotime($object['LastModified'])).'</td>                                      
                                                                      
                                                                    <td>
                                                                            
                                                                            <a href="?action=baixarArquivo&usuario='.$_SESSION['u_id'].'&file='.$object['Key'].'&dir='.$pref.'" title="Baixar arquivo"><span class="glyphicon glyphicon-hdd little_space"></span></a>
                                                                            <a href="?action=excluirArquivo&arquivo='.$object['Key'].'&dir='.$dir.'" title="Excluir arquivo"><span class="glyphicon glyphicon-trash little_space"></span></a>
                                                                            <a href="#" onclick="renomearArquivo(\''.$pref.'\', \''.$object['Key'].'\')" title="Renomear arquivo"><span class="glyphicon glyphicon-pencil little_space"></span></a>
                                                                    </td>';


                                                                    }
                                                                    else
                                                                        echo 'pasta </td> <td> '.$object['LastModified'].'</td>
    <td>
                                                                            <a href="?action=excluirPasta&dir='.$dir.'&name='.$object['Key'].'" title="Excluir pasta"><span class="glyphicon glyphicon-trash little_space"></span></a>
                                                                            <a href="#" onclick="renomearArquivo(\''.$pref.'\', \''.$object['Key'].'\')" title="Renomear pasta"><span class="glyphicon glyphicon-pencil little_space"></span></a>
                                                                    </td>';
                                                                        echo '</tr>';
                                                                }
                                                            }
                                                            ?>
													</table> 
					</div>
				</div>
			</div>
		</div>
<?php include $_SERVER['DOCUMENT_ROOT'].'/trabsd/view/footer.php' ?>
