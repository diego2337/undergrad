#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int compare(const void *a, const void *b)
{
	return *(int*)a - *(int*)b;
}

int main(void)
{
	int *vec, n, nc, i, j;
	scanf("%d", &nc);
	for(j = 0; j < nc; j++)
	{
		scanf("%d", &n);
		vec = (int*)malloc(n*sizeof(int));
		for(i = 0; i < n; i++)
			scanf("%d", &vec[i]);
		qsort(vec, n, sizeof(int), compare);
		for(i = 0; i < n; i++)
		{
			if(i == 0)
				printf("%d", vec[i]);
			else
				printf(" %d", vec[i]);
		}
		printf("\n");
		free(vec);
	}
	return 0;
}