<?php
    class Controller
    {
        public function __construct()
        {
            session_start();
        }
        
        public function run()
        {
            $action = isset($_GET['action']) ? $_GET['action'] : 'index';
            switch($action)
            {
                case 'index':
                    $this->indexAction();
                    break;
                case 'mostrar':
                    $this->mostrar();
                    break;
                case 'mostrarCaes':
                    $this->mostrarCaes();
                    break;
                case 'mostrarGatos':
                    $this->mostrarGatos();
                    break;
                case 'mostrarAves':
                    $this->mostrarAves();
                    break;
                case 'mostrarOutros':
                    $this->mostrarOutros();
                    break;
                case 'mostrarAnimal':
                    $this->mostrarAnimal();
                    break;
                case 'cadastrar':
                    $this->cadastrar();
                    break;
                case 'cadastroBD':
                    $this->cadastroBD();
                    break;
                case 'inserirAnimal':
                    $this->inserirAnimal();
                    break;
                case 'insereAnimalBD':
                    $this->insereAnimalBD();
                    break;
                case 'animaisCadastrados':
                    $this->animaisCadastrados();
                    break;
                default:
                    $this->notFound();
                    break;
            }
        }
        
        public function indexAction()
        {
            /* Estático */
            $_SESSION['d_id'] = null;
            require 'view/index.php';
        }
        
        public function mostrar()
        {
            require 'view/mostrar/mostrar.php';
        }
        
        public function mostrarCaes()
        {
            require 'view/mostrar/mostrarCaes.php';
        }
        
        public function mostrarGatos()
        {
            require 'view/mostrar/mostrarGatos.php';
        }
        
        public function mostrarAves()
        {
            require 'view/mostrar/mostrarAves.php';
        }
        
        public function mostrarOutros()
        {
            require 'view/mostrar/mostrarOutros.php';
        }
        
        public function mostrarAnimal()
        {
            require 'view/mostrar/mostrarAnimal.php';
        }
        
        public function cadastrar()
        {
            require 'view/cadastrar.php';
        }
        
        public function cadastroBD()
        {
            /* Dados estáticos */
            $_SESSION['d_id'] = 1;
            require 'view/index.php';
        }
        
        public function inserirAnimal()
        {
            require 'view/inserir/inserirAnimal.php';
        }
        
        public function insereAnimalBD()
        {
            /* Dados estáticos */
            $_SESSION['d_id'] = 1;
            $this->animaisCadastrados();
        }
        
        public function animaisCadastrados()
        {
             require 'view/mostrar/animaisCadastrados.php';
        }
        
        public function notFound()
        {
            require 'view/404.php';
        }
    }
?>