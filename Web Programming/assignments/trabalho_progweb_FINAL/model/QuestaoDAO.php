<?php
	include 'Questao.php';
	class QuestaoDAO extends DBPDO
	{
		public function __construct()
		{
			parent::__construct();
		}
		public function __destruct()
		{
			parent::__destruct();
		}
		/**
		* @author Roberto Oliveira <rco.ufms@gmail.com>
		*/
		function copiarImagem($arquivo, $caminho)
    	{	
    		$nome_arquivo = $arquivo['name'];
			$pos = strpos($nome_arquivo, '.');
			$nome_sem_ext = substr($nome_arquivo, 0, $pos);
        	$lower = strtolower($nome_sem_ext);
        	$ext = substr($nome_arquivo, $pos, strlen($nome_arquivo));
        	$name = $lower.date('YmdHis').rand().$ext;
        	$destino = $caminho.$name;
			if(!move_uploaded_file($arquivo['tmp_name'],$destino))
        	{
        		echo 'Erro';
              	return false;
    	    }
    	    else
	        	return $destino;
    	}
    	/* Aqui retornaremos a quantidade de questões de uma determinada dificuldade ou área */
    	public function countNumQuestoes($element, $tipo)
    	{
    		/* Busca a quantidade de questões de uma determinada matéria */
    		if($tipo == 0)
    		{
    			$statement = $this->db->prepare("SELECT Questao.m_id FROM Questao WHERE Questao.m_id=:e0");
    		}
    		else if($tipo == 1) /* Busca a quantidade de questões de um determinado tipo */
    		{
    			$statement = $this->db->prepare("SELECT Questao.m_id FROM Questao WHERE Questao.tipo_questao=:e0");
    		}
    		else if($tipo == 2) /* Busca a quantidade de questões de uma determinada dificuldade */
    		{
    			$statement = $this->db->prepare("SELECT Questao.m_id FROM Questao WHERE Questao.dificuldade=:e0");
    		}
    		$statement->bindParam(":e0", $element);
    		$statement->execute();
    		$count = 0;
    		while($q = $statement->fetchObject())
				{
					$count = $count + 1;
				}
    		return $count;
    	}
    	/* Esse método será responsável por manter todas as consultas necessárias para o funcionamento do sistema */
		public function searchHelper($element, $flg)
		{
			if(isset($element) && $flg == 0)
			{
				/* Indica que é uma busca por todas as questões pertencentes a uma matéria */
				$statement = $this->db->prepare("SELECT Questao.q_id, Questao.m_id, Questao.dificuldade, Questao.tipo_questao,
					Questao.ano, Questao.imagem, Materia.nomeMateria FROM Questao INNER JOIN Materia 
					ON Questao.m_id = Materia.m_id WHERE Questao.m_id = :element");
				$statement->bindParam(":element", $element);
			}
			else if(isset($element) && $flg == 1) 
			{
				/* Indica que é uma busca de uma questão por completa para ser exibida */
				$statement = $this->db->prepare("SELECT Questao.q_id, Questao.m_id, Questao.u_id, Questao.dificuldade, 
					Questao.enunciado, Questao.alternativas, Questao.resposta, Questao.tipo_questao, Questao.ano, Questao.imagem,
					Questao.texto_alt, Materia.nomeMateria FROM Questao INNER JOIN Materia ON Questao.m_id = Materia.m_id 
					WHERE Questao.q_id = :element");
				$statement->bindParam(":element", $element);
			}
			else if($flg == 3)
			{
				/* Indica que é uma busca por todas as questões pertencentes a um determinado tipo */
				$statement = $this->db->prepare("SELECT DISTINCT Questao.tipo_questao FROM Questao");
			}
			else if($flg == 4)
			{
				/* Indica que é uma busca por uma questão de um determinado tipo */
				$statement = $this->db->prepare("SELECT Questao.q_id, Questao.m_id, Questao.dificuldade, Questao.tipo_questao,
					Questao.texto_alt, Questao.ano, Questao.imagem, Materia.nomeMateria FROM Questao INNER JOIN Materia ON Questao.m_id = Materia.m_id WHERE 
					Questao.tipo_questao = :element ORDER BY Questao.q_id");
				$statement->bindParam(":element", $element);
			}
			else if($flg == 5)
			{
				/* Indica que é uma busca por todas as questões de uma determinada dificuldade */
				$statement = $this->db->prepare("SELECT Questao.q_id, Questao.m_id, Questao.dificuldade, Questao.tipo_questao,
					Questao.texto_alt, Questao.ano, Materia.nomeMateria FROM Questao NATURAL JOIN Materia WHERE 
                    Questao.dificuldade = :element ORDER BY Questao.q_id");
				$statement->bindParam(":element", $element);
			}
			else if($flg == 6)
			{
				/* Indica que é uma busca por todas as questões em ordem decrescente */
				$statement = $this->db->prepare("SELECT Questao.q_id, Questao.m_id, Questao.dificuldade, Questao.tipo_questao,
                    Questao.ano, Questao.texto_alt, Materia.nomeMateria FROM Questao NATURAL JOIN Materia ORDER BY Questao.q_id DESC");
			}
			else if($flg == 7)
			{
				/* Indica que é uma busca por todas as questões do usuário logado no sistema no momento */
				$statement = $this->db->prepare("SELECT Questao.q_id, Questao.m_id, Questao.dificuldade, Questao.tipo_questao,
                    Questao.ano, Questao.texto_alt, Materia.nomeMateria FROM Questao NATURAL JOIN Materia WHERE Questao.u_id=:element
                    ORDER BY Questao.q_id DESC");
				$statement->bindParam(":element", $element);
			}
			else if($flg == 8)
			{
				/* Indica que é uma busca por todas as dificuldades */
				$statement = $this->db->prepare("SELECT DISTINCT Questao.dificuldade FROM Questao");
			}
			else if($flg == 9)
			{
				/* Indica que é uma busca pela próxima questão de uma determinada matéria */
				$statement = $this->db->prepare("SELECT Questao.q_id, Questao.m_id, Questao.dificuldade, Questao.enunciado,
                    Questao.alternativas, Questao.resposta, Questao.tipo_questao, Questao.ano, Questao.imagem, Questao.texto_alt,
                    Materia.nomeMateria FROM Questao INNER JOIN Materia ON Questao.m_id = Materia.m_id
                    WHERE Questao.q_id=(SELECT min(Questao.q_id) FROM Questao WHERE Questao.q_id > ".$element[0]."
                     AND Questao.m_id='".$element[2]."')");
			}
			else if($flg == 10)
			{
				/* Indica que é uma busca pela questão anterior de uma determinada matéria */
				$statement = $this->db->prepare("SELECT Questao.q_id, Questao.m_id, Questao.dificuldade, Questao.enunciado,
                    Questao.alternativas, Questao.resposta, Questao.tipo_questao, Questao.ano, Questao.imagem, Questao.texto_alt,
                    Materia.nomeMateria FROM Questao INNER JOIN Materia ON Questao.m_id = Materia.m_id
                    WHERE Questao.q_id=(SELECT max(Questao.q_id) FROM Questao WHERE Questao.q_id < ".$element[0]."
                     AND Questao.m_id='".$element[2]."')");
			}
			else if($flg == 11)
			{
				/* Indica que é uma busca pela próxima questão de um determinado tipo de questão */
				$statement = $this->db->prepare("SELECT Questao.q_id, Questao.m_id, Questao.dificuldade, Questao.enunciado,
                    Questao.alternativas, Questao.resposta, Questao.tipo_questao, Questao.ano, Questao.imagem, Questao.texto_alt,
                    Materia.nomeMateria FROM Questao NATURAL JOIN Materia WHERE Questao.q_id=(SELECT min(Questao.q_id) 
                    FROM Questao WHERE Questao.q_id > ".$element[0]." AND Questao.tipo_questao='".$element[1]."')");
			}
			else if($flg == 12)
			{
				/* Indica que é uma busca pela questão anterior de um determinado tipo de questão */
				$statement = $this->db->prepare("SELECT Questao.q_id, Questao.m_id, Questao.dificuldade, Questao.enunciado,
                    Questao.alternativas, Questao.resposta, Questao.tipo_questao, Questao.ano, Questao.imagem, Questao.texto_alt,
                    Materia.nomeMateria FROM Questao NATURAL JOIN Materia WHERE Questao.q_id=(SELECT max(Questao.q_id) 
                    FROM Questao WHERE Questao.q_id <".$element[0]." AND Questao.tipo_questao='".$element[1]."')");
			}
			else if($flg == 13)
			{
				/* Indica que é uma busca pela próxima questão de uma determinada dificuldade */
				$statement = $this->db->prepare("SELECT Questao.q_id, Questao.m_id, Questao.dificuldade, Questao.enunciado,
                    Questao.alternativas, Questao.resposta, Questao.tipo_questao, Questao.ano, Questao.imagem, Questao.texto_alt,
                    Materia.nomeMateria FROM Questao NATURAL JOIN Materia WHERE Questao.q_id=(SELECT min(Questao.q_id) 
                    FROM Questao WHERE Questao.q_id >".$element[0]." AND Questao.dificuldade='".$element[3]."')");
			}
			else if($flg == 14)
			{
				/* Indica que é uma busca pela questão anterior de uma determinada dificuldade */
				$statement = $this->db->prepare("SELECT Questao.q_id, Questao.m_id, Questao.dificuldade, Questao.enunciado,
                    Questao.alternativas, Questao.resposta, Questao.tipo_questao, Questao.ano, Questao.imagem, Questao.texto_alt,
                    Materia.nomeMateria FROM Questao NATURAL JOIN Materia WHERE Questao.q_id=(SELECT max(Questao.q_id) 
                    FROM Questao WHERE Questao.q_id <".$element[0]." AND Questao.dificuldade='".$element[3]."')");
			}
			else if($flg == 15)
			{
				/* Indica que é uma busca pela próxima questão de acordo com o identificador dela */
				$statement = $this->db->prepare("SELECT Questao.q_id, Questao.m_id, Questao.dificuldade, Questao.enunciado,
                    Questao.alternativas, Questao.resposta, Questao.tipo_questao, Questao.ano, Questao.imagem, Questao.texto_alt,
                    Materia.nomeMateria FROM Questao NATURAL JOIN Materia WHERE Questao.q_id=(SELECT min(Questao.q_id) 
                    FROM Questao WHERE Questao.q_id >".$element[0].")");
			}
			else if($flg == 16)
			{
				/* Indica que é uma busca pela questão anterior de acordo com o identificador dela */
				$statement = $this->db->prepare("SELECT Questao.q_id, Questao.m_id, Questao.dificuldade, Questao.enunciado,
                    Questao.alternativas, Questao.resposta, Questao.tipo_questao, Questao.ano, Questao.imagem, Questao.texto_alt,
                    Materia.nomeMateria FROM Questao NATURAL JOIN Materia WHERE Questao.q_id=(SELECT max(Questao.q_id) 
                    FROM Questao WHERE Questao.q_id <".$element[0].")");
			}
			else if($flg == 17)
			{
				/* Indica que é uma busca pela próxima questão do usuário autenticado no momento */
				$statement = $this->db->prepare("SELECT Questao.q_id, Questao.m_id, Questao.u_id, Questao.dificuldade, Questao.enunciado,
                    Questao.alternativas, Questao.resposta, Questao.tipo_questao, Questao.ano, Questao.imagem, Questao.texto_alt,
                    Materia.nomeMateria FROM Questao NATURAL JOIN Materia WHERE Questao.q_id=(SELECT min(Questao.q_id) 
                    FROM Questao WHERE Questao.q_id >".$element[0]." AND Questao.u_id=".$_SESSION['u_id'].")");
			}
			else if($flg == 18)
			{
				/* Indica que é uma busca pela questão anterior do usuário autenticado no momento */
				$statement = $this->db->prepare("SELECT Questao.q_id, Questao.m_id, Questao.u_id, Questao.dificuldade, Questao.enunciado,
                    Questao.alternativas, Questao.resposta, Questao.tipo_questao, Questao.ano, Questao.imagem, Questao.texto_alt,
                    Materia.nomeMateria FROM Questao NATURAL JOIN Materia WHERE Questao.q_id=(SELECT max(Questao.q_id) 
                    FROM Questao WHERE Questao.q_id < ".$element[0]." AND Questao.u_id=".$_SESSION['u_id'].")");
			}
			$questoes = array ();
			$questoes = $this->search($statement);
			return $questoes;
		}
		public function search($statement)
		{
			$questoes = array ();
			try
			{
				$statement->execute();
				//var_dump($statement->fetchObject());
				while($q = $statement->fetchObject())
				{
					$questao = new Questao();
					if(isset($q->q_id))
						$questao->setId($q->q_id);
					if(isset($q->m_id))
						$questao->setMId($q->m_id);
					if(isset($q->u_id))
						$questao->setUId($q->u_id);
					if(isset($q->login))
						$questao->setULogin($q->login);
					if(isset($q->dificuldade))
						$questao->setDificuldade($q->dificuldade);
					if(isset($q->enunciado))
						$questao->setEnunciado($q->enunciado);
					if(isset($q->alternativas))
						$questao->setAlternativas($q->alternativas);
					if(isset($q->resposta))
						$questao->setResposta($q->resposta);
					if(isset($q->tipo_questao))
						$questao->setTipo($q->tipo_questao);
					if(isset($q->ano))
						$questao->setAno($q->ano);
					if(isset($q->nomeMateria))
						$questao->setNomeMateria(utf8_encode($q->nomeMateria));
					if(isset($q->imagem))
					{
						$questao->setImagem($q->imagem);
					}
					if(isset($q->texto_alt))
						$questao->setTextoAlt($q->texto_alt);
					$questoes[] = $questao;
				}
				return $questoes;
			}
			catch (Exception $exc) 
			{
            	echo $exc->getTraceAsString();
        	}
		}
		public function insert($element)
		{
			if(isset($element))
			{
				$materia = $element->getMId();
				$usuario = $element->getUId();
				$dificuldade = $element->getDificuldade();
    			$tipo_questao = $element->getTipo();
    			$data = $element->getAno();
    			$enunciado = $element->getEnunciado();
    			$alternativas = $element->getAlternativas();
    			$resposta = $element->getResposta();
    			$img = $element->getImagem();
    			$texto_alt = $element->getTextoAlt();
    			$imagem = null;
    			if($img != "")
    			{
    				$imagem = $this->copiarImagem($_FILES['imagem'], $_SERVER['DOCUMENT_ROOT']
    					.'/trabalho_progweb/misc/imagens/questao/');
    				if($imagem == null)
        			{
        				echo 'Erro';
              			return -1;
    	    		}
    			}
				try
				{	
					$statement = $this->db->prepare("INSERT INTO Questao (m_id, dificuldade, enunciado, alternativas, 
						resposta, tipo_questao, ano, imagem, u_id, texto_alt) VALUES (:e0, :e1, :e2, :e3, :e4, :e5, :e6, :e7, :e8, :e9)");
					$statement->bindParam(":e0", $materia);
					$statement->bindParam(":e1", $dificuldade);
					$statement->bindParam(":e2", $enunciado);
					$statement->bindParam(":e3", $alternativas);
					$statement->bindParam(":e4", $resposta);
					$statement->bindParam(":e5", $tipo_questao);
					$statement->bindParam(":e6", $data);
					$statement->bindParam(":e7", $imagem);
					$statement->bindParam(":e8", $usuario);
					$statement->bindParam(":e9", $texto_alt);

					$statement->execute();
					return 1;
				}
				catch(PDOException $e)
				{
					echo $e->getMessage();
					return -1;
				}
			}
			else
				return -1;
		}
		public function alter($element, $change)
		{
			if(isset($element))
			{
				// Não há necessidade de alterar o id do usuário 
				$q_id = $element->getId();
				$materia = $element->getMId();
				$dificuldade = $element->getDificuldade();
	    		$tipo_questao = $element->getTipo();
	    		$data = $element->getAno();
	    		$enunciado = $element->getEnunciado();
	    		$alternativas = $element->getAlternativas();
	    		$resposta = $element->getResposta();
	    		$img = $element->getImagem();
	    		$texto_alt = $element->getTextoAlt();
	    		// echo $img;
	    		// echo '<br>';
	    		$imagem = null;
    			if(strcmp($change, "Limpar imagem") == 0)
    			{
    				if($_FILES['imagem']['tmp_name'] != "")
    				{
    					$imagem = $this->copiarImagem($_FILES['imagem'], $_SERVER['DOCUMENT_ROOT']
	    					.'/trabalho_progweb/misc/imagens/questao/');
    					if($imagem == null)
        				{
        					echo 'Erro';
	              			return -1;
    	    			}
    				}
    	    		else
    	    		{
    	    			if(!is_null(($img)))
    	    				unlink(str_replace("/var/www/trabalho_progweb/", "", $img));
    	    		}
    			}
    			else
    			{
    				$imagem = $img;
    				// echo $imagem.'<br>';
    			}
	    		try
				{
					$statement = $this->db->prepare("UPDATE Questao SET Questao.m_id=:e0, Questao.dificuldade=:e1, Questao.tipo_questao=:e2,
						Questao.ano=:e3, Questao.enunciado=:e4, Questao.alternativas=:e5, Questao.resposta=:e6, 
						Questao.imagem=:e7, Questao.texto_alt=:e8 WHERE Questao.q_id=:e9");
						$statement->bindParam(":e0", $materia);
						$statement->bindParam(":e1", $dificuldade);
						$statement->bindParam(":e2", $tipo_questao);
						$statement->bindParam(":e3", $data);
						$statement->bindParam(":e4", $enunciado);
						$statement->bindParam(":e5", $alternativas);
						$statement->bindParam(":e6", $resposta);
						$statement->bindParam(":e7", $imagem);
						$statement->bindParam(":e8", $texto_alt);
						$statement->bindParam(":e9", $q_id);
						$statement->execute();
						return 1;
				}
				catch(PDOException $e)
				{
					echo $e->getMessage();
					return -1;
				}
			}
			else
			{
				return -1;
			}
		}
		public function remove($element)
		{
			$q_id = $element;
			if(isset($q_id))
			{
				try
				{
					$statement = $this->db->prepare("DELETE FROM Questao WHERE Questao.q_id=:e0");
					$statement->bindParam(":e0", $q_id);
					$statement->execute();
					return 1;
				}
				catch(PDOException $e)
				{
					echo $e->getMessage();
					return -1;
				}
			}
			else
				return -1;
		}
	}
?>