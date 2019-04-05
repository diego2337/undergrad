#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int M;

int compare(const void *a, const void *b)
{
	int x = *(int*)a;
	int y = *(int*)b;
	if(x % M == y % M)
	{
		if((x % 2 != 0) && (y % 2 == 0))
			return x-y;
		else if((x % 2 == 0) && (y % 2 != 0))
			return y-x;
		else if((x % 2 != 0) && (y % 2 != 0))
		{
			if(x > y)
				return x-y;
			else
				return y-x;
		}
		else
		{
			if(x > y)
				return y-x;
			else
				return x-y;
		}
	}
	else
		return (x%M)-(y%M);

}

int main(void)
{
	int N, numbers[10001], i;
	scanf("%d %d", &N, &M);
	while(N != 0 && M != 0)
	{
		for(i = 0; i < N; i++)
			scanf("%d",  &numbers[i]);
		qsort(numbers, i, sizeof(int), compare);
		printf("%d %d\n", N, M);
		for(i = 0; i < N; i++)
			printf("%d\n", numbers[i]);
		scanf("%d %d", &N, &M);
	}
	printf("0 0\n");
	return 0;
}