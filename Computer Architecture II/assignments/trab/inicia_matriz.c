#include <stdio.h>
#include <stdlib.h>

/*
   Argumentos passados por linha de commando:
   - n: número de linhas (ou colunas) da matriz quadrada
   - ordem de percurso da matriz: linha ('L') ou coluna ('C')
*/

int main(int argc, char **argv)
{
	int i, j, n, **m ;
	char ordem ;

	n = atoi(argv[1]) ;
	ordem = *argv[2] ;

	/* Aloca matriz */
	m = (int **) malloc(n * sizeof(int *)) ;
	for (i = 0 ; i < n ; i ++)
	{
		m[i] = (int *) malloc(n * sizeof(int)) ;
	}

	if ((ordem == 'l') || (ordem == 'L')) /* Percorre matriz por linhas */
	{
		for (i = 0 ; i < n ; i ++)
		{
			for (j = 0 ; j < n ; j ++)
			{
				m[i][j] = 0 ;
			}
		}
	}
	else if ((ordem == 'c') || (ordem == 'C')) /* Percorre matriz por colunas */
	{
		for (i = 0 ; i < n ; i ++)
		{
			for (j = 0 ; j < n ; j ++)
			{
				m[j][i] = 0 ;
			}
		}
	}
	else
	{
		printf("Ordem de percurso selecionada incorreta\n") ;
	}

	/* Desaloca matriz */
	for (i = 0 ; i < n ; i ++)
	{
		free(m[i]) ;
	}
	free(m) ;
	
	return 0 ;
}
