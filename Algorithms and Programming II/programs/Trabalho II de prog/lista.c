/* Programa: lista.c
Programadores: Diego Cintra e Rogerio Sandim
Data: 11 de março de 2013
O dialogo:  Esse programa e uma lista estatica, que realiza as operaçoes de inserçao, remoçao e apreensao.*/
#include "lista.h"
void init(Lista *L)
{
	*L = (lista*)malloc(sizeof(lista));
	(*L)->tam = 0;
}
int cmp(tipo a, tipo b)
{
	return strcmp(a.placa, b.placa);
}
int compare(const void *a, const void *b)
{
	return strcmp(a, b);
}
int cheia(Lista *L)
{
	Lista aux;
	aux = (lista*)malloc(sizeof(lista));
	if(aux == NULL)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
int vazio(Lista *L)
{
	int ret = 0;
	if((*L)->val == 0 && (*L)->tam == 0)
	{
		ret = 1;
	}
	return ret;
}
int insere(Lista *L, tipo val)
{
	int ret = 1;
	int counter = 0;
	int i;
	if(!cheia(L))
	{
		ret = 0;
	}
	else
	{
		i = (*L)->tam-1;
		while(i > 0 && cmp((*L)->val[i], val) > 0)
		{
			(*L)->val[i+1] = (*L)->val[i];
			i--;
		}
		(*L)->val[i+1] = val;
		(*L)->tam = (*L)->tam+1;
	}
	qsort(L, counter, sizeof(Lista), compare);
	return ret;
}
int remover(Lista *L, tipo val)
{
	int pos, pos2, ret, achou, i;
	ret = 0;
	int counter = 0;
	if(vazio(L))
	{
		ret = 0;
	}
	else
	{
		achou = busca(L, val, &pos, &pos2);
		if(achou)
		{
			i = pos;
			(*L)->tam = (*L)->tam-1;
			while(i < (*L)->tam)
			{
				(*L)->val[i] = (*L)->val[i+1];
				i++;
			}
		}
	}
	qsort(L, counter, sizeof(Lista), compare);
	return ret;
}
int busca(Lista *L, tipo val, void *pont, void *pont2)
{
	int meio, esq, dir, achou;
	Lista atual;
	achou = 0;
	atual = *L;
	dir = (*L)->tam; // segmentation fault
	esq = -1;
	while(esq < dir-1)
	{
		meio = (esq+dir)/2;
		if(cmp((*L)->val[meio], val) < 0)
		{
			esq = meio;
		}
		else
		{
			dir = meio;
		}
	}
	*((int*)pont) = dir;
	atual->tam = dir;
	*((lista**)pont2) = atual;
	if(cmp((*L)->val[dir], val) == 0)
	{
		achou = 1;
	}
	return achou;
}
