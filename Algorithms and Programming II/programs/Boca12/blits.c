#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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

int busca(Hash *L, tipo val, void *pont);

void init(Hash *L)
{
	int i;
	for(i = 0; i < HSIZE; i++)
	{
		(*L)[i] = NULL;
	}
}
int hash(tipo val)
{
	unsigned int hash = 3;
	int i;
	for(i = 0; i < 7; i++)
	{
		hash = 33*hash + val.placa[i];
	}
	return hash%HSIZE;
}

int cmp(tipo a, tipo b)
{
	return strcmp(a.placa, b.placa);
}

int inserir(Hash *L, tipo val)
{
	int i;
	int ret;
	tlista *aux;
	void *pont;
	i = hash(val);
	ret = 1;
	aux = (tlista*)malloc (sizeof(tlista));
	if(busca(L, val, &pont) == 1)
	{
		ret = 2;
		return ret;
	}
	if(aux == NULL)
	{
		ret = 0;
	}
	else
	{
		aux->val = val;
		if((*L)[i] == NULL)
		{
			aux->prox = NULL;
		}
		else
		{
			aux->prox = (*L)[i];
		}
		(*L)[i] = aux;
	}
	return ret;
}

int remover(Hash *L, tipo val)
{
	int ret;
	int i;
	void *pont;
	tlista *atual;
	tlista *ant;
	tlista *aux;
	ret = 0;
	i = hash(val);
	atual = (*L)[i];
	if(busca(L, val, &pont) == 0)
	{
		ret = 2;
		return ret;
	}
	if(atual == NULL)
	{
		ret = 2;
	}
	else
	{	

		if(cmp(atual->val, val) == 0)
		{
			aux = atual;
			printf("carro (%s %d %s %s %s) recuperado.\n", atual->val.placa, atual->val.ano, atual->val.marca, atual->val.modelo, atual->val.estado);
			(*L)[i] = atual->prox;
			free(aux);
			ret = 1;
		}
		else
		{
			ant = atual;
			atual = atual->prox;
			while(atual != NULL && cmp(atual->val, val) != 0)
			{
				
				ant = atual;
				atual = atual->prox;
			}
			if(atual != NULL)
			{
				printf("carro (%s %d %s %s %s) recuperado.\n", atual->val.placa, atual->val.ano, atual->val.marca, atual->val.modelo, atual->val.estado);
				aux = atual;
				ant->prox = atual->prox;
				free(aux);
				ret = 1;
			}
		}

		/*if(ret==1){
		imprimir
			printf("carro (%s %d %s %s %s) recuperado.\n", aux->val.placa, aux->val.ano, aux->val.marca, aux->val.modelo, aux->val.estado);
			free(aux);

		}else
			ret = 2;*/
	}
	return ret;
}

int busca(Hash *L, tipo val, void *pont)
{
	int i;
	tlista *aux;
	int ret;
	i = hash(val);
	ret = 0;
	aux = (*L)[i];
	while(aux != NULL && ret != 1)
	{
		/*printf("hey ho lets go20\n");*/
		if(cmp(aux->val, val) != 0)
		{
			aux = aux->prox;
		}
		else
		{
			*((tlista**)pont) = aux;
			ret = 1;
		}
	}
	/*if(cmp(aux->val, val) == 0)
	{
			printf("hey ho lets go23\n");
		*((tlista**)pont) = aux;
		ret = 1;
	}*/
	return ret;
}

int main(void)
{
	char report;
	Hash L;
	char placa[8], marca[15], modelo[15], estado[3];
	int ano;
	int results;
	tipo ptr;
	void *pont;
	init(&L);
	/*ptr = (tipo*) malloc(sizeof(tipo));*/
	while(scanf(" %c", &report) == 1)
	{
		
		if(report == 'r')
		{
			/*printf("hey ho lets go1\n");*/
			/*informacoes do carro*/
			scanf("%s", ptr.placa);
			scanf("%d", &ptr.ano);
			scanf("%s", ptr.marca);
			scanf("%s", ptr.modelo);
			scanf("%s", ptr.estado);
			results = inserir(&L, ptr);
			if(results == 1)
			{
				printf("carro (%s %d %s %s %s) roubado.\n", ptr.placa, ptr.ano, ptr.marca, ptr.modelo, ptr.estado);
			}
			else if(results == 2)
			{
				printf("carro (%s %d %s %s %s) ja foi cadastrado.\n", ptr.placa, ptr.ano, ptr.marca, ptr.modelo, ptr.estado);
			}
		}
		else if(report == 'a')
		{
			scanf("%s", ptr.placa);
			strcpy(placa, ptr.placa);
			ano = ptr.ano;
			strcpy(marca, ptr.marca);
			strcpy(modelo, ptr.modelo);
			strcpy(estado, ptr.estado);
			results = remover(&L, ptr);
			/*if(results == 1)
			{
				printf("carro (%s %d %s %s %s) recuperado.\n", placa, ano, marca, modelo, estado);
			}*/
			if(results == 2)
			{
				printf("carro %s nao consta na base de dados.\n", placa);
			}
		}
		else if(report == 'c')
		{
			scanf("%s", ptr.placa);
			results = busca(&L, ptr, &pont);
			if(results == 1)
			{
				printf("carro (%s %d %s %s %s) eh um carro roubado, prender motorista.\n", ptr.placa, ptr.ano, ptr.marca, ptr.modelo, ptr.estado);
			}
			else
			{
				printf("carro %s NAO eh um carro roubado, liberar motorista.\n", ptr.placa);
			}
		}
	}
	return 0;
}
