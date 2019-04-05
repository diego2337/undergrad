#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b)
{
	return ((*(int*)a) - (*(int *)b));
}

int asc_cmp(const void *a, const void *b)
{
	return ((*(int*)b) - (*(int *)a));
}

int main(void)
{
	int N, i, j, k, num, even[100001] = {0}, odd[100001] = {0};
	scanf("%d", &N);
	j = 0;
	k = 0;
	for(i = 0; i < N; i++)
	{
		scanf("%d", &num);
		if(num % 2 == 0)
		{
			even[j] = num;
			j++;
		}
		else
		{
			odd[k] = num;
			k++;
		}
	}
	qsort(even, j, sizeof(int), cmp);
	qsort(odd, k, sizeof(int), asc_cmp);
	for(i = 0; i < j; i++)
	{
		printf("%d\n", even[i]);
	}
	for(i = 0; i < k; i++)
	{
		printf("%d\n", odd[i]);
	}
	return 0;
}