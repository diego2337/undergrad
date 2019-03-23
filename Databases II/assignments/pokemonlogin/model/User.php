<?php

class User 
{
	private $id;

	private $login;

	private $pass;

	private $name;

	public function getId ()
	{
		return $this->id;
	}

	public function setId ($id)
	{
		$this->id = $id;
	}


	public function getLogin()
	{
		return $this->login;
	}

	public function setLogin ($login)
	{
		$this->login = $login;
	}
	
	public function getName ()
	{
		return $this->name;
	}

	public function setName ($name)
	{
		$this->name = $name;
	}
        
	public function getPass ()
	{
		return $this->pass;
	}

	public function setPass ($pass)
	{
		$this->pass = $pass;
	}
}