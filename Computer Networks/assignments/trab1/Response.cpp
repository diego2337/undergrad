#ifndef __RESPONSE_H
#include "Response.h"
#endif


/* Esse método será responsável por analisar a requisição enviada pelo navegador e traduzi-la de maneira a enviar o cabeçalho
de resposta corretamente */
std::string Response::mountResponse()
{
	/* Vamos primeiramente nos certificar de que o comando requisitado pelo browser é legível ao servidor (GET ou POST) */
	if((strcmp(this->req->getMethod().c_str(), "GET") != 0) && (strcmp(this->req->getMethod().c_str(), "POST") != 0))
	{
		this->code.assign("400 Bad Request");
		this->data.assign(badRequest());
	}

	/* Verifica-se a versão do protocolo 'http' */
	else if(strcmp(this->req->getHttp_version().c_str(), "HTTP/1.1") != 0)
	{
		this->code.assign("505 HTTP Version Not Supported");
		this->data.assign(httpVersion());
	}

	/* Busca-se a data atual */
	this->date.assign(getDate());
	
	/* Procura-se o arquivo para saber se ele realmente existe naquele caminho especificado - caso sim, o seu tamanho e 
	conteúdo já serão recuperados, bem como a data de sua última modificação */
	if(strcmp(this->req->getMethod().c_str(), "BAD") != 0 && strcmp(this->code.c_str(), "505 HTTP Version Not Supported") != 0 &&
		!(searchFile(0)))
	{
		this->code.assign("404 Not Found");
		this->data.assign(notFound());
	}

	/* Como requisitado, esse será um simples exemplo de resposta 301 - Moved Permanently */
	if(strcmp(this->req->getMethod().c_str(), "BAD") != 0 && strcmp(this->req->getFile().c_str(), "moved.html") == 0 &&
		strcmp(this->code.c_str(), "505 HTTP Version Not Supported") != 0 && strcmp(this->code.c_str(), "404 Not Found") == 0)
	{
		moved();
	}
	/* Verifica-se se um diretório, e não um arquivo, foi requisitado */
	else if(strcmp(this->req->getMethod().c_str(), "BAD") != 0 && strcmp(this->code.c_str(), "505 HTTP Version Not Supported") != 0
		&& strcmp(this->req->getFile().c_str(), "directory") == 0)
	{
		listDirectory();
		this->code.assign("200 OK");
	}

	/* O método "POST" recebe um tratamento adicional */	
	if(strcmp(this->req->getMethod().c_str(), "POST") == 0)
	{
		POSTResponse();
	}

	/* O tamanho do arquivo e a data de sua última modificação são recuperados */
	getContentLength();
	this->lastModifiedDate.assign(getLastModifiedDate());

	/* Finalmente, tendo adquirido todas as informações, uma resposta legível ao navegador será construída */
	return toStr();
}

/* Esse método trata da situação em que o sinal "301" é enviado, buscando-se recursivamente, através do método "findDirectory", 
o arquivo movido */
void Response::moved()
{
	std::string caminho;
	this->code.assign("301 Moved Permanently");
	findDirectory(this->req->getPath().c_str(), 0, caminho, 0);
	if(!(caminho.empty()))
	{
		caminho.append("/");
		this->fd.assign(caminho);
		this->fd.append(this->req->getFile());
	}
	getData();
}

/* Nesse método, vamos encontrar e listar os arquivos e diretórios (com seus respectivos links) de uma determinada pasta em um arquivo
 html */
void Response::listDirectory()
{
	unsigned int i = 0;
	if(!(searchFile(1)))
	{
		this->data.assign("<!DOCTYPE html>\n<html>\n<head>\n<title>Lista de arquivos</title>\n</head>\n<body><h1>Lista de arquivos: </h1><br>\n");
		for(i = 0; i < this->files.size(); i++)
		{
			this->data.append("<p> <a href=\"");
			this->data.append(this->req->getOriginalPath());
			this->data.append(this->files[i]);
			this->data.append("\">");
			this->data.append(this->files[i]);
			this->data.append("</a> </p>");
		}
	}
	this->data.append("\n</body>\n</html>");
}

/* O método abaixo busca o arquivo especificado no atributo "file" - o parâmetro "flag" introduz um tratamento adicional caso ele
seja invocado pelo método "listDirectory" */
bool Response::searchFile(int flag)
{
	DIR *dir;
	struct dirent *entry;
	std::string aux;
	if((dir = opendir(this->req->getPath().c_str())) != NULL)
	{
		while((entry = readdir(dir)) != NULL)
		{
			if(strcmp(entry->d_name, this->req->getFile().c_str()) == 0 && flag == 0)
			{
				this->code.assign("200 OK");
				getData();
				closedir(dir);
				return true;
			}
			if(flag == 1)
			{
				if(entry->d_type == DT_DIR)
				{
					aux.assign(entry->d_name);
					aux.append("/");
					this->files.push_back(aux);
				}
				else
					this->files.push_back(entry->d_name);
			}
		}
	}
	closedir(dir);
	return false;
}

/* Como explicado previamente, encontra-se de maneira recursiva o arquivo movido, adicionando o novo caminho à variável "caminho"
(passada por referência) */
void Response::findDirectory(const char* name, int level, std::string& caminho, int flg)
{
	DIR *dir;
    struct dirent *entry;
    char path[10240];
    if (!(dir = opendir(name)))
        return;

    while ((entry = readdir(dir)) != NULL)
    {
    	/* Encontrou-se um diretório */
        if (entry->d_type == DT_DIR)
        {
            int len = snprintf(path, sizeof(path)-1, "%s/%s", name, entry->d_name);
            path[len] = 0;
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
                continue;
            if(flg == 0)
            {
            	flg = 1;
            }
            else
            {
            	caminho.append("/");
            }
            caminho.append(entry->d_name);
            findDirectory(path, level + 1, caminho, flg);
        }
        else
        {
        	/* Não se faz nada - um arquivo convencional foi encontrado */
        }
    }
    closedir(dir);
}

/* Recupera-se a data e hora atuais */
std::string Response::getDate()
{
	time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%d %m %Y %X GMT", &tstruct);
    return buf;
}

/* Recupera-se a data e hora em que o arquivo foi modificado pela útlima vez */
std::string Response::getLastModifiedDate()
{
	struct stat attrib;
	attrib.st_ctime = 0;
	stat(this->fd.c_str(), &attrib);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&attrib.st_ctime);
    strftime(buf, sizeof(buf), "%d %m %Y %X GMT", &tstruct);
    return buf;
}

/* Esse método é responsável por buscar o tamanho do arquivo e seu conteúdo e passá-lo para uma variável do tipo 'std::string', 
auxiliando na leitura de maneira binária o atributo "buff" (que é um vetor de elementos do tipo "char") */
void Response::getData()
{
	FILE *f = fopen(this->fd.c_str(), "rb");
	if(f)
	{
		fseek(f, 0, SEEK_END);
		long fsize = ftell(f);
		rewind(f);
		this->buff.resize(fsize);
		fread(&this->buff[0], fsize, 1, f);
		fclose(f);
		std::string s(this->buff.begin(), this->buff.end());
		this->data.assign(s);
	}
}

/* Recupera-se aqui o tamanho do arquivo */
void Response::getContentLength()
{
	this->size = this->data.size();
}

/* Esse método irá simplesmente transformar os atributos da classe "Response" em uma variável compatível para o método "send" 
(no caso, a variável será do tipo "char*"). O padrão do cabeçalho de uma resposta também será embutido. */
std::string Response::toStr()
{
	std::string buffer2;
	char *buf = (char*)malloc(10240);
	snprintf(buf, sizeof(buf), "%d", this->size);
	if(strcmp(this->code.c_str(), "200 OK") == 0)
	{

		buffer2 = this->req->getHttp_version() + " " + this->code + "\n" + "Host: " + this->req->getHost() + "\n" + "Date: " + this->date 
		+ "\n" 	+ /*"Last-Modified: " + this->lastModifiedDate + "\n" + */ "Content-Length: " + buf + "\n" + "Content-Type:" + 
    	this->req->getType() + "\n\n";
    	this->header_size = strlen(buffer2.c_str());
    	buffer2 += this->data;
	}
	else if(strcmp(this->code.c_str(), "301 Moved Permanently") == 0)
	{
		buffer2 = this->req->getHttp_version() + " " + this->code + "\n" + "Host: " + this->req->getHost() + "\n" + "Date: " + this->date 
		+ "\n" + "Location: " + this->fd.c_str() + "\n" + /*"Last-Modified: " + this->lastModifiedDate + "\n" + */
		 "Content-Length: " + buf + "\n" + "Content-Type:" + this->req->getType() + "\n\n";
		 this->header_size = strlen(buffer2.c_str());
		 buffer2 += this->data;
	}
    else if(strcmp(this->code.c_str(), "400 Bad Request") == 0)
    {
    	buffer2 = this->req->getHttp_version() + " " + this->code + "\n" + "Host: " + this->req->getHost() + "\n" + "Date: " + this->date
    	+ "\n" + "Content-Length: " + buf + "\n" + "Content-Type:" + this->req->getType() + "\n\n";
    	this->header_size = strlen(buffer2.c_str());
    	buffer2 += this->data;
    }
    else if(strcmp(this->code.c_str(), "404 Not Found") == 0)
    {
    	buffer2 = this->req->getHttp_version() + " " + this->code + "\n" + "Host: " + this->req->getHost() + "\n" + "Date: " + this->date
    	+ "\n" + "Content-Length: " + buf + "\n" + "Content-Type:" + this->req->getType() + "\n\n"; 
    	this->header_size = strlen(buffer2.c_str());
    	buffer2 += this->data;
    }	
    else if(strcmp(this->code.c_str(), "505 HTTP Version Not Supported") == 0)
	{

		buffer2 = "HTTP/1.1 " + this->code + "\n" + "Host: " + this->req->getHost() + "\n" + "Date: " + this->date 
		+ "\n" 	+ /*"Last-Modified: " + this->lastModifiedDate + "\n" + */ "Content-Length: " + buf + "\n" + "Content-Type:" + 
    	this->req->getType() + "\n\n";
    	this->header_size = strlen(buffer2.c_str());
    	buffer2 += this->data;
	}
    free(buf);
	return buffer2;
}

/* Esse método existe simplesmente para facilitar a depuração do código, imprimindo todos os atributos do objeto */
void Response::print()
{
	cout << "http: " << this->req->getHttp_version() << endl;
	cout << "sinal: " << this->code << endl;
	cout << "data: " << this->date << endl;
	cout << "ultima modificacao: " << lastModifiedDate << endl;
	cout << "data length: "<< size << endl;
	cout << "dados strlen: " << strlen(data.c_str()) << endl;
	cout << "contentType: " << this->req->getType() << endl;
	cout << "fd: " << fd << endl;
}

/* Aqui, devemos ser responsáveis por separar as variáveis contidas no método post e repassá-las ao arquivo que será enviado
ao cliente */
void Response::POSTResponse()
{
	std::string temp, name, value;
	temp.assign(this->req->getPost());
	for(int i = strlen(this->req->getPost().c_str()); i >= 0; i--)
	{
		// Comparamos i com o número 4294967295 pois o tipo da variável é unisgned int
		while(i >= 0 && temp[i] != '=')
		{
			if(temp[i] == '+')
				name.append(1, ' ');
			else
				name.append(1, temp[i]);
			i--;
		}
		i--;
		while(i >= 0 && temp[i] != '&')
		{
			value.append(1, temp[i]);
			i--;
		}
		std::reverse(name.begin(), name.end());
		std::reverse(value.begin(), value.end());
		/* A funcionalidade das variáveis "name" e "value" é explicada abaixo, nos comentários que antecedem o método "fillIn" */
		fillIn(name, value);
		value.clear();
		name.clear();
	}
}

/* Aqui, a substituição do arquivo "actions.php" é realizada, onde os campos a serem substituídos são similares à variável 
"$_POST" de arquivos php, contendo dentro dos colchetes os valores 'Curso' e 'Faculdade'. O parâmetro "value" identifica esse campo,
e "name" diz qual será o texto (enviado via navegador) a ser trocado. Caso queira, o leitor pode substituir o arquivo "post.html", 
entretando, o arquivo "actions.php" DEVE ser modificado de maneira a conter dentro de seus colchetes os respectivos atributos 
"name" da tag "<input></input>" */
void Response::fillIn(std::string name, std::string value)
{
	std::string p, trocar;
	p.assign("$_POST[\'");
	p = p + value + "\']";
	trocar.assign(name);
	std::size_t found = 0, substr = strlen(p.c_str());
	while(found < strlen(this->data.c_str()) && found != std::string::npos)
	{
		found = this->data.find(p, found+1);
		if(found != std::string::npos)
		{
			this->data.replace(found, substr, trocar);
		}
	}
}

/* É retornada uma "std::string" contendo os dados a serem transmitidos na decorrência de um sinal "400" ser enviado */
std::string Response::badRequest()
{
	std::string bad;
	bad.append("<!DOCTYPE html>\n<html>\n<head>\n<title> 400 Bad request </title>\n<meta charset = \"UTF-8\" >\n</head>\n<body>\n<h1> Bad request </h1>\n");
	bad.append("<p> A requisição não foi entendida pelo servidor.</p>\n</body>\n</html>");
	return (bad.c_str());
}

/* É retornada uma "std::string" contendo os dados a serem transmitidos na decorrência de um sinal "404" ser enviado */
std::string Response::notFound()
{
	std::string no;
	no.append("<!DOCTYPE html>\n<html>\n<head>\n<title> 404 Not Found </title>\n<meta charset = \"UTF-8\" >\n</head>\n<body>\n<h1> Not Found </h1>\n");
	no.append("<p> A página requisitada não foi encontrada.</p>\n</body>\n</html>");
	return (no.c_str());
}

/* É retornada uma "std::string" contendo os dados a serem transmitidos na decorrência de um sinal "505" ser enviado */
std::string Response::httpVersion()
{
	std::string http;
	http.append("<!DOCTYPE html>\n<html>\n<head>\n<title> 505 HTTP Version Not Supported </title>\n<meta charset = \"UTF-8\" >\n</head>\n<body>\n<h1> HTTP Version Not Supported </h1>\n");
	http.append("<p> Esse servidor só aceita o protocolo HTTP 1.1. Por favor, atualize seu navegador assim que possível.</p>\n</body>\n</html>");
	return (http.c_str());
}