
#include <stdio.h>
#include <sys/socket.h>        /* API para sockets */
#include <arpa/inet.h>         /* Estrutura sockaddr */
#include <string.h>
#include <stdlib.h>
#include <pthread.h>           /* Threads Posix */

#define MAXPENDING 6

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


main()
{
	int clientSock;
	int flag, i = 0, j = 0;
	pthread_t tID[10];
	struct TA *ta;
	int servSock;
	unsigned int csize;
	char* buffer;

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
		ta->pos = i;
		printf("recebi um accept: %d\n",clientSock);

		flag = pthread_create(&tID[i], NULL, TrataClienteThread, (void *) ta);

		if(flag != 0) 
			erro("Erro na criacao da Thread");
		else 
			printf("Criei uma thread\n");
		i++;
		pthread_join(tID[i], (void**)buffer);
		for(j = 0; j < 10; j++)
		{
			/*tamr = write(csock,buffer,strlen(buffer));
			if(tamr == strlen(buffer))
				printf("Mensagem enviada\n");*/
		}
	}

}


/* 1) Declaração da Função Thread*/

void *TrataClienteThread(void *ptr)
{
	int tamr;
	char *buffer;
	int csock = 0;

	csock = ((struct TA *) ptr)->cSock;
	free(ptr);
	printf("Thread do socket %d iniciada\n",csock);
 

 /* 2) Corpo da Thread */
	buffer = (char*)malloc(sizeof(char*)*100);
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
		/*tamr = write(csock,buffer,strlen(buffer));
		if(tamr == strlen(buffer))
			printf("Mensagem enviada\n");*/
	}

	pthread_exit(buffer);
}
