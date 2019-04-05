
#include <stdio.h>
#include <sys/socket.h>		/* API para sockets */
#include <arpa/inet.h>          /* Estrutura sockaddr */
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>             /* para close() */


#define MAXLINE 200

struct client 
{
	int cliente;
	char *buff;
};

erro(char *s)
{
	printf("%s\n",s);
	exit(1);
}

/* Essa thread será responsável por gerenciar as entradas do cliente */
void *keyboard(void *ptr)
{
	int client = *(int*)ptr;
	int tams;
	char buffer[MAXLINE];
	while(strcmp(buffer, "sair\n") != 0)
	{
		memset(buffer, 0, sizeof buffer);
		fgets(buffer,MAXLINE,stdin);
		tams = write(client,buffer,strlen(buffer));
		if(tams == strlen(buffer))
			printf("Mensagem enviada\n");
		else
			exit(0);
	}
}

/* A thread em questão monitorará o envio de mensagens por parte do servidor */
void *ler(void *ptr)
{
	int client = *(int*)ptr;
	int tams;
	char buffer[MAXLINE];
	pthread_detach(pthread_self());
	while(1)
	{
		if((tams = recv(client, buffer, 200, 0)) <= 0)
		{
			erro("Conexão finalizada.");
		}
		buffer[tams] = '\0';
		printf("Cliente recebeu do servidor: %s", buffer);
		memset(buffer, 0, sizeof buffer);
	}
}

/* Esse programa tem como principal funcionalidade a conexão a um servidor e o envio de mensagens a ele. Duas threads aqui são 
criadas, uma para receber mensagens e outra para enviá-las. Caso a mensagem digitada seja "sair", o cliente que a enviou terá
sua conexão finalizada, e caso o servidor a que esteja associado deixe de executar, essa conexão também deve parar. */
main()
{
	/* 1) Cria o socket */
	
	int clientSock;
	int flag, flg2, flg3;
	pthread_t tID, tID2;
	unsigned int tams;
	char buffer[MAXLINE];
	clientSock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	if(clientSock < 0) 
		erro("Erro na criacao do socket");
	
	/* 2) Efetua a conexão com o servidor */
	
	struct sockaddr_in s;
	int portaServidor = 9001;
	
	memset(&s, 0, sizeof(s));                          /* zera a estrutura */
	s.sin_family = AF_INET;                            /* Endereços IPv4 */
	s.sin_addr.s_addr = inet_addr("127.0.0.1");        /* Local Host */
	s.sin_port = htons(portaServidor);                 /* Porta */
	
	flag = connect(clientSock, (struct sockaddr *) &s, sizeof(s));
	if(flag < 0) erro("Erro na execucao do connect");

	/* 3) Cria threads para transmitir e receber os dados */
	flg2 = pthread_create(&tID, NULL, keyboard, (void*)&clientSock);
	if(flg2 < 0)
	{
		error("Erro na criação da thread de escrita\n");
	}
	flg3 = pthread_create(&tID2, NULL, ler, (void*)&clientSock);
	if(flg3 < 0)
	{
		error("Erro na criação da thread de leitura\n");
	}
	pthread_join(tID, NULL);
	/* 4) Encerra o socket */
	flag = close(clientSock);
	if(flag < 0) 
		erro("Erro ao encerrar o socket");
	else
		erro("Cliente encerrado");
	exit(0);

}
