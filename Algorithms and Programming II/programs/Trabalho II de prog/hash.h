/* Diego Cintra e Rogerio Sandim */
#ifndef hash
/* Bibliotecas */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
/* Constantes */
#define HSIZE 1000000

/* Struct do cadastro das placas */
typedef struct{
	char placa[8];
	int ano;
	char marca[10];
	char modelo[15];
	char estado[3];
}tipo;

/*Struct da lista dinamica */
typedef struct _tlista{
	tipo val;
	struct _tlista *prox;
}tlista;

typedef tlista *Hash[HSIZE];

/* Funcoes */
void init(Hash *L);
int hash(tipo val);
int insere(Hash *L, tipo val);
int remover(Hash *L, tipo val);
int busca(Hash *L, tipo val, void *pont);
int cmp(tipo a, tipo b);
#endif
