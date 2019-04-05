#include <time.h>
#include <stdio.h>          /* printf */
#include <stdlib.h>         /* exit */
#include <string.h>         /* bzero */
#include <sys/socket.h>     /* recv, send */
#include <arpa/inet.h>      /* struct sockaddr */
#include <unistd.h>         /* exit */

#define MAXLINE 1024
#define SA struct sockaddr
#define LISTENQ 10

void error(char *msg)
{
  printf("%s\n", msg);
  exit(0);

  return;
}
/* O programa "servidor_data_hora.c" é um programa simples que, ao criar um socket, estabelece uma porta e escuta possíveis clientes 
que queiram se conectar com ele. Quando essa conexão é feita, através do uso da função "fork()", uma cópia do programa é feita na 
memória (processo "filho"), que será responsável por tratar diferentes clientes concorrentemente. O servidor dá ao cliente a data
e hora atual. */
int main(int argc, char **argv)
{
	int			listenfd, connfd, clientlen;
	struct sockaddr_in	servaddr, client;
	char			buff[MAXLINE];
	time_t			ticks;
	pid_t id;
	/* As condições abaixo testam se os argumentos da linha de comando foram passados corretamente e se o socket pode ser criado*/
	if(argc != 2)
	    error("Use: server <port>");

	if((listenfd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
    	error("Falha ao criar o socket");
    /* Inicializando a estrutura */
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family      = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port        = htons(atoi(argv[1])); /* daytime server */
	/* O método "bind" é responsável por alocar uma porta a aplicação "servidor_data_hora" em questão */
	bind(listenfd, (SA *) &servaddr, sizeof(servaddr));
	/* Esse método tem como função verificar se algum cliente deseja se conectar ao servidor */
	listen(listenfd, LISTENQ);

	for ( ; ; ) 
	{
		connfd = accept(listenfd, (SA *) &client, &clientlen);
		/* Após aceitar a conexão com um cliente, o servidor determina um novo socket relativo a conexão de ambos e cria um novo 
		processo para tratar tal relação, através da função fork() - agora, o processo "pai" está livre para aceitar conexões
		com outros clientes paralelamente */
		if((id = fork()) == 0)
		{
			/* A linha abaixo "libera" o socket responsável por "ouvir" requisições de outros clientes, permitindo o servidor
			ouvir outras requisições de outros clientes */
			close(listenfd);
			/* O servidor informa a hora para o cliente, e aguarda por 5 segundos */
			printf("Cliente connectado: %s:%d\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));
			ticks = time(NULL);
        	snprintf(buff, sizeof(buff), "%.24s\r\n", ctime(&ticks));
        	write(connfd, buff, strlen(buff));
			sleep(5);
			printf("Cliente connectado: %s:%d\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));
			/* Como o cliente terminou o que ele precisava fazer com o servidor, a porta relativa a conexão dos dois é fechada */
			close(connfd);
			/* O processo "filho" termina de executar */
			exit(0);
		}
			
		close(connfd);
	}
}

