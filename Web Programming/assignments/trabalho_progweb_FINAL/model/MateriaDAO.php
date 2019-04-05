<?php
	include 'Materia.php';
	class MateriaDAO extends DBPDO
	{
		public function __construct()
		{
			parent::__construct();
		}
		public function __destruct()
		{
			parent::__destruct();
		}
		public function listar()
		{
			$statement = $this->db->prepare("SELECT * FROM Materia ORDER BY nomeMateria");
			$statement->execute();
			$materias = array ();
			while($m = $statement->fetchObject())
			{
				$materia = new Materia();
				$materia->setId($m->m_id);
				$materia->setNomeMateria(utf8_encode($m->nomeMateria));
				$materia->setDescricao(utf8_encode($m->descricao));
				$materias[] = $materia;
			}
			return $materias;
		}
		public function search($element)
		{
			try
			{
				if(isset($element))
				{
					$statement = $this->db->prepare("SELECT :element FROM Materia WHERE m_id=:element");
				}
				$statement->bindParam(":element", $element);
				$statement->execute();
				if($m = $statement->fetchObject())
				{
					$materia = new Materia();
					$materia->setId($m->m_id);
					$materia->setNomeMateria($m->nomeMateria);	
					$materia->setDescricao($m->descricao);
				}
				return $materia;
				/*else
					$statement = $this->db->prepare("SELECT * FROM Materia");
				$statement->bindParam(":element", $element);
				$statement->execute();
				while($m = $statement->fetchObject())
				{
					$materia = new Materia();
					$materia->setId($m->m_id);
					$materia->setNomeMateria($m->nomeMateria);
					$materias[] = $materia;
				}
				return $materias;*/
			}
			catch (Exception $exc) 
			{
            	echo $exc->getTraceAsString();
        	}
		}
		/* Esses métodos não foram implementados pois suas funcionalidades não são requistadas para a aplicação */
		public function insert($element)
		{

		}
		public function alter($element)
		{

		}
		public function remove($element)
		{

		}
	}
?>