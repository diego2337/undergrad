<?php

//require 'model/AbstractFactory.php';

require 'vendor/autoload.php';

use Aws\S3\S3Client;
use Aws\S3\Model\ClearBucket;
use Aws\Common\Credentials\Credentials;
require 'model/Bucket.php';

class BucketFactory extends DBPDO{
  public $client;
  
  public function __construct() {
	//TODO precisa conectar com s3?
      
      # Note. other methods of providing the credentials did not work, so stick to this
        $credentials = new Credentials('AKIAI4S72J5V37T5O4CA', 'V2+F0yEVrMGwNCfq+d0lDThARrnhnDvuhSZV8u+n');

      
	$this->client = S3Client::factory(array(
            'credentials' => $credentials
        ));
        
        parent::__construct();
   }
   public function insert($param)
   {
       
      }

   public function buscaBucket($bucket)
   {
       
        $statement = $this->db->prepare("SELECT * FROM Usuario WHERE Usuario.login = '".$bucket->getId()."' ");
        $statement->execute();
        $u = $statement->fetchObject();

        if(!($u))
        {
                return false;
        }
        else
        {

            $bucket = new Bucket();
            $bucket->setId($u->u_id);
          //  $bucket->setNumberOfItems($u->items);
            $bucket->setDbBucket($u->bucket);
            //$user->setLogin($u->login);
            //$user->setSenha($u->senha);

            return $bucket;
        }

                        
   }
    
   public function buscar($param) {

//try{
		$result = $this->client->listObjects([
			'Bucket' => '<string>', // REQUIRED
			'Delimiter' => '<string>',
			'EncodingType' => 'url',
			'Marker' => '<string>',
			'MaxKeys' => '<integer>',
			'Prefix' => '<string>',
		]);

//}
	//catch

	}
    public function listar($param)
    {
        
        
   	$objects = $this->client->getIterator('ListObjects', array(
			'Bucket' => $param->getDbBucket(), // REQUIRED
			'Prefix' => '',
                        'Delimiter'=> '/'
		),  array(
                            
               'return_prefixes' => true, 
              ));
        
        return $objects;
        

    }
	public function inserir($param)
    {
       // $bucket = uniqid($param->getId(), true);
//        echo "Creating bucket named {$bucket}\n";
        //$buckets = new BucketFactory();
        //$param = $buckets->buscaBucket($param);
            
        $result = $this->client->createBucket(array(
            'Bucket' => $param->getDbBucket()
        ));
        
        
        
        
        
        

    }

	public function deletar($param, $path)
	{
      /*$objects = $this->client->getIterator('ListObjects', array(
        'Bucket' => $param->getDbBucket(), // REQUIRED
        'Prefix' => '',
        'Delimiter'=> '/'
      ),  
      array(                     
        'return_prefixes' => true, 
      ));
      $obj = new ObjectFactory();
      $obj2 = new Object();
      $obj2->setBucket($param->getDbBucket());
      foreach ($objects as $object)
      {
        $obj2->setName($object['Key']);
        $obj->remover($obj2); 
      }
      $obj2->setName($object['Prefix']);
      $obj->remover($obj2); */
    /*$keys = $this->client->listObjects(array('Bucket' => $param->getDbBucket(),'Prefix' => $path));
    $result = $this->client->deleteObjects(array(
      'Bucket'  => $param->getId(),
      'Objects' => array_map(function ($key) {
          return array('Key' => $key);
      }, $keys)
    ));*/
    $clear = new ClearBucket($this->client, $param->getDbBucket());
    $clear->clear();
    $this->client->deleteBucket(array('Bucket' => $param->getDbBucket()));
	}


}

?>

