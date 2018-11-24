// Programa: find.c
// Programador: Diego Cintra
// Data: 23/11/2012
// O dialogo: Esse programa ira ler, em um vetor v, um numero k, imprimindo 1 se acha-lo e -1 se nao.
#include<stdio.h>
int buscaseq(int arr[], int n, int k)
{
	int i = 0;
	while(i < n)
	{		
		if(arr[i] == k)
		return i;
		i++;
	}
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
		buscaseq(arr, n, k);
		printf("%d\n", buscaseq(arr, n, k));
	}
	return 0;
}
