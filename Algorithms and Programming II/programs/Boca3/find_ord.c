// Programa: findord.c
// Programador: Diego Cintra
// Data: 23/11/2012
// O dialogo: Esse programa e uma otimizacao do programa find, mudando sua busca de sequencial para binaria.
#include<stdio.h>
int buscabin(int arr[], int n, int k)
{
	int esq, dir, meio;
	esq = -1;
	dir = n;
	while(esq < dir-1)
	{		
		meio = (esq + dir)/2;
		if(arr[meio] < k)
		esq = meio;
		else
		dir = meio;
	}
	if(arr[dir] == k)
	return dir;
	else
	return -1;
}
int main(void)
{
	int j, l, n, rep, k, arr[100];
	scanf("%d", &rep);
	for(j = 0; j < rep; j++)
	{
		scanf("%d", &k); // numero a ser achado
		scanf("%d", &n); // tamanho do vetor
		for(l = 0; l < n; l++)
		scanf("%d", &arr[l]);
		buscabin(arr, n, k);
		printf("%d\n", buscabin(arr, n, k));
	}
	return 0;
}
