/* Programa: duplamente.c
 Programador: Diego Cintra
 Data: 22/02/2013 */
#include<stdio.h>
#include<stdlib.h>
typedef int tipo;
typedef struct _tlista{
	tipo val;
	struct _tlista *next;
	struct _tlista *prev;
}tlista;
typedef tlista *Lista;

int cmp(tipo a, tipo b);

void init(Lista *L)
{
	(*L) = NULL;
}

void insere(Lista *L, tipo val)
{
	Lista L2, atual, anterior;
	L2 = (tlista*)malloc (sizeof(tlista));
	L2->val = val;
	atual = *L;
	if(*L == NULL)
	{
		*L = L2;
		L2->next = NULL;
		L2->prev = NULL;
	}
	else
	{
		if(atual->val < val)
		{
			atual->prev = L2;
			L2->prev = NULL;
			L2->next = atual;
			*L = L2;
		}
		else
		{
			anterior = atual;
			atual = atual->next;
			while(atual != NULL && atual->val > val)
			{
				anterior = atual;
				atual = atual->next;
			}
			L2->next = atual;
			L2->prev = anterior;
			anterior->next = L2;
			if(atual != NULL)
			{
				atual->prev = L2;
			}
		}
	}
	
}

void go(Lista *L, int tam)
{
	Lista L2;
	L2 = *L;
	int counter = 0;
	/*while(L2->prev != NULL)
	{
		L2 = L2->prev; 
	}*/
	printf("IDA ");
	while(counter < tam - 1)
	{
		printf("%d ", L2->val);
		L2 = L2->next;
		counter++;
	}
	printf("%d ", L2->val);
	(*L) = L2;
	
	/*printf("\n");*/
}
void back(Lista *L, int tam)
{
	Lista L2;
	L2 = (*L);
	/*L2 = L2->prev;*/
	/*while(L2->next != NULL)
	{
		L2 = L2->next;	
	}*/
	printf("VOLTA ");
	while(tam > 1)
	{
		printf("%d ", L2->val);
		L2= L2->prev;
		tam--;
	}
	printf("%d", L2->val);
	printf("\n");
}
int cmp(tipo a, tipo b)
{
	return a-b;
}

int main(void)
{
	int i, j, rep, in, num;
	Lista L;
	scanf("%d", &rep);
	for(i = 0; i < rep; i++)
	{
		/*printf("hey ho lets go\n");*/
		init(&L);
		scanf("%d", &in);
		for(j = 0; j < in; j++)
		{
			scanf("%d", &num);
			insere(&L, num);
		}
		go(&L, in);
		back(&L, in);
	}
	return 0;
}
