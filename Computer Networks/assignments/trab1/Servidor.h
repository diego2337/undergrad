#ifndef __SERVIDOR_H
#define __SERVIDOR_H

#define LISTENQ 25
#include <stdio.h>
#include <sys/socket.h>
#include <netdb.h>
#include <errno.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <list>

#include <iostream>
using namespace std;
typedef struct sockaddr_in sock;
extern pthread_mutex_t mymutex;

void* run2(void*);
/* A classe Servidor será responsável por descrever um socket ao qual ele definirá sua disponibilidade de serviços e
escutará para possíveis conexões de navegadores que requisitam páginas em html. O protocolo de transporte utilizado
é o TCP. */
class Servidor
{
public:
	sock server_addr;
	int sckt;
	/* Construtor padrão - se nenhuma porta for passada como argumento da linha de comando então a porta especificada
	é a 8080 */
	Servidor(int port = 8080)
	{
		/* Inicializando a estrutura */
		bzero(&server_addr, sizeof(server_addr));
		server_addr.sin_family = AF_INET;
		server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
		server_addr.sin_port = htons(port);
		/* Criação do socket */
		if((sckt =  socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
		{
			printf("Falha ao criar o socket.\n");
  			exit(0);
		}
		/* O método "bind" é responsável por alocar uma porta à aplicação em questão */
		if((bind(sckt, (sockaddr*)&server_addr, sizeof(server_addr)) < 0))
		{
			printf("Falha ao associar uma porta ao socket.\n");
  			exit(0);
		}
		/* Esse procedimento tem como função verificar se algum cliente deseja se conectar ao servidor */
		if((listen(sckt, LISTENQ)) < 0)
		{
			printf("Falha ao escutar requisições da porta.\n");
  			exit(0);
		}
	}

	Servidor operator =(const Servidor&);
	void error(string);
	void run();
	void request(int, sock);
};

struct requestParams
{
	sock s;
	int integer;
	Servidor self;
};

#endif