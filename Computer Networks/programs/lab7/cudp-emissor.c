/* CLIENTE UDP */

#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFERSIZE 255
#define PORT 9001

int main(int argc, char *argv[])
{
    int sock, yes = 1;
    struct sockaddr_in sA;
    struct sockaddr_in fA;
    char *servIP = "127.0.0.1";
    char *msg;
    int fASize, rLen;
    char buffer[BUFFERSIZE];

   
    /* 1) Cria um socket UDP */
    if ((sock = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0)
    {
        printf("Erro na criação do socket\n");
        exit(1);
    }

    /* 2) Prepara a estrutura de endereços */
    memset(&sA, 0, sizeof(sA));
    sA.sin_family = AF_INET;
    /* Especificando o endereço '255.255.255.255', o que indica um broadcast */
    sA.sin_addr.s_addr = htonl(-1);
    sA.sin_port   = htons(atoi(argv[1]));
    /* 2.1) Recebendo uma msg do emissor para ser enviada */
    msg = malloc(255*sizeof(char));
    printf("Por favor escreva sua mensagem: \n");
    scanf("%s", msg);
    /* Identificando ao socket que iremos utilizar de broadcast */
    if(setsockopt(sock, SOL_SOCKET, SO_BROADCAST, &yes, sizeof(int)) == -1)
    {
        printf("Erro de configuração de broadcast.\n");
        exit(1);
    }
    /* 3) Envia uma string para o servidor (receptor) */
    puts("Enviando mensagem...");
    if (sendto(sock, msg, strlen(msg)+1, 0, (struct sockaddr *)&sA, sizeof(sA)) != (strlen(msg)+1))
    {
        printf("Erro de transmissao\n");
        exit(1);
    }

    
    /* 4) Aguarda resposta: Eco */
    puts("Aguardando o eco da mensagem ...");
 
    fASize = sizeof(fA);
    if ((rLen = recvfrom(sock, buffer, BUFFERSIZE, 0,(struct sockaddr *) &fA, &fASize)) <= 0)
    {
        printf("Erro de recepcao\n");
        exit(1);
    }

    buffer[rLen] = '\0';
    printf("Recebi o pacote: '%s' do endereco %s:%d\n", buffer, inet_ntoa(fA.sin_addr), ntohs(fA.sin_port));
    
    close(sock);
    exit(0);
}
