#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned long int path,peso[100001];
int pred[100001];

unsigned long int lowestWeight(int u, int v)
{
	if(u == v)
		return 0;
	else if(v > u)
		return peso[v] + lowestWeight(u, pred[v]);
	else
		return peso[u] + lowestWeight(pred[u], v);
}

int main(void)
{
	int u, v, n, i, a, q;
	unsigned long int l;
	scanf("%d", &n);
	while(n != 0)
	{
		for(i = 1; i <= n-1; i++)
		{
			scanf("%d %lu", &a, &l);
			pred[i] = a;
			peso[i] = l;

		}
		scanf("%d", &q);
		for(i = 0; i < q; i++)
		{
			if(i != 0)
				printf(" ");
			path = 0;
			scanf("%d %d", &u, &v);
			path = lowestWeight(u, v);
			printf("%lu", path);
		}
		printf("\n");
		scanf("%d", &n);
	}
	return 0;
}