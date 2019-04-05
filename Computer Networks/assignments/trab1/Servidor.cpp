#ifndef __SERVIDOR_H
#include "Servidor.h"
#endif

#ifndef __REQUEST_H
#include "Request.h"
#endif

#ifndef __RESPONSE_H
#include "Response.h"
#endif

void* run2(void * params)
{
	struct requestParams *r = (struct requestParams*)params;
	r->self.request(r->integer,r->s);
	free(r);
	pthread_detach(pthread_self());
	return NULL;
}

Servidor Servidor::operator =(const Servidor& s)
{
	this->server_addr.sin_family = s.server_addr.sin_family;
	this->server_addr.sin_addr.s_addr = s.server_addr.sin_addr.s_addr;
	this->server_addr.sin_port = s.server_addr.sin_port;
	this->sckt = s.sckt;
	return *this;
}

void Servidor::error(string msg)
{
  cout << msg;
  exit(0);

  return;
}

/* Esse método irá executar por tempo indefinido o servidor web. Para parar, envie um sinal SIGINT (CTRL+C) ao processo. */
void Servidor::run()
{
	socklen_t clientLen;
	pthread_t thread;
	int r_thread;
	sock client;
	struct requestParams *r;
	int accpt;
	for(;;)
	{
		memset(&client, 0, sizeof client);
		accpt = 0;
		clientLen = sizeof(client);
		/* Aqui, aceita-se a conexão com o cliente */
		if((accpt = accept(this->sckt, (sockaddr*)&client, &clientLen)) < 0)
		{
			this->error("A conexão não pôde ser estabelecida.\n");
		}
		/* A estrutura do arquivo "Servidor.h" é inicializada aqui para a criação da thread */
		r = (struct requestParams*)malloc(sizeof(struct requestParams));
		Servidor copia = *this;
		r->s = client;
		r->integer = accpt;
		r->self = copia;
		/* Uma thread é criada para tratar o cliente em questão */
		r_thread = pthread_create(&thread, NULL, &run2, (void*)r);
		if(r_thread)
		{
			fprintf(stderr,"Erro - pthread_create(), código de retorno: %d\n", r_thread);
		}
	}
}

/* Esse método é responsável por receber as requisições do navegador, tratá-las e enviar um cabeçalho de resposta mais o arquivo
requisitado. */
void Servidor::request(int accpt, sock client)
{
	char buffer[10240];
	int config, flag = 1;
	struct timeval option;
	/* Definimos aqui 3 segundos para timeout */
	option.tv_sec = 3;
	option.tv_usec = 0;
	pthread_mutex_init(&mymutex, NULL);
	/* Aqui, dado que o protocolo a ser implementado é o HTTP/1.1, a conexão deve ser persistente, portanto
	um timeout simples é implementado através da função "setsockopt" */
	while(flag)
	{
		memset(&buffer, 0, sizeof buffer);
		pthread_mutex_lock(&mymutex);
		if((config = setsockopt(accpt, SOL_SOCKET, SO_RCVTIMEO, &option, sizeof(option))) < 0)
		{
			this->error("Problema na definição de um tempo de espera da requisição do navegador.\n");
		}
		/* Nesse momento, recebe-se a mensagem ("request") do navegador */
		if((config = recv(accpt, buffer, sizeof(buffer), 0)) < 0)
		{
			//cout << "Tempo de requisição esgotado." << endl;
			break;
		}
		pthread_mutex_unlock(&mymutex);
		/* Os comentarios abaixo foram deixados para testes dos sinais '505' e '400'*/
		/*buffer[22] = 'H';
		buffer[23] = 'T';
		buffer[24] = 'T';
		buffer[25] = 'P';
		buffer[26] = '/';
		buffer[27] = '1';
		buffer[28] = ' ';
		buffer[29] = ' ';*/
		//buffer[0] = 'B';
		/* Um objeto do tipo "Request" é instanciado para análise do cabeçalho advindo do navegador */
		Request requisicao(buffer, server_addr.sin_port);
		if(requisicao.alive == false)
		{
			flag = 0;
		}
		requisicao.setPath(requisicao.getCurrentDir(requisicao.getPath()));
		Response resposta(requisicao);
		memset(&buffer, 0, sizeof buffer);
		memcpy(buffer, resposta.mountResponse().c_str(), (resposta.size+resposta.header_size));
		if((config = send(accpt, resposta.mountResponse().c_str(), (resposta.header_size+resposta.size), 0)) < 0)
		{
			this->error("Falha no envio da resposta ao servidor.\n");
		}
		/* Iremos agora escrever no arquivo de log o IP, método e arquivo requisitados (e em que data e hora essa requisição
		aconteceu) */
		pthread_mutex_lock(&mymutex);
		FILE *f = fopen("log.txt", "a");	
		if(f)
		{
			fprintf(f, "IP do cliente solicitante: %s \t Método requisitado: %s \t Arquivo requisitado: %s \t Data e Hora: %s \n",
			inet_ntoa(client.sin_addr), resposta.req->getMethod().c_str(), resposta.req->getFile().c_str(), resposta.date.c_str());
		}
		fclose(f);
		pthread_mutex_unlock(&mymutex);
	}
	pthread_mutex_destroy(&mymutex);
	close(accpt);
}   