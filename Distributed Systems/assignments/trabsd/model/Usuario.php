<?php
	class Usuario 
	{
		private $u_id;
		private $login;
		private $senha;
		private $size;
		private $bucket;

		public function getUId ()
		{
			return $this->u_id;
		}

		public function setUId ($id)
		{
			$this->u_id = $id;
		}


		public function getLogin()
		{
			return $this->login;
		}

		public function setLogin ($login)
		{
			$this->login = $login;
		}
		  
		public function getSenha ()
		{
			return $this->senha;
		}

		public function setSenha ($senha)
		{
			$this->senha = $senha;
		}

		public function getSize()
		{
			return $this->size;
		}

		public function setSize($size)
		{
			$this->size = $size;
		}

		public function getBucket()
		{
			return $this->bucket;
		}

		public function setBucket($bucket)
		{
			$this->bucket = $bucket;
		}
	}
?>