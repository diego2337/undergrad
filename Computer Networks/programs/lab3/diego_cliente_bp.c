#include <stdio.h>          /* printf */
#include <stdlib.h>         /* exit */
#include <string.h>         /* bzero */
#include <sys/socket.h>     /* struct sockaddr, socket */
#include <netinet/in.h>     /* struct sockaddr_in */
#include <arpa/inet.h>      /* inet_pton, htons */
#include <unistd.h>         /* read */

#define BUFFSIZE 100
#define MAXPENDING 5
#define SA struct sockaddr

void error(char *msg);

/* O programa "cliente_bp.c" tem como principal função criar um socket e tentar se conectar com um servidor que esteja apto a 
aceitar conexões. Após essa conexão, um bate papo simples é iniciado, onde somente uma palavra pode ser enviada, contendo no 
máximo 100 letras e sempre alternando entre cliente e servidor; caso o cliente digite ou receba a palavra "sair", então a conexão
entre o servidor e ele será finalizada e a execução do processo iniciado pelo cliente também será terminada. */
int main(int argc, char *argv[])
{
  int sockfd, bytes = 0;
  struct sockaddr_in servaddr;
  char buffer[BUFFSIZE], palavra[100];
  unsigned int echolen;
  /* As condicoes abaixam testam se os argumentos da linha de comando foram passados corretamente e se o socket pode ser criado*/
  if (argc != 3)
    error("Use: TCPecho <server_ip> <porta>");
  
  if((sockfd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
    error("Falha ao criar o socket");
  
  /* Inicializando a estrutura */
  bzero(&servaddr, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = inet_addr(argv[1]);
  servaddr.sin_port = htons(atoi(argv[2]));

  /* Estabelecendo conexao */
  if (connect(sockfd, (SA *) &servaddr, sizeof(servaddr)) < 0)
    error("Falha ao conectar ao servidor");
  
  printf("Conexão estabelecida. Bate papo iniciado. (PALAVRAS NAO DEVEM TER MAIS QUE 100 CARACTERES)\n");
  /* Aqui, com o bate papo iniciado, pode-se enviar uma palavra e receber outra do servidor. Caso ou o cliente ou o servidor mandem a 
  palavra "sair", o processo iniciado pelo cliente tem de ser finalizado, e a conexão entre ambos encerrada */
  while(strcmp(buffer, "sair") != 0)
  {
    /* O memset é utilizado aqui para evitar com que palavras recebidas anteriormente (armazenadas na variável "buffer") sejam 
    concatenadas com novas, caso essas venham a ser menores (por exemplo, se a palavra anterior fosse "abacaxi" e agora o cliente
    recebesse "ddd", sem o memset isso resultaria em "dddcaxi") */
    memset(buffer, 0, sizeof buffer);
    printf("Cliente: ");
    scanf("%s", palavra);
    echolen = strlen(palavra);
    if (send(sockfd, palavra, echolen, 0) != echolen)
      error("Falhou ao enviar todos os bytes");
    if(strcmp(palavra, "sair") == 0)
    {
      break;
    }
    /* Recebendo a palavra como resposta do servidor */
    printf("Servidor diz: ");
      if((bytes = recv(sockfd, buffer, BUFFSIZE-1, 0)) < 1)
        error("Falhou ao receber os bytes do servidor");
      printf("%s", buffer);
    printf("\n");
  }
  /* O socket criado pelo cliente é destruido */
  close(sockfd);
  exit(0);
}

/* Imprime mensagens de erro */
void error(char *msg)
{
  printf("%s\n", msg);
  exit(0);

  return;
}
