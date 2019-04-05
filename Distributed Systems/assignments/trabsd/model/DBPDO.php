<?php

abstract class DBPDO 
{
    
    protected $db;
    
    public function __construct() 
    {
        try 
        {
            $this->db = new PDO("mysql:host=localhost;dbname=TrabalhoSD", "root", "morenao");
            // TODO - ao final, remover 
            $this->db->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_WARNING);
        } 
        catch (PDOException $exception) 
        {
            echo $exception->getMessage();
        }
        catch (Exception $exception) 
        {
            echo $exception->getMessage();
        }
    }
    
    public function __destruct()
    {
        $this->db = null;
    }

    //abstract public function search($element);
    
    abstract public function insert($element);     
       
}


?>
