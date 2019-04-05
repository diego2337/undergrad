<?php

class Object{
	private $name;
	private $size;
	private $path;
        private $bucket;

	function __construct() {
    	}

            function getName() {
                return $this->name;
            }

            function getSize() {
                return $this->size;
            }

            function getPath() {
                return $this->path;
            }

            function getBucket() {
                return $this->bucket;
            }

            function setName($name) {
                $this->name = $name;
            }

            function setSize($size) {
                $this->size = $size;
            }

            function setPath($path) {
                $this->path = $path;
            }

            function setBucket($bucket) {
                $this->bucket = $bucket;
            }

            	//setters and getters
}

?>
