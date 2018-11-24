
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define hsize 300

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

typedef tlista *hash[hsize];

void init(hash *l);
void inserir(hash * l,tipo val);
int busca(hash *l, tipo val, void * pont);
void remover(hash * l, tipo val);
void stringtipo(void * pont, char ret[8]);
int HASH(tipo val);
int cmp(tipo A, tipo B);



int main(void){
	//Modifiquei aki
	//tipo *info;
	//info=(tipo*)malloc(sizeof(tipo));
	tipo info;
	hash l;
	init (&l);
	char operacao;
	int achou=0;
	//Modifiquei aki
	//tipo *ponteiro;
	tlista *ponteiro;
	while(scanf(" %c", &operacao) == 1)
	{	
		if(operacao=='r')
		{
			//ROUBO - INSERIR
			//Modifiquei aki ao inves de -> coloquei ponto
			scanf("%s", info.placa);
			scanf("%d", &info.ano);		
			scanf("%s", info.marca);
			scanf("%s", info.modelo);
			scanf("%s", info.estado);

			achou = busca(&l, info, &ponteiro);
			if(achou)
			{
				printf("carro (%s %d %s %s %s) ja foi cadastrado.\n",  info.placa, info.ano, info.marca, info.modelo, info.estado);
			
			}
			else
			{ 			
				inserir(&l,info);
				printf("carro (%s %d %s %s %s) roubado.\n", info.placa, info.ano, info.marca, info.modelo, info.estado);
			}
		}
		else if(operacao=='a')
		{
			//APREENDIDO - REMOVER
			scanf("%s", info.placa);
			achou = busca(&l, info, &ponteiro);
			if(achou)
			{
				printf("carro (%s %d %s %s %s) recuperado.\n", info.placa, ponteiro->val.ano, ponteiro->val.marca, ponteiro->val.modelo, ponteiro->val.estado);
				remover(&l, info);			
			}
			else
			{
				printf("carro %s nao consta na base de dados.\n", info.placa);			
			}		

		}
		else if(operacao=='c')
		{
			//BUSCA	

			scanf("%s", info.placa);
			achou = busca(&l, info, &ponteiro);
			if(achou)
			{
				printf("carro (%s %d %s %s %s) eh um carro roubado, prender motorista.\n", info.placa, ponteiro->val.ano, ponteiro->val.marca, ponteiro->val.modelo, ponteiro->val.estado);
			
			// Modifiquei aki : nao precisa remover aki
			//	remover(&l, info);			
			}
			else
			{
				printf("carro %s NAO eh um carro roubado, liberar motorista.\n", info.placa);			
			}	
		}
	}

	return 0;
}


int busca(hash *L, tipo val, void * pont)
{
	int i = HASH(val);
	int ret=0;
	tlista *aux;	
	aux = (*L)[i];
	while(aux!=NULL && cmp(aux->val,val) != 0)
		aux = aux->prox;
	if(aux == NULL)
		return ret;
	if(cmp(aux->val, val)==0)
	{
		*((tlista**)pont)=aux;
		ret=1;
	}
			
	return ret;		
}


void init(hash *l)
{
	int i;
	for (i = 0; i < hsize; i += 1)
	{
		(*l)[i]=NULL;		
	}
}


void remover(hash * l, tipo val)
{
	int i = HASH(val);
	tlista *atual;
	tlista *ant;
	tlista *aux;
	atual = (*l)[i];
	if(atual==NULL)
	{
		exit(1);
	}
	else
	{
		if(cmp(atual->val, val)==0)
		{
			aux = atual;
			(*l)[i] = atual->prox;
			free(aux);
		}
		else
		{
			ant = atual;
			atual = atual->prox;
			while(atual!=NULL && cmp(atual->val, val)!=0)
			{
				ant = atual;
				atual = atual->prox;
			}
			if(atual!=NULL)
			{
				aux=atual;
				ant->prox = atual->prox;
				free(aux);
			}
		}
	}

}

int HASH(tipo val)
{
	int i;
	long long int soma=3;
	long long int result;
	for(i=0; i<7; i++)
	{
		soma = 33*soma + val.placa[i];
	}
	result = soma % hsize;
	return result;
}


int cmp(tipo A, tipo B) 
{
	return strcmp(A.placa, B.placa);
}


void inserir(hash *l, tipo val)
{
	int i = HASH(val);
	tlista *aux;	
	aux = (tlista*)malloc(sizeof(tlista));
	if(aux == NULL)
	{
		exit(1);
	}
	else
	{
		aux->val = val;
		if((*l)[i] == NULL)
		{
			aux->prox = NULL;
		}
		else
		{
			aux->prox = (*l)[i];
		}
		(*l)[i] = aux;
	}

}

