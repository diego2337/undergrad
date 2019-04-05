<?php
	class Materia
	{
		private $m_id;
		private $nomeMateria;
		private $numQuestoes;
		private $descricao;
		public function __construct()
		{
			;
		}
		public function getId()
		{
			return $this->q_id;
		}
		public function setId($id)
		{
			$this->q_id = $id;
		}
		public function getNomeMateria()
		{
			return $this->nomeMateria;
		}
		public function setNomeMateria($m)
		{
			$this->nomeMateria = $m;
		}
		public function getNumQuestoes()
		{
			return $this->numQuestoes;
		}
		public function setNumQuestoes($n)
		{
			$this->numQuestoes = $n;
		}
		public function getDescricao()
		{
			return $this->descricao;
		}
		public function setDescricao($d)
		{
			$this->descricao = $d;
		}
	}
?>