#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void count(long long int bowls[51], int n)
{
	int i, j;
	long long int count = 0;
	for(i = n-1; i >= 0; i--)
	{
		count = count + bowls[i];
		for(j = i-1; j >= 0; j--)
		{
			bowls[j] = bowls[j] + bowls[i];
		}
	}
	printf("%lld\n", count);
}

int main(void)
{
	int n, i;
	long long int bowls[51];
	scanf("%d", &n);
	while(n != 0)
	{
		for(i = 0; i < n; i++)
		{
			scanf("%lld", &bowls[i]);
		}
		count(bowls, n);
		scanf("%d", &n);
	}
	return 0;
}