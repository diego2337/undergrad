#ifndef __REQUEST_H
#include "Request.h"
#endif 

#ifndef __RESPONSE_H
#include "Response.h"
#endif

/* Nesse construtor, basicamente iremos organizar todo o cabeçalho */
Request::Request(char *buffer, unsigned short int port)
	{
		int aux;
		std::string temp;
		char hostname[1024];
		struct hostent* h;
		/* Verificamos se a requisição é "GET" ou "POST" */
		if(buffer[0] == 'G')
		{
			method.assign("GET");
		}
		else if(buffer[0] == 'P')
		{
			method.assign("POST");
			for(unsigned int i = strlen(buffer); i != 4294967295 && buffer[i] != '\n'; i--)
			{
				post.append(1, buffer[i]);
			}
			std::reverse(post.begin(), post.end());
		}
		else
		{
			method.assign("BAD");
		}
		/* Devemos armazenar qual tipo de arquivo o navegador pode aceitar - por ser um trabalho simples, somento o primeiro
		tipo é salvo */
		for(unsigned int i = 0; i < strlen(buffer); i++)
		{
			if(buffer[i] == 'A' && buffer[i+1] == 'c' && buffer[i+2] == 'c' && buffer[i+3] == 'e' && buffer[i+4] == 'p'
				&& buffer[i+5] == 't' && buffer[i+6] == ':')
			{
				aux = i+7;
				i = strlen(buffer);
				while(buffer[aux] != '/')
				{
					type.append(1, buffer[aux]);
					aux++;
				}
				aux++;
				while(buffer[aux] != ',')
				{
					temp.append(1, buffer[aux]);
					aux++;
				}
				type = type + '/' + temp;
			}
		}
		/* Encontra-se aqui o nome do arquivo mais sua extensão e o caminho dele */
		for(unsigned int i = 0; i < strlen(buffer); i++)
		{
			if(buffer[i] == '/')
			{
				aux = i;
				i = strlen(buffer);
				while(buffer[aux] != ' ')
				{
					path.append(1, buffer[aux]);
					aux++;
				}
				unsigned int z = path.size();
				unsigned int z2 = z;
				while(buffer[aux] != '/')
				{
					file.append(1, buffer[aux]);
					aux--;
					z2--;
				}
				path.erase((z2+1), z);
				std::reverse(file.begin(), file.end());
				char lixo[] = " ";
				for(unsigned int j = 0; j < strlen(lixo); j++)
				{
					file.erase(std::remove(file.begin(), file.end(), lixo[j]), file.end());
				}
			}	
		}
		/* Essa atribuição é feita pois, caso ele saia do laço sem receber qualquer atribuição, então foi requisitado um diretório */
		if(file.empty())
		{
			file.assign("directory");
		}
		/* O protocolo HTTP do navegador é buscado */
		for(unsigned int i = 0; i < strlen(buffer); i++)
		{
			if(buffer[i] == 'H' && buffer[i+1] == 'T' && buffer[i+2] == 'T' && buffer[i+3] == 'P')
			{
				/* A palavra 'HTTP' foi encontrada */
				aux = i+1;
				http_version.append(1, 'H');
				while(buffer[aux] != '\r')
				{
					http_version.append(1, buffer[aux]);
					aux++;
				}
			}
		}
		/* O campo "host" deve ser identificado utilizando-se as funções "gethostname" e "gethostbyname" */
		hostname[1023] = '\0';
		gethostname(hostname, 1023);
		h = gethostbyname(hostname);
		if(h == NULL)
		{
			for(unsigned int i = 0 ; i < strlen(buffer); i++)
			{
				if(buffer[i] == 'H' && buffer[i+1] == 'o' && buffer[i+2] == 's' && buffer[i+3] == 't')
				{
					aux = i+6;
					while(buffer[aux] != '\n')
					{
					host.append(1, buffer[aux]);
					aux++;
					}
				}
			}
		}
		else
		{
			host.assign(h->h_name);
			snprintf(hostname, sizeof(hostname), "%d", port);
			host.append(":");
			host.append(hostname);
		}
		/* O campo "Connection" identifica se o navegador ainda irá requisitar mais arquivos ou está terminando sua requisição */
		for(unsigned int i = 0 ; i < strlen(buffer); i++)
		{
			if(buffer[i] == 'C' && buffer[i+1] == 'o' && buffer[i+2] == 'n' && buffer[i+3] == 'n' && buffer[i+4] == 'e'
				&& buffer[i+5] == 'c' && buffer[i+6] == 't' && buffer[i+7] == 'i' && buffer[i+8] == 'o' && buffer[i+9] == 'n')
			{
				aux = i + 11;
				i = strlen(buffer);
				temp.clear();
				while(buffer[aux] != '\n')
				{
					temp.append(1, buffer[aux]);
					aux++;
				}
				char lixo[] = " ";
				for(unsigned int j = 0; j < strlen(lixo); j++)
				{
					temp.erase(std::remove(temp.begin(), temp.end(), temp[j]), temp.end());
				}
				if(strcmp(temp.c_str(), "keep-alive") > 0)
				{
					this->alive = true;
				}
				else
				{
					this->alive = false;
				}
			}
		}
	}

/* Esse método existe simplesmente para facilitar a depuração do código, imprimindo todos os atributos do objeto */
void Request::print()
{
	cout << "method: " << this->method << endl;
	cout << "file: " << this->file << endl;
	cout << "path: " << this->path << endl;
	cout << "http: " << this->http_version << endl;
	cout << "post: " << this->post << endl;

}

/* Aqui, busca-se o caminho onde se encontra o arquivo requisitado (denominado por algumas literaturas de caminho absoluto) */
std::string Request::getCurrentDir(std::string path) const
{
	char currentPath[FILENAME_MAX];
	char *aux;
	std::string tmp;
	if(!GCDir(currentPath, sizeof(currentPath)))
	{
		cout << "O caminho não pôde ser especificado. " << endl;
	}
	currentPath[sizeof(currentPath) - 1] = '\0';
	aux = currentPath;
	strcat(aux, path.c_str());
	tmp.assign(aux);
	return tmp;
}

/* Uma sobrecarga do operador "=" é implementada abaixo para cópia profunda, que será utilizada no construtor de um objeto do tipo 
"Response" */
Request Request::operator =(const Request& r)
{
	this->method.assign(r.method);
	this->file.assign(r.file);
	this->path.assign(r.path);
	this->originalPath.assign(r.originalPath);
	this->http_version.assign(r.http_version);
	this->host.assign(r.host);
	this->type.assign(r.type);
	this->post.assign(r.post);
	this->alive = r.alive;
	return *this;
}

std::string Request::getMethod()
{
	return this->method;
}

std::string Request::getFile()
{
	return this->file;
}

std::string Request::getPath()
{
	return this->path;
}

void Request::setPath(std::string caminho)
{
	this->path.assign(caminho);
}

std::string Request::getOriginalPath()
{
	return this->originalPath;
}

std::string Request::getHttp_version()
{
	return this->http_version;
}

std::string Request::getHost()
{
	return this->host;
}

std::string Request::getType()
{
	return this->type;
}

std::string Request::getPost()
{
	return this->post;
}