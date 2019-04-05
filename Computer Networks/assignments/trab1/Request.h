#ifndef __REQUEST_H
#define __REQUEST_H

#ifndef __SERVIDOR_H
#include "Servidor.h"
#endif
#include <string>
#include <algorithm>

/* Essa diretiva será utilizada somente no método "getCurrentDir" */
#define GCDir getcwd

/* A classe Request tem como principal funcionalidade a verificação do cabeçalho de requisição do navegador, organizando em campos 
(definidos como seus atributos) cada um dos aspectos que serão analisados pelo servidor. */
class Request
{
private:
	std::string method, file, path, originalPath, http_version, host, type, post;
public:
	bool alive;
	Request()
	{
		method.assign(" ");
		file.assign(" ");
		http_version.assign(" ");
		host.assign(" ");
		type.assign(" ");
		path.assign(" ");
		originalPath.assign(" ");
		post.assign(" ");
		alive = true;
	}
	Request(char *buffer, unsigned short int);
	Request operator =(const Request&);
	void print();
	std::string getCurrentDir(std::string) const; 
	std::string getMethod();
	std::string getFile();
	std::string getPath();
	void setPath(std::string);
	std::string getOriginalPath();
	std::string getHttp_version();
	std::string getHost();
	std::string getType();
	std::string getPost();
};
#endif