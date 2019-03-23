#include <stdio.h>
#include <stdlib.h>

#define N 2000 /* Número de linhas e colunas das matrizes */
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
	int i, jj, j, kk, k, B, **a, **b, **c ;
	B = atoi(argv[1]);
	/* Aloca matrizes */
	a = (int **) malloc(N * sizeof(int *)) ;
	for (i = 0 ; i < N ; i++)
	{
		a[i] = (int *) malloc(N * sizeof(int)) ;
	}
	b = (int **) malloc(N * sizeof(int *)) ;
	for (i = 0 ; i < N ; i++)
	{
		b[i] = (int *) malloc(N * sizeof(int)) ;
	}
	c = (int **) malloc(N * sizeof(int *)) ;
	for (i = 0 ; i < N ; i++)
	{
		c[i] = (int *) malloc(N * sizeof(int)) ;
	}

	/* Inicia matrizes */
	for (i = 0 ; i < N ; i++)
	{
		for (j = 0 ; j < N ; j++)
		{
			a[i][j] = rand() % 1000 ;
			b[i][j] = rand() % 1000 ;
			c[i][j] = 0 ;
		}
	}
	/* Calcula matriz c como a x b */
	for(jj = 0; jj < N; jj = jj + B)
	{
		for(kk = 0; kk < N; kk = kk + B)
		{
			for (i = 0 ; i < N ; i ++)
			{
				for (j = jj ; j < min(jj+B, N) ; j ++)
				{
					for (k = kk; k < min(kk+B, N) ; k ++)
					{
						c[i][j] = c[i][j] + a[i][k] * b[k][j] ;
					}
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
		free(b[i]) ;
	}
	free(b) ;
	for (i = 0 ; i < N ; i ++)
	{
		free(c[i]) ;
	}
	free(c) ;
	
	return 0 ;
}
