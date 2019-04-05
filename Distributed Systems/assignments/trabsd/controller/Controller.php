<?php
    include $_SERVER['DOCUMENT_ROOT'].'/trabsd/model/DBPDO.php';
    include $_SERVER['DOCUMENT_ROOT'].'/trabsd/model/UsuarioDAO.php';
    include $_SERVER['DOCUMENT_ROOT'].'/trabsd/model/ObjectFactory.php';
    include $_SERVER['DOCUMENT_ROOT'].'/trabsd/model/BucketFactory.php';
    class Controller
    {
        public function __construct()
        {
            session_start();
        }
        public function run()
        {
            $action = isset($_GET['action']) ? $_GET['action'] : 'index';
            switch ($action)
            {
                case 'index':
                    $this->indexAction();
                    break;
                case 'enviarArquivo':
                    $this->enviarArquivo();
                    break;
                case 'login':
                    $this->login();
                    break;
                case 'cadastro':
                    $this->cadastro();
                    break;
                case 'cadastrar':
                    $this->cadastrar();
                    break;
                case 'confirmarLogin':
                    $this->confirmarLogin();
                    break;
                case 'fazerLogoff':
                    $this->fazerLogoff();
                    break;
                case 'mostrarPainel':
                    $this->mostrarPainel();
                    break;
                 case 'mostrarSuperPainel':
                    $this->mostrarSuperPainel();
                    break;
                case 'deletarConta':
                    if(isset($_SESSION['usuario']))
                        $this->deletarConta();
                    break;
                case 'editarSenha':
                    if(isset($_SESSION['usuario']))
                        $this->editarSenha();
                    break;
                case 'editarSenhaDB':
                    $this->editarSenhaDB();
                    break;
                case 'baixarArquivo':
                    $this->baixarArquivo();
                    break;
                case 'verPasta':
                    $this->verPasta();
                    break;
                case 'renomearArquivo':
                    $this->renomearArquivo();
                    break;
                case 'criarPasta':
                    $this->criarPasta();
                    break;
                case 'excluirPasta':
                    $this->excluirPasta();
                    break;
                case 'excluirArquivo':
                    $this->excluirArquivo();
                    break;
                # not found TODO - não exibe imagem de fundo 
                default:
                    $this->notFound();
                    break;
            }
        }

        public function indexAction() 
        {
            require 'view/index.php';
        }

        public function carregarArquivo()
        {

			//TODO voltar para pag de listgem dos arquivos
      //      require 'view/mostrar/mostrarPainel.php';
        }

	public function enviarArquivo()
	{
 # if(dados foram lidos corretamente)
            $pref = $_GET['dir'];
            $target_dir =  $_SERVER['DOCUMENT_ROOT'].'/trabsd/upload/';
            $target_file = $target_dir . basename($_FILES["fileToUpload"]["name"]);
            $uploadOk = 1;
         //  $imageFileType = pathinfo($target_file,PATHINFO_EXTENSION);
            // Check if image file is a actual image or fake image
           
            
            // Check if file already exists
            //TODO S3
            
            // Check file size
            if ($_FILES["fileToUpload"]["size"] > 500000000) {
                echo "Sorry, your file is too large.";
                $uploadOk = 0;
            }
            
            
            // Check if $uploadOk is set to 0 by an error
            if ($uploadOk == 0) {
                echo "Sorry, your file was not uploaded.";
            // if everything is ok, try to upload file
            } else {
                if (move_uploaded_file($_FILES["fileToUpload"]["tmp_name"], $target_file)) {
                   //TODO  echo "The file ". basename( $_FILES["fileToUpload"]["name"]). " has been uploaded.";
                } else {
                    echo "Sorry, there was an error uploading your file.";
                }
            }
            
            
            
            
            
           // $parse = new Parser();
           // if($parse->getFile())
            //{
              //  $_SESSION['success'] = 1;
		//		$name = $_FILE['arquivo']['name'];
				$size = $_FILES['fileToUpload']['size']/1024;
		//		$items = 1;
                                
                                    
                                $bucket = new Bucket();
                                $bucket->setId($_SESSION['usuario']);
                                $buckets = new BucketFactory();
                                $bucket = $buckets->buscaBucket($bucket);

                                
				$file = new Object();
                                if($_GET['dir'] == '/')
                                {  
                                    $file->setName($_FILES["fileToUpload"]["name"]);
                                                                        
                                    $objects = $buckets->listar($bucket);
                                }
                                
                                
                                else{
                                    
                                
                                    $file->setName($pref.$_FILES["fileToUpload"]["name"]);
                                    
                                    
                                    $file->setPath($_GET['dir']);
                                    $pref = $_GET['dir'];
                                    $file->setBucket($bucket->getDbBucket());
                                

                                    $obj = new ObjectFactory();
                                    
                                    $objects = $obj->listar($file);
                                    
                                }
				$file->setSize($size);
                                $file->setBucket($bucket->getDbBucket());
                                $file->setPath($target_file);
				$objetos = new ObjectFactory();
				$objetos->inserir($file);	
                $user = new UsuarioDAO();
                $user->alterar($size, 0);
				//echo"deu certo lalalalal";
                //require 'view/consulta/realizarConsulta.php';   
							//TODO voltar para pag de listgem dos arquivos
	            require 'view/mostrar/mostrarPainel.php';

				//voltar para a pasta de upload
            //}
            //else # else require 'Conjunto de dados corrompidos ou inexistente'
            //{
              //  $_SESSION['success'] = 0;
                //require 'view/carregarArquivo/carregarArquivo.php';
           // }


	}

        public function login()
        {
            require 'view/mostrar/login.php';
        }

        public function cadastro()
        {
            require 'view/mostrar/cadastro.php';
        }

        public function cadastrar()
        {
            $password = $_POST['password'];
            $passcheck = $_POST['passwordcheck'];
            $user = $_POST['login'];
            if(strcmp($password, $passcheck) != 0)
            {
                $_GET['incorrect'] = 1;
                require 'view/mostrar/cadastro.php';
            }
            else
            {
                $usuario = new UsuarioDAO();
                // Retorna verdadeiro se há um login igual
                if($usuario->checar($user))
                {
                    $_GET['incorrect'] = 1;
                    require 'view/mostrar/cadastro.php';
                }
                else
                {
                    $arr = array ();
                    $arr[0] = $user;
                    $arr[1] = $password;
                    $arr[2] = uniqid($user, true);
                    $arr[3] = 0; // size used
                    if($usuario->insert($arr))
                    {
                        $_GET['signUp'] = 1;
			$bucket = new Bucket();
                        $bucket->setSize(0);
			$bucket->setId($user);
                        $bucket->setDbBucket($arr[2]);
			
			$buckets = new BucketFactory();
			$buckets->inserir($bucket);
                        require 'view/index.php';
                    }
                    else
                    {
                        $_GET['incorrect'] = 2;
                        require 'view/mostrar/cadastro.php';       
                    }
                }
            }

        }

       public function confirmarLogin()
        {
            $login = $_POST['login'];
            $password = $_POST['password'];
            if(isset($_SESSION['usuario']))
            {
                $_GET['logged'] = 1;
                require 'view/index.php';
            }
            $usuario = new UsuarioDAO();
            $user = $usuario->autenticar($login, $password);
            if($user)
            {
                $_GET['signIn'] = 1;
                $_SESSION['usuario'] = $user->getLogin();
                /* Indica que é superusuario */
                if($user->getUId() == 1)
                    $_SESSION['superuser'] = 1;
                $_SESSION['u_id'] = $user->getUId();
                $_SESSION['size'] = $user->getSize();
                require 'view/index.php';
            }
            else
            {
                $_GET['badPass'] = 1;
                require 'view/mostrar/login.php';
            }
        }

        public function fazerLogoff()
        {
            session_unset();
            session_destroy();
            require 'view/index.php';
        }

        public function mostrarPainel()
        {
	       $buckets = new BucketFactory();
            $bucket = new Bucket();
            $bucket->setId($_SESSION['usuario']);
            
            $bucket = $buckets->buscaBucket($bucket);
       
            $objects = $buckets->listar($bucket);
            $pref = '/';
          
             require 'view/mostrar/mostrarPainel.php';
        }
        
        public function mostrarSuperPainel()
        {
            $u = new UsuarioDAO();
            $users = $u->listar();
            require 'view/mostrar/mostrarSuperPainel.php';
        }

        public function deletarConta()
        {
            /* Antes de deletar a conta deve-se deletar todos os arquivo do bucket */
            $buckets = new BucketFactory();
            $bucket = new Bucket();
            $bucket->setId($_SESSION['usuario']);
            $bucket = $buckets->buscaBucket($bucket);
            $path = '/';
            /* Removendo de fato todos os itens */
            $buckets->deletar($bucket, $path);

            $user = $_GET['usuario'];
            if(isset($user))
            {   
                $usuario = new UsuarioDAO();
                $result = $usuario->remove($user);
                if($result == 1)
                {
                    $_GET['fimConta'] = 1;
                    $_SESSION['usuario'] = null;
                    $_SESSION['u_id'] = null;
                    require 'view/index.php';
                }
            }

            $_GET['fimConta'] = 1;
            require 'view/index.php';
        }

        public function editarSenha()
        {
            require 'view/edicao/editarSenha.php';
        }

        public function editarSenhaDB()
        {
            $senhaAtual = $_POST['password'];
            $novaSenha = $_POST['newPassword'];
            $confirmaSenha = $_POST['newPasswordCheck'];
            $usuario = new UsuarioDAO();
            $user = $usuario->autenticar($_SESSION['usuario'], $senhaAtual);
            if(!$user)
            {
                $_GET['incorrect'] = 1;
                require 'view/edicao/editarSenha.php';
            }
            else
            {
                if(strcmp($novaSenha, $confirmaSenha) != 0)
                {
                    $_GET['incorrect'] = 2;
                    require 'view/edicao/editarSenha.php';
                }
                else
                {
                    $result = $usuario->alter($novaSenha);
                    if($result == 1)
                    {
                        $_GET['updateSenha'] = 1;
                        require 'view/index.php';
                    }
                }
            }
        }

        public function baixarArquivo()
        {
			$file = new Object();
            if(isset($_GET['file']))
            {
			    $file->setName($_GET['file']);
                $file->setPath($_GET['dir']);
                $files = new ObjectFactory();
                $files->download($file);
            }
            else
                die("Arquivo não encontrado.");
           // require 'view/mostrar/baixarArquivo.php';
        }

        public function verPasta()
        {
            
            
	    $buckets = new BucketFactory();
            $bucket = new Bucket();
            $bucket->setId($_SESSION['usuario']);
            $bucket = $buckets->buscaBucket($bucket);
            

            $objeto = new Object();
            $objeto->setPath($_GET['dir']);
            $objeto->setBucket($bucket->getDbBucket());
            $objs = new ObjectFactory();
            $objects = $objs->listar($objeto);
			
			$pref = $_GET['dir'];
            if(isset($_GET['name']) && $_GET['name'] == 1)
                $_GET['name'] = 1;
            //$this->iterarPasta();
			require 'view/mostrar/mostrarPainel.php';
        }

        public function criarPasta()
        {
            $obj = new Object();
            $obj->setName($_GET['nome'].'/');
            $obj->setSize(0);
            $obj->setPath($_GET['dir']);
            
            $bucket = new Bucket();
            $buckets = new BucketFactory();
            $bucket->setId($_SESSION['usuario']);
            $bucket = $buckets->buscaBucket($bucket);
            $obj->setBucket($bucket->getDbBucket());
            if($_GET['dir']=='/' || $_GET['dir'] == '')
                $pref = '/';
            else
                $pref = $_GET['dir'];
            $objs = new ObjectFactory();
            $objs->inserirPasta($obj);
            
            $objects=$objs->listar($obj);
            require 'view/mostrar/mostrarPainel.php';
            
        }
        
         public function renomearArquivo()
        {
            $buckets = new BucketFactory();
            $bucket = new Bucket();
            $bucket->setId($_SESSION['usuario']);
            $bucket = $buckets->buscaBucket($bucket); 
             
            $objeto = new Object();
            $objeto->setBucket($bucket->getDbBucket());
            $objeto->setName($_GET['name']);
            $objs = new ObjectFactory();
            /* Identifica que é pasta */
            if(isset($_GET['dir']) && (/*strcmp($_GET['dir'], "/") == 0 ||*/ $_GET['name'][strlen($_GET['name'])-1] == "/"))
            {
                /* Indica que é a pasta raiz */
                if(strcmp($_GET['dir'], "/") == 0)
                    $objeto->setPath("");    
                else
                    $objeto->setPath($_GET['dir']);
                $aux = $objeto->getPath();
                $objs->alterar($objeto, true, $_GET['nome'], $_GET['name'], 0);
                $objeto->setPath($aux);
                $objs->borrar($objeto);
            }
            else
            {
                /* Indica que é a pasta raiz */
                if(strcmp($_GET['dir'], "/") == 0)
                    $objeto->setPath("");    
                else
                    $objeto->setPath($_GET['dir']);
                $objs->alterar($objeto, false, $_GET['nome'], $_GET['name'], 0);
            }
            
            
            
            
         $this->mostrarPainel();
          //  require 'view/index.php';
        }
        public function iterarPasta()
        {
            # TODO - entrar na pasta do S3
	    	/*$bucket = new Bucket();
	    	$bucket->setId($_SESSION['usuario']);
			$buckets = new BucketFactory();
			$buckets->lista($bucket);
            require 'view/mostrar/mostrarPainel.php';*/
        }

        public function excluirPasta()
        {
            $buckets = new BucketFactory();
            $bucket = new Bucket();
            $bucket->setId($_SESSION['usuario']);
            $bucket = $buckets->buscaBucket($bucket);
            $file = new Object();
            $file->setBucket($bucket->getDbBucket());
            $file->setPath($_GET['dir']);
            $file->setName($_GET['name']);
            $files = new ObjectFactory();
            $folderSize = $files->folderSize($file, 1)/1024;
            $files->borrar($file);
            $user = new UsuarioDAO();
            $user->alterar($folderSize, 1);
            $this->mostrarPainel();
            //require 'view/index.php';
        }

        public function excluirArquivo()
        {
            
            
            $buckets = new BucketFactory();
            $bucket = new Bucket();
            $bucket->setId($_SESSION['usuario']);
            $bucket = $buckets->buscaBucket($bucket);
            
            
            $file = new Object();
          //  $file->setName($_GET['arquivo']);
            $file->setBucket($bucket->getDbBucket());
            
            if(isset($_GET['dir']) && $_GET['dir']!='/' && $_GET['dir']!=''){
                $file->setName($_GET['dir'].$_GET['arquivo']);  
                $file->setPath($_GET['dir']);
                $pref = $_GET['dir'];
             //   echo "nao tem dir<br>";
                $files = new ObjectFactory();
                $folderSize = $files->folderSize($file, 0)/1024;
                $size = $files->remover($file);
                
                $objects = $files->listar($file);
                
            }
            else{
                $file->setName($_GET['arquivo']);
                $pref='/';
          
                
                $file->setPath($pref);
            
                $files = new ObjectFactory();
                $folderSize = $files->folderSize($file, 0)/1024;
                /*die($folderSize);*/
                $size = $files->remover($file);
            
                //$bucket = new Bucket();
                //$bucket->setId($_SESSION['usuario']);
                //$buckets = new BucketFactory();
                $objects = $buckets->listar($bucket);
                               
            } 
            $user = new UsuarioDAO();
            $user->alterar($folderSize, 1);  
          //  echo "esse é o prefixo: ".$pref."lalalla";
            
            
            require 'view/mostrar/mostrarPainel.php'; 
        }
        
        
        
        public function notFound()
        {
            require 'view/404/404.php';
        }
    }
?>
