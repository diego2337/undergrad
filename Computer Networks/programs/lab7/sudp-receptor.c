/* SERVIDOR (RECEPTOR) UDP */

#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFSIZE 255
#define PORTA 9001


int main(int argc, char *argv[])
{
    int sock, yes = 1;
    struct sockaddr_in sA; // endereço do receptor
    struct sockaddr_in cA; // endereço do emissor
    unsigned int cALen;     // tamanho da estrutura de endereço
    char Buffer[BUFSIZE];  // buffer de recepção
    int rMSize;            // quantidade de dados recebidos

    
	printf("Receptor UDP\n");

    /* Cria um socket UDP */

	if ((sock = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0)
	{
        printf("Erro na criacao do socket\n");
		exit(1);
	}

    /* Define o endereço do receptor */

 	memset(&sA, 0, sizeof(sA));
    sA.sin_family = AF_INET;
    sA.sin_addr.s_addr = htonl(INADDR_ANY);
    sA.sin_port = htons(atoi(argv[1]));
    if(setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1)
    {
        printf("Erro de configuração de broadcast.\n");
        exit(1);
    }
 	/* Associa o socket ao endereço do receptor */
 	if (bind(sock, (struct sockaddr *) &sA, sizeof(sA)) < 0)
   	{
       	printf("Erro no bind\n");
		exit(1);
	}

	/* Aguarda pacotes dos emissores */

	for (;;)
	{

	    cALen = sizeof(cA);
      	if ((rMSize = recvfrom(sock, Buffer, BUFSIZE, 0,(struct sockaddr *) &cA, &cALen)) < 0)
 	 	{
       		printf("Erro na recepcao\n");
			exit(1);
		}
		printf("Eu recebi essa mensagem: '%s'\n", Buffer);

       	printf("Recebi um pacote do emissor %s:%d\n", inet_ntoa(cA.sin_addr), ntohs(cA.sin_port));

		/* Envia o eco ao emissor*/
		if (sendto(sock, Buffer, rMSize, 0,(struct sockaddr *) &cA, sizeof(cA)) != rMSize)
 	 	{
        	printf("Erro na transmissão\n");
			exit(1);
		}
	}

}
