#include <stdio.h>          /* printf, snprintf */
#include <stdlib.h>         /* exit */
#include <string.h>         /* bzero */
#include <sys/socket.h>     /* struct sockaddr, socket, listen, bind, accept */
#include <netinet/in.h>     /* struct sockaddr_in */
#include <arpa/inet.h>      /* inet_pton, htons, htonl */
#include <unistd.h>         /* write, fork, close */
#include <time.h>           /* ctime, time */

#define MAXLINE 256
#define SA struct sockaddr
#define PORT 1300
#define LISTENQ 4

void error(char *msg);

int main(int argc, char *argv[])
{
  int listenfd, connfd;
  struct sockaddr_in servaddr;
  char buff[MAXLINE];
  time_t ticks;
  pid_t pid;

  listenfd = socket(AF_INET, SOCK_STREAM, 0);
  
  bzero(&servaddr, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
  servaddr.sin_port = htons(PORT);

  if(bind(listenfd, (SA *) &servaddr, sizeof(servaddr)) < 0)
    error("erro no bind");

  if(listen(listenfd, LISTENQ) < 0)
    error("erro no listen");

  for( ; ; )
    {
      connfd = accept(listenfd, (SA *) NULL, NULL);
      if((pid = fork()) == 0)
	{
	  close(listenfd);
	  
	  ticks = time(NULL);
	  snprintf(buff, sizeof(buff), "%.24s\r\n", ctime(&ticks));
	  write(connfd, buff, strlen(buff));
	  	  
	  close(connfd);
	  exit(0);
	}
      close(connfd);
    }

  close(listenfd);
  exit(0);
}


/* Imprime mensagens de erro */
void error(char *msg)
{
  printf("%s\n", msg);
  exit(0);

  return;
}
