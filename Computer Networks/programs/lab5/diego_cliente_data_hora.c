#include <time.h>
#include <stdio.h>          /* printf */
#include <stdlib.h>         /* exit */
#include <string.h>         /* bzero */
#include <sys/socket.h>     /* recv, send */
#include <arpa/inet.h>      /* struct sockaddr */
#include <unistd.h>         /* exit */

#define MAXLINE 4096
#define SA struct sockaddr

void error(char *msg)
{
  printf("%s\n", msg);
  exit(0);

  return;
}

/* O programa "cliente_data_hora.c" tem como função criar um socket e tentar se conectar com um servidor que esteja apto a aceitar 
conexões. Após essa conexão, o cliente recebe a data e hora atuais do servidor. */
int main(int argc, char **argv)
{
	int					sockfd, n;
	char				recvline[MAXLINE + 1];
	struct sockaddr_in	servaddr;
	/* As condições abaixo testam se os argumentos da linha de comando foram passados corretamente e se o socket pode ser criado*/
	if (argc != 3)
		error("usage: client <IPaddress> <Port>");

	if ( (sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		error("socket error");
	/* Inicializando a estrutura */
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port   = htons(atoi(argv[2]));	/* daytime server */
	if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0)
		error("inet_pton error for");
	/* Estabelecendo conexao */
	if (connect(sockfd, (SA *) &servaddr, sizeof(servaddr)) < 0)
		error("connect error");

	while ( (n = read(sockfd, recvline, MAXLINE)) > 0)
	{
		recvline[n] = 0;	/* null terminate */
		if (fputs(recvline, stdout) == EOF)
			error("fputs error");
	}
	if (n < 0)
		error("read error");
	/* O socket criado pelo cliente é destruido */
	close(sockfd);
	exit(0);
}

