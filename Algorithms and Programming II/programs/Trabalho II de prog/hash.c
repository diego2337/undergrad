/* Programa: hash.c
Programadores: Diego Cintra e Rogerio Sandim
Data: 11 de março de 2013
O dialogo: Esse programa e uma funcao hash, com funcoes insere, remove e busca. */
#include "hash.h"
void init(Hash *L)
{
	int i;
	for(i = 0; i < HSIZE; i++)
	{
		(*L)[i] = NULL;
	}
}
int cmp(tipo a, tipo b) 
{
	return strcmp(a.placa, b.placa);
}

int hash(tipo val) 
{
	long long int hash = 3;
	int i;
	for(i = 0; i < 7;i++)
	{
		hash = 33 *hash + val.placa[i];
	}
	return hash % HSIZE;
}

int insere(Hash *L, tipo val)
{
	int i = hash(val);
	int ret = 1;
	tlista *aux;
	aux = (tlista*)malloc(sizeof(tlista));
	if(aux == NULL)
	{
		ret = 0;
	}
	else
	{
		aux->val = val;
		if((*L)[i] != NULL)
			aux->prox = (*L)[i];
		else
			aux->prox = NULL;
		(*L)[i] = aux;
	}
	return ret;
}

int remover(Hash *L, tipo val)
{	
	int ret = 0;
	int i = hash(val);
	tlista *atual;
	tlista *ant;
	tlista *aux;
	atual = (*L)[i];
	if(atual == NULL) 
	{
		ret = 0;
	}
	else 
	{
		if(cmp(atual->val,val) == 0) 
		{
			aux = atual;
			(*L)[i] = atual->prox;
			free(aux);
			ret = 1;
		}
		else 
		{
			ant = atual;
			atual = atual->prox;
			while(atual != NULL && cmp(atual->val,val) != 0) 
			{
				ant = atual;
				atual = atual->prox;
			}
			if(atual != NULL) 
			{
				aux = atual;
				ant->prox = atual->prox;
				free(aux);
				ret = 1;
			}
		}
	}
	return ret;
}

int busca(Hash *L,tipo val, void *pont) 
{
	int i = hash(val);
	int ret = 1;
	tlista *aux;
	aux = (*L)[i];
	while(aux != NULL && cmp(aux->val,val) != 0) 
	{
		aux = aux->prox;
	}	
	if (aux == NULL)
		return ret = 0;
	if(cmp(aux->val,val) == 0)
	{
		*((tlista **)pont) = aux;
		ret = 1;
	}	
	return ret;
}


