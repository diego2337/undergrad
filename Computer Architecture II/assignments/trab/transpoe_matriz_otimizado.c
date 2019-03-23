#include <stdio.h>
#include <stdlib.h>

#define N 10000 /* Número de linhas e colunas das matrizes */
/*
   Argumento passado por linha de commando:
   - b: fator de bloco (ou blocking factor) da matriz quadrada
*/
int min(int a, int b)
{
	return a < b ? a : b;
}

int main(int argc, char **argv)
{
	int i, j, ii, jj, b, **a, **c ;
	b = atoi(argv[1]);
	/* Aloca matrizes */
	a = (int **) malloc(N * sizeof(int *)) ;
	for (i = 0 ; i < N ; i++)
	{
		a[i] = (int *) malloc(N * sizeof(int)) ;
	}
	c = (int **) malloc(N * sizeof(int *)) ;
	for (i = 0 ; i < N ; i++)
	{
		c[i] = (int *) malloc(N * sizeof(int)) ;
	}

	/* Inicia matriz a */
	for (i = 0 ; i < N ; i++)
	{
		for (j = 0 ; j < N ; j++)
		{
			a[i][j] = rand() % 1000 ;
		}
	}

	/* Transpoe matriz a em c*/
	for(ii = 0; ii < N; ii = ii + b)
	{
		for(jj = 0; jj < N; jj = jj + b)
		{
			for (i = ii ; i < min(ii+b, N) ; i ++)
			{
				for (j = jj ; j < min(jj+b, N) ; j ++)
				{
					c[j][i] = a[i][j] ;
				}
			}
		}
	}
	/* Desaloca matrizes */
	for (i = 0 ; i < N ; i ++)
	{
		free(a[i]) ;
	}
	free(a) ;
	for (i = 0 ; i < N ; i ++)
	{
		free(c[i]) ;
	}
	free(c) ;
	
	return 0 ;
}
