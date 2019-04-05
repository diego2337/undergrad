#include <stdio.h>          /* printf */
#include <stdlib.h>         /* exit */
#include <string.h>         /* bzero */
#include <sys/types.h>
#include <netdb.h>
#include <sys/socket.h>     /* struct sockaddr, socket */
#include <netinet/in.h>     /* struct sockaddr_in */
#include <arpa/inet.h>      /* inet_pton, htons */
#include <unistd.h>         /* read */

#define BUFFSIZE 100
#define MAXPENDING 5
#define SA struct sockaddr

void error(char *msg);

/* O programa "servidor_bp.c" tem como principal função criar um socket, estabelecer uma porta e escutar 
possíveis clientes que queiram se conectar com ele. Ao aceitar uma conexão, o programa irá executar um bate papo simples,
onde o número máximo de letras é limitado a 100, e uma palavra por vez pode ser enviada. Somente um cliente pode se conectar 
ao servidor para realizar o bate papo, e caso o servidor digite a palavra "sair" a porta que ele abriu será fechada e ambos 
terminarão sua execução. */
int main(int argc, char *argv[])
{
  int listenfd, connfd, clientlen, n, who = 0;
  char buffer[BUFFSIZE];
  char ip4[INET_ADDRSTRLEN], palavra[100];
  struct sockaddr_in servaddr, client;
  /* As condicoes abaixo testam se os argumentos da linha de comando foram passados corretamente e se o socket pode ser criado*/
  if(argc != 2)
    error("Use: nome_executavel <porta>");
  
  if((listenfd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
    error("Falha ao criar o socket");
  /* Aqui, a estrutura "sockaddr_in" é inicializada */
  bzero(&servaddr, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
  servaddr.sin_port = htons(atoi(argv[1]));
  /* O metodo "bind" é responsável por alocar uma porta a aplicação "servidor_bp" em questão */
  if(bind(listenfd, (SA *) &servaddr, sizeof(servaddr)) < 0)
    error("Falha ao observar o socket do servidor");
  /* Esse metodo tem como função verificar se algum cliente deseja se conectar ao servidor */
  if(listen(listenfd, MAXPENDING) < 0)
    error("Falha ao tentar escutar o socket do servidor");
  /* O servidor irá permanecer ativo ate que ou a condição especificada abaixo (relativa a flag "who") seja verdadeira ou
  o sinal SIG_INTERRUPT (Ctrl+C) seja ativado pelo terminal */
  for( ; ; )
  {
    /*O "n" sempre é inicializado aqui para não armazenar as palavras recebidas de clientes anteriores */
    n = 10000000;
    clientlen = sizeof(client);
    /* A variável "connfd" irá receber um novo descritor de arquivo socket relativo a essa nova conexão estabelecida, enquanto "client"
    conterá o socket relativo ao cliente */
    if((connfd = accept(listenfd, (SA *) &client, &clientlen)) < 0)
      error("Falhou ao aceitar a conexao do cliente");

    printf("Cliente connectado. Bate papo iniciado. (PALAVRAS NAO DEVEM TER MAIS QUE 100 CARACTERES)\n");
    /* A função abaixo guarda em "ip4" o ip do cliente conectado */
    inet_ntop(AF_INET, &(client.sin_addr), ip4, INET_ADDRSTRLEN);
    /* Aqui começa o bate papo. Como a condição while descreve, enquanto o servidor não enviar a palavra "sair", ele ainda continua 
    ativo no bate papo */
    while(strcmp(palavra, "sair") != 0)
    { 
      /* O memset é utilizado aqui para evitar com que palavras recebidas anteriormente sejam concatenadas com novas, caso essas
      venham a ser menores (por exemplo, se a palavra anterior fosse "abacaxi" e agora o servidor recebesse "ddd", sem o memset
      isso resultaria em "dddcaxi") */
      memset(buffer, 0, sizeof buffer);
      printf("Cliente (IP %s, porta %hu) diz: ", ip4, ntohs(client.sin_port));
      if((n = recv(connfd, buffer, BUFFSIZE, 0)) < 0)
        error("Falhou ao receber os dados restantes do cliente");
      printf("%s", buffer);
      /* Caso o servidor receba do cliente a palavra "sair", tudo o que ele deve fazer é desconectá-lo, porém continuar como
      um processo ativo. Logo, a variável "who" é atribuída a um, que terá seu significado melhor explicado abaixo */
      if(strcmp(buffer, "sair") == 0)
      {
        who = 1;
        break;
      }
      printf("\nServidor: ");
      scanf("%s", palavra);
      /* Aqui, o servidor envia uma mensagem de volta ao cliente */
      if(send(connfd, palavra, strlen(palavra), 0) == -1)
        error("Falhou ao enviar os dados de volta para o cliente");
    }
    /* O descritor de socket criado especialmente para essa conexao é finalizado */
    close(connfd);
    /* A flag "who" é testada agora; caso ela esteja com zero, isso quer dizer que o servidor enviou a palavra sair, e portanto o 
    bate papo será finalizado (ou seja, nenhum outro cliente poderá se conectar e o processo do servidor é finalizado), saindo do
    laço "for" */
    if(who == 0)
      break;
    who = 0;
    printf("\n");
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
