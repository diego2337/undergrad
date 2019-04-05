
#include <stdio.h>
#include <sys/socket.h>        /* API para sockets */
#include <arpa/inet.h>         /* Estrutura sockaddr */
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>           /* Threads Posix */

#define MAXPENDING 10

/* Struct para passagem de parâmetros para Thread */

struct TA  
{ 
	int cSock; 
	int pos;
};

void *TrataClienteThread(void *);	

erro(char *msg)
{
	printf("%s",msg);
	exit(1);
}

	int clientes[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};

/* O programa descrito em "servidor_eco_multi.c" tem como principal função aceitar conexões vindas de outros clientes através da 
criação de threads, aonde o tratamento para cada cliente é dado. Ao receber uma mensagem de um cliente, ela deve ser encaminhada
a todos os outros que estão conectados ao servidor, e caso o servidor pare de executar então todos os clientes devem ter suas
conexões finalizadas. */
main()
{
	int clientSock, tamr;
	int flag, i = 0, j = 0;
	pthread_t tID;
	struct TA *ta;
	int servSock;
	bool cheio = true;
	unsigned int csize;

	/* 1) Cria o socket */
	
	servSock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

	if(servSock < 0) 
		erro("Erro na criacao do socket");

	/* 2) Efetua o bind na porta e entra em modo de escuta */

	struct sockaddr_in s,c;
	int portaServidor = 9001;

	memset(&s, 0, sizeof(s));                      /* zera a estrutura */
	s.sin_family = AF_INET;                        /* Endereços IPv4 */

	s.sin_addr.s_addr = htonl(INADDR_ANY);         /* Qualquer interface do servidor*/
	s.sin_port = htons(portaServidor);             /* Porta */

	flag = bind(servSock, (struct sockaddr *) &s, sizeof(s));
    	if(flag < 0) 
		erro("Erro na execucao do bind");

	flag = listen(servSock, MAXPENDING);
	if(flag < 0) 
		erro("Erro ao entrar em modo listen");

	/* 3) Loop para Aguardar Clientes */

	printf("Aguardando Clientes\n");

	while(1)
	{
		csize = sizeof(c);
        clientSock = accept(servSock, (struct sockaddr *) &c, &csize);
        if(clientSock < 0) 
        	erro("Erro ao receber um accept");

		/* Código para Tratar o Cliente */
		ta = (struct TA *) malloc(sizeof(struct TA));
		ta->cSock = clientSock;
		/* Procura uma posição vazia para o cliente */
		for(j = 0 ; j < 10; j++)
		{
			if(clientes[j] == -1)
			{
				i = j;
				cheio = false;
			}
		}
		/* Caso nenhuma posição tenha sido encontrada previamente, então a capacidade de atendimento aos clientes chegou ao máximo
		e qualquer outra conexão deve ser desconsiderada */
		if(cheio)
		{
			printf("Não há como atender mais clientes.\n");
			close(clientSock);
		}
		else
		{
			ta->pos = i;
			printf("recebi um accept: %d\n",clientSock);
			clientes[i] = clientSock;
			flag = pthread_create(&tID, NULL, TrataClienteThread, (void*)ta);

			if(flag != 0) 
				erro("Erro na criacao da Thread");
			else 
				printf("Criei uma thread\n");
			cheio = true;
		}
	}

}


/* 1) Declaração da Função Thread*/

void *TrataClienteThread(void *ptr)
{
	int tamr, j, p;
	char buffer[100];
	int csock = 0;

	csock = ((struct TA *) ptr)->cSock;
	p = ((struct TA *) ptr)->pos;
	free(ptr);
	printf("Thread do socket %d iniciada\n",csock);
 

 /* 2) Corpo da Thread */
	while(1)
	{		
		tamr = read(csock, buffer, 100);
		if(tamr <= 0) 
        {
			printf("Thread %d encerrou\n",csock);
        		break;
      	}

		buffer[tamr] = 0;
		printf("%d: %s", csock, buffer);
		/* Enviando a mensagem para os outros clientes */
		for(j = 0; j < 10; j++)
		{
			if(clientes[j] != -1 && j != p)
			{
				tamr = write(clientes[j],buffer,100);
				if(tamr <= 0)
				{
					error("nao enviou\n");
				}
				printf("Mensagem enviada para %d\n", clientes[j]);
				if(tamr == strlen(buffer))
					printf("Mensagem enviada\n");
			}
		}
	}
	clientes[p] = -1;
	close(clientes[p]);
	return NULL;
}
