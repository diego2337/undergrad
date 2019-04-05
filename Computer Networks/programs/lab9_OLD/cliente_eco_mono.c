
#include <stdio.h>
#include <sys/socket.h>		/* API para sockets */
#include <arpa/inet.h>          /* Estrutura sockaddr */
#include <string.h>
#include <stdlib.h>
#include <unistd.h>             /* para close() */


#define MAXLINE 200

erro(char *s)
{
	printf("%s\n",s);
	exit(1);
}

main()
{
	/* 1) Cria o socket */
	
	int clientSock;
	int flag;
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

	/* 3) Transmite os dados */

	while(1)
	{
		fgets(buffer,MAXLINE,stdin);
		tams = write(clientSock,buffer,strlen(buffer));
		if(tams == strlen(buffer))
			printf("Mensagem enviada\n");
		else
			break;
	} 

	/* 4) Encerra o socket */
	
	printf("Erro no servidor\n");
	flag = close(clientSock);
	if(flag < 0) 
		erro("Erro ao encerrar o socket");
	else
		erro("Cliente ecerrado");

}
