<?php
	include 'Usuario.php';
	class UsuarioDAO extends DBPDO
	{
		public function __construct()
		{
			parent::__construct();
		}
		public function __destruct()
		{
			parent::__destruct();
		}

		public function autenticar($login, $password)
		{
			$senha = md5($password);
			$statement = $this->db->prepare("SELECT senha FROM Usuario WHERE Usuario.login = '".$login."' ");
			$statement->execute();
			$u = $statement->fetchObject();
			/* Não digitou a senha ou login é inexistente */
			if(!($u))
			{
				return false;
			}
			else
			{
				$statement = $this->db->prepare("SELECT * FROM Usuario WHERE Usuario.senha = '".$senha."' 
					AND Usuario.login='".$login."'");
				$statement->execute();
				$u = $statement->fetchObject();
				/* Senha incorreta */
				if(!($u))
					return false;
				else
				{
					$user = new Usuario();
					$user->setUId($u->u_id);
					$user->setLogin($u->login);
					$user->setSenha($u->senha);
				}
				return $user;
			}
		}

		public function checar($element)
		{
			$statement = $this->db->prepare("SELECT Usuario.login FROM Usuario WHERE Usuario.login='".$element."'");
			$statement->execute();
			$u = $statement->fetchObject();
			if(!($u))
				return false;
			else
				return true;
		}

		public function insert($element)
		{
			if(isset($element))
			{
				try
				{
					$login = $element[0];
					$senha = md5($element[1]); 
					$statement = $this->db->prepare("INSERT INTO Usuario (Usuario.login, Usuario.senha) VALUES (:u0, :u1)");
					$statement->bindParam(":u0", $login);
					$statement->bindParam(":u1", $senha);
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

		public function remove($element)
		{
			if(isset($element))
			{
				try
				{
					$statement = $this->db->prepare("DELETE FROM Usuario WHERE Usuario.u_id=:u0");
					$statement->bindParam(":u0", $element);
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

		public function alter($element)
		{
			if(isset($element))
			{
				$newPassword = md5($element);
				try
				{
					$statement = $this->db->prepare("UPDATE Usuario SET Usuario.senha=:n0 WHERE Usuario.u_id=:s0");
					$statement->bindParam(":n0", $newPassword);
					$statement->bindParam(":s0", $_SESSION['u_id']);
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