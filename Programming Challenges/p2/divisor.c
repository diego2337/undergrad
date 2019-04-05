#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef unsigned long long int ulli;

ulli get_divisors(ulli n)
{
	ulli i, count = 0;
	int sqr = sqrt(n);
	for(i = 1; i <= sqr; i++)
	{
		if(n % i == 0)
		{
			count = count + 2;
		}
	}
	if(sqr*sqr == n)
		count--;
	return count;
}

int main(void)
{
	ulli N, L, U, max_divisors, max_index, i, j, divisors;
	scanf("%llu", &N);
	for(i = 0; i < N; i++)
	{
		scanf("%llu %llu", &L, &U);
		max_index = max_divisors = 0;
		for(j = L; j <= U; j++)
		{
			divisors = get_divisors(j);
			if(divisors > max_divisors)
			{
				max_divisors = divisors;
				max_index = j;
			}
		}
		printf("Between %llu and %llu, %llu has a maximum of %llu divisors.\n", L, U, max_index, max_divisors);
	}
	return 0;
}