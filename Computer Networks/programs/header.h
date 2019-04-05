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
#define SA struct sockaddr