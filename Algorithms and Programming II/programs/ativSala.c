// Programa: ativSala.c
// Programadores: Diego e Rogerio
// Data: 16/01/2013
#include<stdio.h> // printf, scanf
#include<stdlib.h>
void intercala(int V[], int V2[], int n, int n2, int VS[])
{
	int i, j, k;
	i = 0;
	j = 0;
	k = 0;
	while(i < n && j < n2)
	{
		if(V[i] < V2[j])
		{
			VS[k] = V[i];
			i++;
		}
		else
		{
			VS[k] = V2[j];
			j++;
		}
		k++;
	}
	while(j < n2)
	{
		VS[k] = V2[j];
		j++;
		k++;
	}
	while(i < n)
	{
		VS[k] = V[i];
		i++;
		k++;
	}
}
int compara(const void *a, const void *b)
{
	return ((*(int*)a) - (*(int *)b));
}
int main(int argc, char *argV[])
{
	if(argc != 4)
	{
		printf("O arquivo %s não pôde ser aberto\n", argV[0]);
		return EXIT_FAILURE;
	}
	FILE *a;
	FILE *b;
	FILE *S;
	int V[10], V2[10], VS[10];
	int n, n2, i;

	a = fopen(argV[1], "r");
	fscanf(a, "%d", &n);
	for(i = 0; i < n; i++)
	{
		fscanf(a, "%d", &V[i]);
	}
	fclose(a);

	b = fopen(argV[2], "r");
	fscanf(b, "%d", &n2);
	for(i = 0; i < n2; i++)
	{
		fscanf(b, "%d", &V2[i]);
	}
	fclose(b);

	qsort(V, n, sizeof(int), compara);
	qsort(V2, n2, sizeof(int), compara);

	intercala(V, V2, n, n2, VS);
		
	S = fopen(argV[3], "w");
	for(i = 0; i < n + n2; i++)
	fprintf(S, "%d\n", VS[i]);
	
	fclose(S);	
	return 0;
}
