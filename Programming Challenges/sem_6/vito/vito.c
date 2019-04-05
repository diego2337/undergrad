#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b)
{
	return ((*(int*)a) - (*(int *)b));
}

int main(void)
{
	int n, i, r, j, base, distance, streets[501];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		distance = 0;
		scanf("%d", &r);
		for(j = 0; j < r; j++)
		{
			scanf("%d", &streets[j]);
		}
		qsort(streets, r, sizeof(int), cmp);
		base = streets[r/2];
		for(j = 0; j < r; j++)
		{
			distance += abs(base-streets[j]);
		}
		printf("%d", distance);
		if(i != n-1)
			printf("\n");
	}
	return 0;
}