// Programa: heap.c
// Programador: Diego Cintra
// Data: 14/12/2012
#include<stdio.h>
int pai(int i)
{
	int r;
	if(i == 0)
	r = 0;
	else
	r = (i-1)/2;
	return r;
}
int dir(int i)
{
	return 2*(i + 1);
}
int esq(int i)
{
	return (2*(i+1)-1);
}
void sobe(int V[], int i)
{
	int aux;
	while(V[pai(i)] < V[i])
	{
		aux = V[pai(i)];
		V[pai(i)] = V[i];
		V[i] = aux;
		i = pai(i);
	}
}
void insere(int *n, int V[], int X)
{
	*n = *n + 1;
	V[*n-1] = X;
	sobe(V, *n-1);
}
void desce(int n, int V[], int i)
{
	int e, d, maior, aux;
	e = esq(i);
	d = dir(i);
	maior = i;
	if(e < n && V[e] > V[maior]) 
	maior = e;
	if(d < n && V[d] > V[maior])
	maior = d;
	if(i != maior)
	{
		aux = V[maior];
		V[maior] = V[i];
		V[i] = aux;
		desce(n, V, maior);
	}
}
void cheap(int n, int V[])
{
	int i;
	i = pai(n-1);
	while(i >= 0)
	{
		desce(n, V, i);
		i--;
	}
}
int main(void)
{
	int V[100], X, n, j, k, l, m, rep;
	scanf("%d", &rep);
	for(j = 0; j < rep; j++)
	{
		scanf("%d", &n);
		for(k = 0; k < n; k++)
		scanf("%d", &V[k]);
		cheap(n, V);
		for(m = 0; m < 3; m++)
		{
			scanf("%d", &X);	
			insere(&n, V, X);
		}
		for(l = 0; l < n; l++)
		printf("%d ", V[l]);
		printf("\n");
	}
	return 0;
}
