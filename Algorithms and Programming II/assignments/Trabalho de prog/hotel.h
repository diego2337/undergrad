// Diego Cintra
#ifndef hotel
// Bibliotecas
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

// Struct do hospede a ser cadastrado
typedef struct _quarto{
char nome[30];
int numero_quarto;
char data_check_in[20];
int data_check_out;
int tipo_quarto;
int ocupado;
}quarto;

// Struct dos txts
typedef struct _qtxt{
	int numquarto;
	int index2;
}qtxt;

typedef struct _ntxt{
	char nompess[200];
	int index3;
}ntxt;

// Funcoes

int checkin(char name[200], char date[20], int type);
void lista(void);
int pesquisar(char type2[10], char nameroom[200]);
int checkout(char name[200]);

// Funcoes do programa hotel.c
void date(char tempo[50]);
int compare(const void *a, const void *b);
int compare2(const void *a, const void *b);
void sorting(FILE *quartos, qtxt aux[200], int *counter);
void sorting2(FILE *nomes, ntxt aux2[200], int *counter);
void cadastro(quarto cadastro, int numquarto, int type, char date[20], char name[200]);
int bbinstring(char nameroom[200], int lines2, ntxt aux2[50], int *bin);
int bbin(int nameroom, int lines, qtxt aux[20], int *p, int *bin);
#endif