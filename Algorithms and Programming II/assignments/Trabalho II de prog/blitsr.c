#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define HSIZE 300

typedef struct{
   char placa[8];
   int ano;
   char marca[10];
   char modelo[15];
   char estado[3];
}tipo;

typedef struct _tlista{
	tipo val;
	struct _tlista *prox;
}tlista;

typedef tlista *Hash[HSIZE];


void init(Hash *L) {
	int i;
	    for(i = 0; i < HSIZE; i++)
		(*L)[i] = NULL;
}

int cmp(tipo a, tipo b) {
	return strcmp(a.placa, b.placa);
}

int funcaohash(tipo val) {
	long long int hash = 3;
	int i;
	for(i = 0; i < 7;i++){
		hash = 33 *hash + val.placa[i];
	}
	return hash % HSIZE;
}

int busca(Hash *L,tipo val, void *pont) {
	int i = funcaohash(val);
	int ret = 1;
	tlista *aux;
	aux = (*L)[i];
	while(aux != NULL && cmp(aux->val,val) != 0) {
		aux = aux->prox;
	}	
	if (aux == NULL)
		return ret-1;
	if(cmp(aux->val,val) == 0){
		*((tlista **)pont) = aux;
		ret;
	}	
	return ret;
}

int insere(Hash *L, tipo val){
	int i = funcaohash(val);
	int ret = 1;
	tlista *aux;
	aux =(tlista*)malloc(sizeof(tlista));
	if(aux == NULL){
		ret = 0;
	}else{
		aux->val = val;
		if((*L)[i] != NULL)
		    aux->prox = (*L)[i];
		else
			aux->prox = NULL;
		(*L)[i] = aux;
	}
	return ret;
}

int remover (Hash *L, tipo val) {	
	int ret = 0;
	int i = funcaohash(val);
	tlista *atual;
	tlista *ant;
	tlista *aux;
	atual = (*L)[i];
	if(atual == NULL) {
		ret = 0;
	}else {
		if(cmp(atual->val,val) == 0) {
			aux = atual;
			(*L)[i] = atual->prox;
			free(aux);
			ret = 1;
		}else {
			ant = atual;
			atual = atual->prox;
			while(atual != NULL && cmp(atual->val,val) != 0) {
				ant = atual;
				atual = atual->prox;
			}
			if(atual != NULL) {
				aux = atual;
				ant->prox = atual->prox;
				free(aux);
				ret = 1;
			}
		}
	}
	return ret;
}

int main(void) {
	char indice;
	Hash L;
	tipo carro;
	tlista *aux;
	stdin = fopen("blits.in", "r");
	init (&L);
	while(scanf(" %c", &indice) == 1) {
		if(indice == 'r') {
				scanf ("%s %d %s %s %s", carro.placa, &carro.ano, carro.marca, carro.modelo, carro.estado);
			if(busca(&L, carro, &aux)) {
				printf ("carro (%s %d %s %s %s) ja foi cadastrado.\n",carro.placa, carro.ano, carro.marca, carro.modelo, carro.estado);
			}else {
				insere(&L,carro);
				printf ("carro (%s %d %s %s %s) roubado.\n", carro.placa, carro.ano, carro.marca, carro.modelo, carro.estado);
			}
		}else if(indice == 'a') {
			scanf("%s",carro.placa);
			if(busca(&L,carro,&aux)) {
				remover (&L, carro);
		  		printf ("carro (%s %d %s %s %s) recuperado.\n", carro.placa, aux->val.ano, aux->val.marca, aux->val.modelo, aux->val.estado);
			}else {
				printf ("carro %s nao consta na base de dados.\n", carro.placa);
			}
		}else if(indice == 'c') {			
			scanf ("%s", carro.placa);
		 	if (busca (&L, carro, &aux)) {
				printf ("carro (%s %d %s %s %s) eh um carro roubado, prender motorista.\n", carro.placa, aux->val.ano, aux->val.marca, aux->val.modelo, aux->val.estado);
	  		}
		  	else {
		  		printf ("carro %s NAO eh um carro roubado, liberar motorista.\n", carro.placa);
			}		
		}
	}
	return 0;
}