<?php

require 'model/User.php';

class UserFactory extends AbstractFactory {
    
    public function __construct() {
        parent::__construct();
    }   
    
    public function alterar($object) {
        
    }
    
    public function authenticate ($login, $pass) {
		$pass = md5($pass);

		$sth = $this->database->prepare ("SELECT senha FROM Treinador where login = '". $login. "'");

		$sth->execute();

		$user  = $sth->fetchObject ();
		
		
		if(!$user)
			return NULL;
		return $user->senha == $pass;
		
		
		
    }

    public function buscar($param) {
        
        try {
            
            $sth = $this->database->prepare ('SELECT * FROM User WHERE login = :login');
        
            $sth->bindParam(":login", $login);

            $sth->execute();
            
            $users = array ();

            while ($obj =  $sth->fetchObject())
            {
                    $user = new User ();

                    $user->setId ($obj->id);
                    $user->setLogin($obj->login);
                    $user->setName ($obj->name);
                    $user->setPass ($obj->pass);

                    $users [] = $user;
            }
            
            return $users;
            
        } catch (PDOException $e) {
            $e->getMessage();
        }
        
        
    }

    public function inserir($object) {
        
        $login = $object->getLogin();
        $pass = $object->getPass();
        $name  = $object->getPass();
        
        if(loginExist($login)) { 
                return false;
        }
        
        try {
            
            $sthe = $this->database->prepare("INSERT INTO User (login, pass, name) VALUES (:login, :pass, :name" );

            $sthe->bindParam(":login", $login);
            $sthe->bindParam(":pass", md5($pass));
            $sthe->bindParam(":name", $name);

            return $sthe->execute();
            
        } catch (PDOException $e) {
            echo $e->getMessage();
        }
    }

    public function remover($param) {
        
    }
    
    public function loginExist($login){
        $sth = $this->connection->prepare ('SELECT * FROM User WHERE login = :login');
        
        $sth->bindParam(":login", $login);
        
        $sth->execute();
        
        while ($obj =  $sth->fetchObject())
	{
            return true;
	}
        
        return false;
        
    }
    
    public function findAll () {
		$sth = $this->connection->prepare ('SELECT * FROM User');
		$sth->execute();

		$users = array ();

		while ($obj =  $sth->fetchObject())
		{
			$user = new User ();

			$user->setId ($obj->id);
			$user->setLogin($obj->login);
			$user->setName ($obj->name);
			$user->setPass ($obj->pass);

			$users [] = $user;
		}
		return $users;
	}
    
    
}

?>
