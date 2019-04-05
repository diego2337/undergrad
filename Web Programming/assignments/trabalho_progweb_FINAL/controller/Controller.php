<?php
	require $_SERVER['DOCUMENT_ROOT'].'/trabalho_progweb/model/DBPDO.php';
	require $_SERVER['DOCUMENT_ROOT'].'/trabalho_progweb/model/MateriaDAO.php';
	require $_SERVER['DOCUMENT_ROOT'].'/trabalho_progweb/model/QuestaoDAO.php';
    require $_SERVER['DOCUMENT_ROOT'].'/trabalho_progweb/model/UsuarioDAO.php';
	class Controller
	{
		public function __construct()
		{
			session_start();
			$_SESSION['success'] = 0;
            $_SESSION['edit'] = 0;
            $_SESSION['remove'] = 0;
		}
		public function run()
		{
			$action = isset($_GET['action']) ? $_GET['action'] : 'index';
			switch ($action)
			{
				case 'index':
					$this->indexAction();
					break;
				case 'buscarQuestoes':
					$this->buscarQuestoes();
					break;
				case 'inserirQuestao':
                    if(isset($_SESSION['usuario']))
					   $this->inserirQuestao();
                    else
                        $this->indexAction();
					break;
				case 'inserirQuestaoDB':
					$this->inserirQuestaoDB();
					break;
				case 'mostrarMateria':
					$this->mostrarMateria();
					break;
				case 'mostrarQuestoes':
					$this->mostrarQuestoes();
					break;
				case 'mostrarQuestao':
					$this->mostrarQuestao();
					break;
                case 'editarQuestao':
                    if(isset($_SESSION['usuario']))
                        $this->editarQuestao();
                    else
                        $this->indexAction();
                    break;
                case 'editarQuestaoDB':
                    $this->editarQuestaoDB();
                    break;
                case 'apagarQuestao':
                    if(isset($_SESSION['usuario']))
                        $this->apagarQuestao();
                    else
                        $this->indexAction();
                    break;
                case 'apagarQuestaoDB':
                    $this->apagarQuestaoDB();
                    break;
                case 'buscarEMostrarQuestao':
                    $this->buscarEMostrarQuestao();
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
				default:
					$this->notFound();
					break;
			}
		}

        /* Esse método simplesmente invocará a página principal da aplicação */
		public function indexAction() 
		{
        	require 'view/index.php';
    	}

    	public function buscarQuestoes()
    	{
    
            $materias = array ();
            if(isset($_GET['busca']) && $_GET['busca'] == 1)
            {
                $m2 = new MateriaDAO();
                $materias = $m2->listar();
            }
            else if(isset($_GET['busca']) && $_GET['busca'] == 2)
            {
                $q2 = new QuestaoDAO();
                $questoes = $q2->searchHelper(0, 3);
            }
            else if(isset($_GET['busca']) && $_GET['busca'] == 3)
            {
                $q2 = new QuestaoDAO();
                $questoes = $q2->searchHelper(0, 8);
            }
            else if(isset($_GET['busca']) && $_GET['busca'] == 4)
            {
                $q2 = new QuestaoDAO();
                $questoes = $q2->searchHelper(0, 6);
            }
    		require 'view/busca/buscaQuestoes.php';
    	}

    	public function inserirQuestao()
    	{
            $materias = array ();
            $m2 = new MateriaDAO();
            $materias = $m2->listar();
    		require 'view/insere/insereQuestao.php';
    	}

    	public function inserirQuestaoDB()
    	{
    		$m_id = isset($_POST['m_id']) ? $_POST['m_id'] : 0;
            $u_id = isset($_SESSION['u_id']) ? $_SESSION['u_id'] : '---';
    		$dificuldade = isset($_POST['dificuldade']) ? $_POST['dificuldade'] : '---';
    		$tipo_questao = isset($_POST['tipoQuestao']) ? $_POST['tipoQuestao'] : '---';
    		$data = isset($_POST['data']) ? $_POST['data'] : 0000-00-00;
    		$enunciado = isset($_POST['enunciado']) ? $_POST['enunciado'] : '---';
    		$alternativas = isset($_POST['alternativas']) ? $_POST['alternativas'] : '---';
    		$resposta = isset($_POST['resposta']) ? $_POST['resposta'] : '---';
            $imagem = isset($_FILES['imagem']['tmp_name']) ? $_FILES['imagem']['tmp_name'] : null;
            $texto_alt = isset($_POST['texto_alt']) ? $_POST['texto_alt'] : null;
    		$questao = new Questao();

    		$questao->setMId($m_id);
            $questao->setUId($u_id);
    		$questao->setDificuldade($dificuldade);
    		$questao->setTipo($tipo_questao);
    		$questao->setAno($data);
    		$questao->setEnunciado($enunciado);
    		$questao->setAlternativas($alternativas);
    		$questao->setResposta($resposta);
            $questao->setImagem($imagem);
            $questao->setTextoAlt($texto_alt); 
    		$questaoDAO = new QuestaoDAO();
    		$success = $questaoDAO->insert($questao);
    		$_SESSION['success'] = $success;
    		require 'view/index.php';
    	}

    	public function mostrarMateria()
    	{
    		//require 'view/mostrar/mostrarMateria.php';
    	}

    	public function mostrarQuestoes()
    	{
            if(isset($_GET['idMateria']))
            {
                $m = $_GET['idMateria'];
                $flg = 0;
            }
            else if(isset($_GET['tipo_questao']))
            {
                $m = $_GET['tipo_questao'];
                $flg = 4;
            }
            else if(isset($_GET['dificuldade']))
            {
                $m = $_GET['dificuldade'];
                $flg = 5;
            }
            else if(isset($_GET['busca']))
            {
                $m = 0;
                $flg = 6;
            }
            else if(isset($_GET['porUsuario']))
            {
                $m = $_GET['porUsuario'];
                $flg = 7;
            }
            $q2 = new QuestaoDAO();
            $questoes = array ();
            $questoes = $q2->searchHelper($m, $flg);
    		require 'view/mostrar/mostrarQuestoes.php';
    	}

    	public function mostrarQuestao()
    	{
            $m = $_GET['idQuestao'];
            $q2 = new QuestaoDAO();
            $questoes = array ();
            /* Aqui, sabemos que somente uma tupla foi recuperada, portanto sempre iremos referenciá-la através da posição [0]
            do array */
            $questoes = $q2->searchHelper($m, 1);
			require 'view/mostrar/mostrarQuestao.php';    		
    	}

        public function editarQuestao()
        {
            $m = $_GET['idQuestao'];
            $q2 = new QuestaoDAO();
            $questoes = array ();
            $questoes = $q2->searchHelper($m, 1);
            $materias = array ();
            $m2 = new MateriaDAO();
            $materias = $m2->listar();

            require 'view/edicao/editarQuestao.php';
        }

        public function editarQuestaoDB()
        {
            $q_id = isset($_POST['q_id']) ? $_POST['q_id'] : 0;
            $m_id = isset($_POST['m_id']) ? $_POST['m_id'] : 0;
            $dificuldade = isset($_POST['dificuldade']) ? $_POST['dificuldade'] : '---';
            $tipo_questao = isset($_POST['tipoQuestao']) ? $_POST['tipoQuestao'] : '---';
            $data = isset($_POST['data']) ? $_POST['data'] : 0000-00-00;
            $enunciado = isset($_POST['enunciado']) ? $_POST['enunciado'] : '---';
            $alternativas = isset($_POST['alternativas']) ? $_POST['alternativas'] : '---';
            $resposta = isset($_POST['resposta']) ? $_POST['resposta'] : '---';
            $imagem = $_POST['imagemOriginal'] != "" ? $_POST['imagemOriginal'] : null;
            $texto_alt = isset($_POST['texto_alt']) ? $_POST['texto_alt'] : null;
            $questao = new Questao();

            $questao->setId($q_id);
            $questao->setMId($m_id);
            $questao->setDificuldade($dificuldade);
            $questao->setTipo($tipo_questao);
            $questao->setAno($data);
            $questao->setEnunciado($enunciado);
            $questao->setAlternativas($alternativas);
            $questao->setResposta($resposta);
            $questao->setImagem($imagem);
            $questao->setTextoAlt($texto_alt);

            $questaoDAO = new QuestaoDAO();
            $success = $questaoDAO->alter($questao, $_POST['mudar']);
            $_SESSION['edit'] = $success;
            require 'view/index.php';
        }

        public function apagarQuestao()
        {
            //require 'view/mostrar/confirmacao.php';
        }

        public function apagarQuestaoDB()
        {
            $q_id = $_GET['idQuestao'];
            $m_id = $_GET['idMateria'];
            $questaoDAO = new QuestaoDAO();
            $success = $questaoDAO->remove($q_id);
            $_SESSION['remove'] = $success;
            require 'view/index.php';
        }

        public function buscarEMostrarQuestao()
        {
            $anterior = $_GET['anterior'];
            // $i = $_GET['idQuestao'];
            // $t = $_GET['tipo_questao'];
            // $m = $_GET['idMateria'];
            // $d = $_GET['dificuldade'];
            $types = array ();
            $types[0] = $_GET['idQuestao'];
            $types[1] = $_GET['tipo_questao'];
            $types[2] = $_GET['idMateria'];
            $types[3] = $_GET['dificuldade'];
            $q2 = new QuestaoDAO();
            $questoes = array ();
            if(isset($_SESSION['materia']) && $_SESSION['materia'] == 1)
            {
                if($anterior == 0)
                {
                    $questoes = $q2->searchHelper($types, 9);
                }
                else
                {
                    $questoes = $q2->searchHelper($types, 10);   
                }
            }
            else if(isset($_SESSION['materia']) && $_SESSION['materia'] == 2)
            {
                if($anterior == 0)
                {
                    $questoes = $q2->searchHelper($types, 11);
                }
                else
                {
                    $questoes = $q2->searchHelper($types, 12);
                }
            }
            else if(isset($_SESSION['materia']) && $_SESSION['materia'] == 3)
            {
                if($anterior == 0)
                {
                    $questoes = $q2->searchHelper($types, 13);
                }
                else
                {
                    $questoes = $q2->searchHelper($types, 14);
                }
            }
            else if(isset($_SESSION['materia']) && $_SESSION['materia'] == 4)
            {
                if($anterior == 0)
                {
                    $questoes = $q2->searchHelper($types, 15);
                }
                else
                {
                    $questoes = $q2->searchHelper($types, 16);
                }
            }
            else if(isset($_SESSION['materia']) && $_SESSION['materia'] == 5)
            {
                if($anterior == 0)
                {
                    $questoes = $q2->searchHelper($types, 17);
                }
                else
                {
                    $questoes = $q2->searchHelper($types, 18);
                }
            }
            if(empty($questoes))
            {
                if($_SESSION['materia'] == 1 || isset($_SESSION['usuario']))
                    $_GET['busca'] = 1;
                else if($_SESSION['materia'] == 2)
                    $_GET['busca'] = 2;
                else
                    $_GET['busca'] = 3;
                $this->buscarQuestoes();
            }
            else
                require 'view/mostrar/mostrarQuestao.php';
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
                    if($usuario->insert($arr))
                    {
                        $_GET['signIn'] = 1;
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
            $usuario = new UsuarioDAO();
            $user = $usuario->autenticar($login, $password);
            if($user)
            {
                $_SESSION['usuario'] = $user->getLogin();
                $_SESSION['u_id'] = $user->getUId();
                require 'view/index.php';
            }
            else
            {
                $_GET['incorrect'] = 1;
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
            require 'view/mostrar/mostrarPainel.php';
        }

        public function deletarConta()
        {
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

    	public function notFound()
    	{
    		require 'view/404/404.php';
    	}
	}
?>