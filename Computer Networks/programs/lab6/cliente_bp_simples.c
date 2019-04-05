#include <stdio.h>          /* printf */
#include <stdlib.h>         /* exit */
#include <string.h>         /* bzero */
#include <sys/socket.h>     /* struct sockaddr, socket */
#include <netinet/in.h>     /* struct sockaddr_in */
#include <arpa/inet.h>      /* inet_pton, htons */
#include <unistd.h>         /* read */
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

#define BUFFSIZE 32
#define SA struct sockaddr

void error(char *msg);
void treat(int sinal);

/* O programa "cliente_bp.c" tem como principal função criar um socket e tentar se conectar com um servidor que esteja apto a 
aceitar conexões. Após essa conexão, um bate papo simples é iniciado, onde somente uma palavra pode ser enviada, contendo no 
máximo 20 letras e sempre alternando entre cliente e servidor; caso o cliente digite ou receba a palavra "sair", então a conexão
entre o servidor e ele será finalizada e a execução do processo iniciado pelo cliente também será terminada. Na ocorrência do 
usuário digitar uma tecla de interrupção (CTRL+C) e enviar um sinal "SIGINT" ao sistema operacional, a função "signal", 
juntamente com a função "treat", serão responsáveis por tratar essa interrupção, questionando o usuário se ele realmente deseja
sair do programa ou não. */
int main(int argc, char *argv[])
{
  int sockfd, received = 0, bytes = 0;;
  struct sockaddr_in servaddr;
  char bufferin[BUFFSIZE], bufferout[BUFFSIZE];
  unsigned int echolen;
  /* As condicoes abaixam testam se os argumentos da linha de comando foram passados corretamente e se o socket pode ser criado*/
  if (argc != 3)
    error("Use: TCPecho <server_ip>  <porta>");
  
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
  /* Aqui, com o bate papo iniciado, pode-se enviar uma palavra e receber outra do servidor. Caso ou o cliente ou o servidor mandem a 
  palavra "sair", o processo iniciado pelo cliente tem de ser finalizado, e a conexão entre ambos encerrada */
  do
  {
    /* A função de captura de sinais está presente logo no começo da iteração do "while", permitindo o tratamento do sinal "SIGINT" */
    signal(SIGINT, treat);
    printf("Eu:");
    scanf("%20s", bufferin);
    if(send(sockfd, bufferin, strlen(bufferin), 0)!= strlen(bufferin))
      error("Falha ao enviar todos os bytes para o servidor");
  
    /* Recebendo a palavra como resposta do servidor */
    if((received = recv(sockfd, bufferout, BUFFSIZE, 0)) < 0)
          error("Falhou ao receber os dados iniciais do cliente");
    bufferout[received] = 0;
    printf("Servidor: %s\n",bufferout);

  }while(strcmp(bufferin,"sair"));
  
  printf("Desconectei!\n");
  /* O socket criado pelo cliente é destruido */
  close(sockfd);
  exit(0);
}

/* Trata o sinal enviado pelo sistema */
void treat(int sinal)
{
  char sair[5];
  printf("Você realmente deseja sair do programa? Digite 'sair' para confirmar.\n");
  scanf("%s", sair);
  if(strcmp(sair, "sair") == 0)
  {
    printf("Finalizando...\n");
    exit(0);
  }
  else
  {
    printf("Retornando ao programa...\n");
    return;
  }
}

/* Imprime mensagens de erro */
void error(char *msg)
{
  printf("%s\n", msg);
  exit(0);

  return;
}

