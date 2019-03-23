<?php
$username = "mor";
$password = "@mor";
$hostname = "localhost"; 

//connection to the database
$dbhandle = mysql_connect($hostname, $username, $password) 
  or die("Unable to connect to MySQL");
echo "Connected to MySQL<br>";
mysql_select_db("Pokedex") or die("error pilih db");

?>