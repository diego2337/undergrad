#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

void sieve(int upper, bool primes[65000])
{
	int i, j;
	for(i = 2; i <= floor(sqrt(upper)); i++)
	{
		for(j = i; j <= upper; j = j + j)
		{
			primes[j] = false;
		}
	}
}

int mod_pow(long long base, int exp, int mod) 
{
    long long result = 1;
    while(exp > 0) 
    {
        if(exp % 2 == 1)
            result = (result * base) % mod;
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

bool isCarmichael(long long n, bool primes[65000])
{
	int i;
	if(primes[n] == true)
		return false;
	else
	{
		for(i = 2; i < n; i++)
		{
			if(mod_pow(i, n, n) != i) return false;
		}
		return true;
	}
}

int main(void)
{
	long long n;
	bool primes[65000] = {true}, carmichael[65000];
	sieve(65000, primes);
	for(n = 2; n <=65000; n++)
	{
		carmichael[n] = isCarmichael(n, primes);
	}
	scanf("%lld", &n);
	while(n != 0)
	{
		if(carmichael[n])
		{
			printf("The number %lld is a Carmichael number.", n);
		}
		else
			printf("%lld is normal.", n);
		printf("\n");
		scanf("%lld", &n);
	}
	return 0;
}