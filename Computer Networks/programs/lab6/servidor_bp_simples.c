#include <stdio.h>          /* printf */
#include <stdlib.h>         /* exit */
#include <string.h>         /* bzero */
#include <sys/socket.h>     /* recv, send */
#include <arpa/inet.h>      /* struct sockaddr */
#include <unistd.h>         /* exit */

#define BUFFSIZE 32
#define MAXPENDING 5
#define SA struct sockaddr

void error(char *msg);

/* O programa "servidor_bp_simples.c" tem como principal função criar um socket, estabelecer uma porta e escutar 
possíveis clientes que queiram se conectar com ele. Ao aceitar uma conexão, o programa irá executar um bate papo simples,
onde o número máximo de letras é limitado a 20, e uma palavra por vez pode ser enviada. Somente um cliente pode se conectar 
ao servidor para realizar o bate papo, e caso o servidor digite a palavra "sair" a porta que ele abriu será fechada e ambos 
terminarão sua execução. */
int main(int argc, char *argv[])
{
  int listenfd, connfd, clientlen, n;
  char bufferin[BUFFSIZE], bufferout[BUFFSIZE];
  struct sockaddr_in servaddr, client;
  /* As condicoes abaixo testam se os argumentos da linha de comando foram passados corretamente e se o socket pode ser criado*/
  if(argc != 2)
    error("Use: SERVERecho <porta>");
  
  if((listenfd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
    error("Falha ao criar o socket");
  /* Aqui, a estrutura "sockaddr_in" é inicializada */
  bzero(&servaddr, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
  servaddr.sin_port = htons(atoi(argv[1]));
  /* O metodo "bind" é responsável por alocar uma porta a aplicação "servidor_bp_simples" em questão */
  if(bind(listenfd, (SA *) &servaddr, sizeof(servaddr)) < 0)
    error("Falha ao observar o socket do servidor");
  /* Esse metodo tem como função verificar se algum cliente deseja se conectar ao servidor */
  if(listen(listenfd, MAXPENDING) < 0)
    error("Falha ao tentar escutar o socket do servidor");
  /* Mantém o bate papo aberto até que receba o sinal "SIGINT" */
  for( ; ; )
    {

      n = -1;
      clientlen = sizeof(client);

      if((connfd = accept(listenfd, (SA *) &client, &clientlen)) < 0)
      error("Falhou ao aceitar a conexao do cliente");
      printf("iteracao do for;;;\n");
      do
      {
        /* Recebendo a msg do cliente */
        if((n = recv(connfd, bufferout, BUFFSIZE, 0)) < 0)
          error("Falhou ao receber os dados iniciais do cliente");
        bufferout[n] = 0;
        printf("%s: %s\n", inet_ntoa(client.sin_addr), bufferout);

         printf("Servidor:");
         scanf("%20s", bufferin);
         /* Aqui, o servidor envia uma mensagem de volta ao cliente */
         if(send(connfd, bufferin, strlen(bufferin), 0)!= strlen(bufferin))
           error("Falha ao enviar todos os bytes para o servidor");

      }while(strcmp(bufferin, "sair"));
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