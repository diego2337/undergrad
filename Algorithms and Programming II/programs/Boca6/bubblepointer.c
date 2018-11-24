// Programa: bubble.c
// Programador: Diego Cintra
// Data: 30/11/2012
// O dialogo: Esse programa ira fazer a ordenacao de vetores por meio do bubble sort, imprimindo o numero de trocas para a operacao.
#include<stdio.h>
int bolha(int n, int *V)
{
	int i, j, aux = 0, trocas = 0;
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n - 1; j++)
		{
			if(*(V+j) > *(V+j+1))
			{
				aux = *(V+j);
				*(V+j) = *(V+j+1);
				*(V+j+1) = aux;
				trocas++;
				// printf("%d \n", trocas);
			}
		}
	}
	return trocas;
}

int main(void)
{
	int V[100], n, i, j, rep;
	scanf("%d", &rep);
	for(i = 0; i < rep; i++)
	{
		scanf("%d", &n);
		for(j = 0; j < n; j++)
		scanf("%d", V + j);
		printf("%d\n", bolha(n, V));
	}
	return 0;
}
