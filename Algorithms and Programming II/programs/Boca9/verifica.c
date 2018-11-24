#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define bool int

typedef char tipo;
typedef struct _pilha
{
    tipo val;
    struct _pilha * prox;
}tpilha;
typedef tpilha * pilha;
void init(pilha * stack)
{
    *stack = NULL;
}

void empilha(pilha * stack, tipo val)
{
    tpilha  * p;
    p = (tpilha *)malloc(sizeof(tpilha));
    if ( p== NULL){
        printf("ERRO! Memoria cheia!\n");
        exit(EXIT_FAILURE);
    }
    p->val = val;
    p->prox = *stack;
    *stack = p;
}

tipo desempilha(pilha * stack)
{
    tipo v;
    pilha t;
    t = *stack;
    if (t==NULL){
       printf("Pilha Vazia\n");
       exit(EXIT_FAILURE);
    }
     v = t->val;
    *stack = t->prox;
    free(t);
    return v;
}

int empty(pilha * stack)
{
    int ret = 0;
    if (*stack == NULL)
        ret = 1;
    return ret;
}
bool par(char character1, char character2)
{
   if(character1 == '(' && character2 == ')')
     return 1;
   else if(character1 == '{' && character2 == '}')
     return 1;
   else if(character1 == '[' && character2 == ']')
     return 1;
   else
     return 0;
}
bool balanceado(char caux)
{
	int i = 0;
	pilha st = NULL;
	while(caux[i])
	{
		 if(caux[i] == '{' || caux[i] == '(' || caux[i] == '[')
		empilha(&p, caux[i]);
		if(caux[i] == '}' || caux[i] == ')' || caux[i] == ']')
         {
         if(st == NULL)
           return 0;

         else if ( !balanceado(desempilha(&p), caux[i]) )
           return 0;
      }
      i++;
	}
}
int main(void)
{
	char codigo[200], caux[200], caux2[200];
	int i, n, j, m;
	pilha p;
	while(scanf("%s", codigo) != '#')
	{

		init(&p);
		m = 1;
		n = 0;
		for(i = 0; i < strlen(codigo); i++)
		{
			if(codigo[i] == '(' || codigo[i] == '[' || codigo[i] == '{' || codigo[i] == ')' || codigo[i] == ']' || codigo[i] == '}')
			{
				caux[n] = codigo[i];
				n++;
			}
		}
		for(i = 0; i < strlen(caux); i++)
		{
			for(j = i+1; j < strlen(caux); j++)
			{
				par(caux[i], caux[j]);
			}	
		}
		bool balanceado(caux);
		if(balanceado(caux))
		printf("Programa OK!\n");
		else
		printf("Programa com erro\n");
	}
	return 0;
}
