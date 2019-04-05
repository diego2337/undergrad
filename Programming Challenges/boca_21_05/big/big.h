#ifndef __BIG_H
#define __BIG_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXDIGITOS 100
#define MAIS 1
#define MENOS -1

typedef struct{
	char digitos[MAXDIGITOS]; /* representa o numero */
	int sinal; /* representa o sinal */
	int ultimodigito; /* indice do digito de mais alta ordem */
}numerogrande;

void inicializa_numgrande(numerogrande *n);
void imprime_numgrande(numerogrande *n);
void soma_numgrandes(numerogrande *a, numerogrande *b, numerogrande *c);
void subtrai_numgrandes(numerogrande *a, numerogrande *b, numerogrande *c);
void justifica_zero(numerogrande *n);
int compara_numgrandes(numerogrande *a, numerogrande *b);
void multiplica_numgrandes(numerogrande *a, numerogrande *b, numerogrande *c);
void desloca_digito(numerogrande *n, int d);
void divide_numgrandes(numerogrande *a, numerogrande *b, numerogrande *c);

#endif