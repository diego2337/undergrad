// Programa: matriz.c
// Programador: Diego Cintra
// Data: 18/01/2013
// O dialogo: Esse programa ira alocar dinamicamente uma matriz e imprimir a soma de seus valores.
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	int i, j, k, n, m, soma, rep;
	int **matriz;
	scanf("%d", &rep);
	for(k = 0; k < rep; k++)
	{

		scanf("%d %d", &m, &n); // Dimensao da matriz
		matriz = (int**)malloc (m*sizeof(int*));

		for(j = 0; j < m; j++)
		{
			*(matriz+j) = (int*)malloc(n*sizeof(int));
		}

		for(i = 0; i < m; i++)
		{
			for(j = 0; j < n; j++)
			scanf("%d", (*(matriz+i)+j));
		}

		for(i = 0; i < m; i++)
		{
			for(j = 0; j < n; j++)
			soma = soma + *(*(matriz+i)+j);
		}			
		printf("%d\n", soma);
		for(i = 0; i < n; i++)
		{
			free(*(matriz+i));
		}
		free(matriz);
		soma = 0;
		
	}
	return 0;
}
