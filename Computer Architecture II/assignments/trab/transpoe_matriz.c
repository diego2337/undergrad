#include <stdio.h>
#include <stdlib.h>

#define N 10000 /* Número de linhas e colunas das matrizes */

int main(int argc, char **argv)
{
	int i, j, **a, **c ;

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
	for (i = 0 ; i < N ; i ++)
	{
		for (j = 0 ; j < N ; j ++)
		{
			c[j][i] = a[i][j] ;
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
