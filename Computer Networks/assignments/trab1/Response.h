#ifndef __RESPONSE_H
#define __RESPONSE_H

#ifndef __REQUEST_H
#include "Request.h"
#endif

#include <fstream>
#include <sstream>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>
#include <vector>

/* Na classe Response encontram-se todos os métodos necessários para montar-se uma resposta do servidor adequada ao navegador,
contendo cabeçalho e dados. */
class Response
{
public:
	Request *req;
	std::string code, date, lastModifiedDate, data, fd;
	std::vector<std::string> files;
	std::vector<char> buff;
	int size, header_size;
	Response(Request& requisicao)
	{
		req = new Request();
		/* Cópia profunda */
		*(req) = requisicao;
		this->fd.append(this->req->getPath());
		this->fd.append(this->req->getFile());
		size = header_size = 0;
	}
	~Response()
	{
		delete req;
	}
	std::string mountResponse();
	std::string toStr();
	bool searchFile(int);
	std::string getDate();
	std::string getLastModifiedDate();
	std::string badRequest();
	std::string notFound();
	std::string httpVersion();
	std::string getResponse();
	void moved();
	void listDirectory();
	void fillIn(std::string, std::string);
	void getData();
	void findDirectory(const char*, int, std::string&, int);
	void getContentLength();
	void print();
	void POSTResponse();
};
#endif