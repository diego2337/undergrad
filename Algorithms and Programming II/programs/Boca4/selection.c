// Programa: selection.c
// Programador: Diego Cintra
// Data: 30/11/2012
// O dialogo: Esse programa ira fazer a ordenacao de vetores por meio do selection sort, imprimindo o numero de trocas para a operacao.
#include<stdio.h>
int selection(int n, int V[])
{
	int i, j, min, aux = 0, trocas = 0;
	for(i = 0; i < n -1; i++)
	{
		min = i;
		for(j = i + 1; j < n; j++)
		{
			if(V[min] > V[j])
			{
				min = j;
			}
		}
		if(i != min)
		{
			aux = V[i];
			V[i] = V[min];
			V[min] = aux;
			trocas++;
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
		scanf("%d", &V[j]);
		printf("%d\n", selection(n, V));
	}
	return 0;
}
