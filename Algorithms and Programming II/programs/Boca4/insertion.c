// Programa: selection.c
// Programador: Diego Cintra
// Data: 30/11/2012
// O dialogo: Esse programa ira fazer a ordenacao de vetores por meio do selection sort, imprimindo o numero de trocas para a operacao.
#include<stdio.h>
void insertion(int n, int V[])
{
	int i, x, j;
	for(i = 1; i < n; i++)
	{
		x = V[i];
		j = i - 1;
		while(j >= 0 && V[j] > x)
		{
			V[j+1] = V[j];
			j--;	
		}
		V[j+1] = x;
	}
}

int main(void)
{
	int V[100], n, i, j, rep;
	scanf("%d", &rep);
	for(i = 0; i < rep; i++)
	{
		scanf("%d", &n);
		for(j = 0; j < n; j++)
		scanf("%d", &V[j]);
		insertion(n, V);
		for(j = 0; j < n; j++)
		printf("%d ", V[j]);
		printf("\n");
		// printf("%d\n", insertion(n, V));
	}
	return 0;
}
