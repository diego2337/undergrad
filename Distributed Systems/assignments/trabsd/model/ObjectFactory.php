<?php

//require 'model/AbstractFactory.php';

require 'vendor/autoload.php';

use Aws\S3\S3Client;
use Aws\Common\Credentials\Credentials;
require 'model/Object.php';

class ObjectFactory {
  public $client;
  
  public function __construct() {

	    # Note. other methods of providing the credentials did not work, so stick to this
        $credentials = new Credentials('AKIAI4S72J5V37T5O4CA', 'V2+F0yEVrMGwNCfq+d0lDThARrnhnDvuhSZV8u+n');

      
	$this->client = S3Client::factory(array(
            'credentials' => $credentials
        ));
   
   }
   

    
  /* public function getBucket(){
       
       //conecta com o banco
       
       $query = 'SELECT bucket FROM Usuario WHERE login = '.$_SESSION['usuario'].'';
       
       
   }
   */
   
   public function inserirPasta($param)
   {
        $this->client->putObject(array( 
        'Bucket'       =>$param->getBucket(),
         'Key'          =>  $param->getPath().'/'.$param->getName(),
        'Body'       => "",
        'ACL'          => 'public-read'
        ));

       
   }
   
    public function inserir($param)
	{
		
		//echo "Creating a new object with key {$key}\n";
		$result = $this->client->putObject(
                     array(
                        'Bucket'     => $param->getBucket(),
                        'Key'        => $param->getName(),
                        'SourceFile' => $param->getPath()
                    )
                       
                        );
          
        }

    public function listar($param)
    {
        $objects = $this->client->getIterator('ListObjects', array(
            'Bucket' => $param->getBucket(), // REQUIRED
            'Delimiter' => '/',
            'Prefix' => $param->getPath()
            ),
             array(
                            
               'return_prefixes' => true, 
              )
         );
 
        return $objects;
        

    }   public function listar2($param)
    {
      // echo "bucket".$param->getBucket();
      // echo " Path: ".$param->getPath();
        $objects = $this->client->getIterator('ListObjects', array(
            'Bucket' => $param->getBucket(), // REQUIRED
            'Prefix' => $param->getPath(),
            'Delimiter' => '/'
            ),
             array(
                            
               'return_prefixes' => true, 
              )
         );
        return $objects;
    }


    public function alterar($param, $isDirectory, $novoNome, $nomeASubstituir, $level)
    {
		//renomear arquivo ou pasta
        $sourceBucket = $param->getBucket();

        /* Caso 1: Renomear arquivo */
        if($isDirectory == false)
        {
            $sourceKeyname = $param->getPath().$param->getName();
            $key = $param->getPath().$param->getName();
            $newName = $param->getPath().$novoNome;

            $this->client->copyObject(array( // TODO - argumento de 'Bucket' pode ser $sourceBucket?
                'Bucket'     => $param->getBucket(),
                'Key'        => $newName,
                'CopySource' => "{$sourceBucket}/{$sourceKeyname}",
            ));
            /*echo "Deleting object with key {$key}\n";*/
                    $result = $this->client->deleteObject(array(
                            'Bucket' => $param->getBucket(),
                            'Key'    => "{$key}"
            ));
        }
        else if($isDirectory == true) // Caso 2: Renomear Pasta
        {
          $path = $param->getPath();
          $param->setPath($param->getPath().$param->getName());
          /* Recuperar todos os elementos da pasta atual */
          /*echo 'TA NA HORA DE LISTAR<br>';*/
          $objects = $this->listar2($param);
          /*echo 'LISTAR DE HORA NA TA<br>';*/
          /* Iterar por cada elemento e realizar a mudança de nome */
          foreach($objects as $object)
          {
               // print_r($object);
        /*
              //  die();

                /* Renomeando todos os argumentos necessários para cada elemento */
                /*echo  $object['Key'];
                 echo $param->getBucket();*/
                if(isset($object['Key']) && $object['Key'] != "")
                  $arr = explode($param->getPath(), $object['Key']);
                else if(isset($object['Prefix']) && $object['Prefix'] != "")
                {
                  /* Chama recursivamente a função */
                  /*$arr = explode($param->getPath(), $object['Prefix']);*/
                  $previous_dir = '';
                  $tok = strtok($object['Prefix'],"/");
                  $prev = $tok;
                  $tok = strtok("/");
                  while ($tok !== false) 
                  {
                      $previous_dir = $previous_dir.$prev;
                      $prev = "/".$tok;
                      $tok = strtok("/");
                  }
                  $previous_dir = $previous_dir."/";
                  $novoObj = new Object();
                  $novoObj->setBucket($param->getBucket());
                  $novoObj->setPath($previous_dir);
                  $str = $object['Prefix'];
                  $i = strlen($str)-2;
                  $n = "";
                  while($str[$i] != "/" && $i >= 0)
                  {
                    $i = $i - 1;
                  }
                  $i = $i + 1;
                  while($i < strlen($str))
                  {
                    $n = $n.$object['Prefix'][$i];
                    $i = $i + 1;
                  }
                  /*$param->setName(substr(strrev($object['Prefix']), 0, strpos(strrev($object['Prefix']), "/")));*/
                  $novoObj->setName($n);
                  /*echo '<br><br><br>entrou na recursao - diretorio corrente: '.$object['Prefix'].' tok: '.$n.' <br><br><br>';*/
                  $this->alterar($novoObj, true, $novoNome, $nomeASubstituir, $level+1);
                }
                /*echo '<br><br>separador<br><br>';
                echo $object['Key'];
                echo '<br><br>separador2<br><br>';*/
                /* echo '<br>dando espaço<br><br><br>';
                echo $arr[1];*/
                if(isset($arr[1]))
                {
                  // $newName = $path.$novoNome."/".$arr[1];
                  $newName = str_replace($nomeASubstituir, $novoNome."/", $param->getPath()).$arr[1];
                  $sourceKeyname = $path.$param->getName();//.$arr[1];
                  $key = $path.$param->getName().$arr[1];
                  /*echo 'espaco0<br>';
                  echo $arr[1].'<br>'.print_r($arr).'<br>';
                  echo 'espaco<br>';
                  echo urldecode($param->getBucket().'/'.$sourceKeyname.$arr[1]).'<br>';
                  echo 'espaco2<br>';
                  echo $newName.'<br>';
                  echo 'espaco3<br>';
                  echo $level.'<br>';
                  echo 'espaco4<br>';*/
                  /* Realizando de fatos as mudanças */
                  /*echo urldecode($param->getBucket().'/'.$sourceKeyname);*/
                  $this->client->copyObject(array( // TODO - argumento de 'Bucket' pode ser $sourceBucket?
                      'Bucket'     => $param->getBucket(),
                      'Key'        => $newName,
                      'CopySource' => urldecode($param->getBucket().'/'.$sourceKeyname.$arr[1])//$sourceBucket/{$sourceKeyname},
                  ));
                  /*echo "Deleting object with key {$key}\n";*/
                    $result = $this->client->deleteObject(array(
                      'Bucket' => $param->getBucket(),
                      'Key'    => urldecode($param->getBucket().'/'.$sourceKeyname.$arr[1])
                  ));
                }
          }  
      }
    
    }

        
	public function download($param)
	{

    $buckets = new BucketFactory();
    $bucket = new Bucket();
    $bucket->setId($_SESSION['usuario']);
    $bucket = $buckets->buscaBucket($bucket);        
		/*echo "Downloading that same object:\n";*/
		$result = $this->client->getObject(array(
			'Bucket' => $bucket->getDbBucket(),
			'Key'    => $param->getPath().$param->getName(),
            'SaveAs'=>$_SERVER['DOCUMENT_ROOT'].'/trabsd/tempDownload/'.$param->getName()
		));
                
                header("Content-Type: application/octet-stream");
                header('Content-Disposition: attachment; filename="'.$param->getName().'"');
                ob_clean();   // discard any data in the output buffer (if possible)
flush();      // flush headers (if possible)

                readfile($_SERVER['DOCUMENT_ROOT'].'/trabsd/tempDownload/'.$param->getName());
	}
	
	public function remover($param)
	{
		/*$info = $this->client->getObjectInfo($param->getBucket(), $param->getName());*/
		//echo "Deleting object with key ".$param->getName()."\n";
    $result = $this->client->getObject(array(
      'Bucket' => $param->getBucket(),
      'Key'    => $param->getName(),
    ));
    $size = $result['Size'];
		$result = $this->client->deleteObject(['Bucket' => $param->getBucket(),
			'Key'    => $param->getName()
    ]);
    return $size;
	}

  public function borrar($param)
  {
    /*echo 'dye dye DYEEEEEEEEEEEE <br><br><br>';*/
    
    $result = $this->client->deleteMatchingObjects($param->getBucket(), $param->getPath().$param->getName());
    return 1;
  }

  public function folderSize($param, $isDirectory)
  {
    $size = 0;
    if($isDirectory == 1)
    {
      if($param->getPath()=="/")
        $prefix = $param->getName();
      else
        $prefix = $param->getPath().$param->getName();
    }
    else
      $prefix = $param->getName();
    $objects = $this->client->getIterator('ListObjects', array(
        "Bucket" => $param->getBucket(),
        "Prefix" => $prefix
    ));
    $i = 0;
    foreach ($objects as $object) 
    {
        $size = $size+$object['Size'];
    }
    /*return $this->formatSizeUnits($size);*/
    return $size;
  }

  public function formatSizeUnits($bytes) 
  {
    if ($bytes >= 1073741824) 
    {
        $bytes = number_format($bytes / 1073741824, 2) /*. ' GB'*/;
    } 
    elseif ($bytes >= 1048576) 
    {
        $bytes = number_format($bytes / 1048576, 2) /*. ' MB'*/;
    } 
    elseif ($bytes >= 1024) 
    {
        $bytes = number_format($bytes / 1024, 2) /*. ' KB'*/;
    } 
    elseif ($bytes > 1) 
    {
        $bytes = $bytes;
    } 
    elseif ($bytes == 1) 
    {
        $bytes = $bytes;
    } 
    else 
    {
        $bytes = 0;
    }
    return $bytes;
}
}
?>


