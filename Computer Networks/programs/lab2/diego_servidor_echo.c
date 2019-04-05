#include <stdio.h>          /* printf */
#include <stdlib.h>         /* exit */
#include <string.h>         /* bzero */
#include <sys/types.h>
#include <netdb.h>
#include <sys/socket.h>     /* struct sockaddr, socket */
#include <netinet/in.h>     /* struct sockaddr_in */
#include <arpa/inet.h>      /* inet_pton, htons */
#include <unistd.h>         /* read */

#define BUFFSIZE 32
#define MAXPENDING 5
#define SA struct sockaddr

void error(char *msg);

/* O programa "servidor_echo.c" tem como principal funcao criar um socket, estabelecer uma porta para se conectar e escutar 
possiveis clientes que queiram se conectar com ele. */
int main(int argc, char *argv[])
{
  int listenfd, connfd, clientlen, n;
  char buffer[BUFFSIZE];
  char ip4[INET_ADDRSTRLEN];
  struct sockaddr_in servaddr, client;
  /* As condicoes abaixam testam se os argumentos da linha de comando foram passados corretamente e se o socket pode ser criado*/
  if(argc != 2)
    error("Use: nome_executavel <porta>");
  
  if((listenfd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
    error("Falha ao criar o socket");
  /* Aqui, a estrutura "sockaddr_in" é inicializada */
  bzero(&servaddr, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
  servaddr.sin_port = htons(atoi(argv[1]));
  /* O metodo "bind" é responsavel por alocar uma porta a aplicacao "servidor_echo" em questao */
  if(bind(listenfd, (SA *) &servaddr, sizeof(servaddr)) < 0)
    error("Falha ao observar o socket do servidor");
  /* Esse metodo tem como funcao verificar se algum cliente deseja se conectar ao servidor */
  if(listen(listenfd, MAXPENDING) < 0)
    error("Falha ao tentar escutar o socket do servidor");
  /* O servidor ira permanecer ativo ate que o sinal SIG_INTERRUPT (Ctrl+C) seja ativado pelo terminal, devido ao laco "for" abaixo */
  for( ; ; )
  {
    n = -1;
    clientlen = sizeof(client);
    /* A variavel "connfd" ira receber um novo descritor de arquivo socket relativo a essa nova conexao estabelecida, enquanto "client"
    contera o socket relativo ao cliente */
    if((connfd = accept(listenfd, (SA *) &client, &clientlen)) < 0)
	    error("Falhou ao aceitar a conexao do cliente");

    printf("Cliente connectado.\n");
    /* As duas linhas de codigo abaixo mostram o ip a qual o servidor esta relacionado */
    inet_ntop(AF_INET, &(client.sin_addr), ip4, INET_ADDRSTRLEN);
    printf("O endereço IPv4 do cliente é: %s\n", ip4);
    printf("A porta de conexão utilizada pelo cliente é: %hu\n", ntohs(client.sin_port));
    /* O primeiro fluxo de informacoes que o servidor recebe é a mensagem passada pelo cliente */
    if((n = recv(connfd, buffer, BUFFSIZE, 0)) < 0)
	    error("Falhou ao receber os dados iniciais do cliente");

    /* A mensagem "conexao realizada" é encaminhada aqui */
    if(send(connfd, "conexão realizada", strlen("conexão realizada")+1, 0) != strlen("conexão realizada")+1)
      error("Falhou ao enviar os dados de volta para o cliente");
    while(n > 0)
	  { 
      /* Aqui, a mensagem passada pelo cliente é retornada a ele */
	    if(send(connfd, buffer, n, 0) != n)
	      error("Falhou ao enviar os dados de volta para o cliente");

	    if((n = recv(connfd, buffer, BUFFSIZE, 0)) < 0)
	      error("Falhou ao receber os dados restantes do cliente");
	  }
    /* O descritor de socket criado especialmente para essa conexao é finalizado */
    close(connfd);
  }
  exit(0);
}

/* Imprime mensagens de erro */
void error(char *msg)
{
  printf("%s\n", msg);
  exit(0);

  return;
}
