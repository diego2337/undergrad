<?php

class Bucket{
	private $id;
	private $size;
	
        private $dbBucket;

	function __construct() {
    	}

	//setters and getters
        
        function getDbBucket() {
            return $this->dbBucket;
        }

        function setDbBucket($dbBucket) {
            $this->dbBucket = $dbBucket;
        }

                
        
        
        function getId() {
            return $this->id;
        }

        function getSize() {
            return $this->size;
        }

        function getNumberOfItems() {
            return $this->numberOfItems;
        }

        function setId($id) {
            $this->id = $id;
        }

        function setSize($size) {
            $this->size = $size;
        }

        function setNumberOfItems($numberOfItems) {
            $this->numberOfItems = $numberOfItems;
        }


}



?>
