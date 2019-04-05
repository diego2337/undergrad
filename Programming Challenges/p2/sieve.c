#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
typedef unsigned long long int ulli;

bool *primes;

void sieve(ulli n)
{
	ulli i = 2, j, max = floor(sqrt(n));
	for(; i < max; i++)
	{
		for(j = i; j < n; j = j + j)
		{
			primes[j] = true;
		}
	}

}

int main(void)
{
	int n, i;
	ulli j;
	scanf("%llu", &j);
	primes = (bool*)malloc(j*sizeof(bool));
	sieve(j);
	return 0;
}