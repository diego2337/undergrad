#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	int i, j, k, rep, soma, m, n;
	int **matriz;
	scanf("%d", &rep);
	for(i=0; i<rep;i++)
	{
		scanf("%d %d", &m, &n);
		matriz = (int**)malloc (m*sizeof(int*));
		for(j=0; j < m; j++)
		{
			*(matriz+j) = (int*)malloc (n*sizeof(int));
		}
		for(j=0; j < m; j++)
		{
			for(k=0; k<n; k++)
			scanf("%d", (*(matriz+j)+k));
		}
		for(j = 0; j < m; j++)
		{
			for(k = 0; k < n; k++)
			soma = soma + *(*(matriz+j)+k);
		}
		printf("%d\n", soma);
		for(j = 0; j < m; j++)
		{
			free(*(matriz+j));
		}
		free(matriz);
		soma = 0;
	}
	return 0;
}
