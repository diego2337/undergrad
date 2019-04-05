#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long int ulli;
int main(void)
{
	int n, m, u, L, R, v, p, i, k;
	ulli *arr;
	ulli aux;
	scanf("%d %d %d", &n, &m, &u);
	arr = (ulli*)malloc(n*sizeof(ulli));
	for(i = 0; i < n; i++)
	{
		scanf("%llu", &arr[i]);
	}
	k = 0;
	scanf("%d %d %d %d", &L, &R, &v, &p);
	for(i = L-1; i  < R-1; i++)
	{
		if(arr[i] < v)
			k++;
	}
	aux = u*k;
	aux = aux / (R-L+1);
	arr[p-1] = aux;
	for(i = 0; i < n; i++)
	{
		printf("%llu\n", arr[i]);
	}
	return 0;
}