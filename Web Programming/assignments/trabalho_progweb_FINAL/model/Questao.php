<?php
	class Questao
	{
		private $q_id;
		private $m_id;
		private $u_id;
		private $dificuldade;
		private $enunciado;
		private $alternativas;
		private $resposta;
		private $ano;
		private $tipo;
		private $textoAlt;
		private $uLogin;
		// Atributos exclusivos que não são manipulados no banco de dados
		private $nomeMateria;
		private $imagem;
		function __construct()
		{

		}
		public function getId()
		{
			return $this->q_id;
		}
		public function setId($id)
		{
			$this->q_id = $id;
		}
		public function getMId()
		{
			return $this->m_id;
		}
		public function setMId($id)
		{
			$this->m_id = $id;
		}
		public function getUId()
		{
			return $this->u_id;
		}
		public function setUId($id)
		{
			$this->u_id = $id;
		}
		public function getDificuldade()
		{
			return $this->dificuldade;
		}
		public function setDificuldade($d)
		{
			$this->dificuldade = $d;
		}
		public function getEnunciado()
		{
			return $this->enunciado;
		}
		public function setEnunciado($e)
		{
			$this->enunciado = $e;
		}
		public function getAlternativas()
		{
			return $this->alternativas;
		}
		public function setAlternativas($alter)
		{
			$this->alternativas = $alter;
		}
		public function getResposta()
		{
			return $this->resposta;
		}
		public function setResposta($r)
		{
			$this->resposta = $r;
		}
		public function getAno()
		{
			return $this->ano;
		}
		public function setAno($a)
		{
			$this->ano = $a;
		}
		public function getTipo()
		{
			return $this->tipo;
		}
		public function setTipo($t)
		{
			$this->tipo = $t;
		}
		public function getNomeMateria()
		{
			return $this->materia;
		}
		public function setNomeMateria($m)
		{
			$this->materia = $m;
		}
		public function getImagem()
		{
			return $this->imagem;
		}
		public function setImagem($img)
		{
			$this->imagem = $img;
		}
		public function getULogin()
		{
			return $this->uLogin;
		}
		public function setULogin($uLogin)
		{
			$this->uLogin = $uLogin;
		}
		public function getTextoAlt()
		{
			return $this->textoAlt;
		}
		public function setTextoAlt($texto)
		{
			$this->textoAlt = $texto;
		}
	}
?>