#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef unsigned long long int ulli;

ulli digit_sum(ulli i)
{
	ulli count = 0;
	if(i / 10 == 0)
		return i;
	else
	{
		while(i > 0)
		{
			count = count + i%10;
			i = i / 10;
		}
	}
	return count;
}

bool isPrime(ulli n)
{
	if(n == 2 || n == 3 || n ==  5 || n == 7)
		return true;
	else if(n % 2 == 0 || n % 3 == 0 || n % 5 == 0 || n % 7 == 0)
		return false;
	else
		return true;
}

ulli fatoracao_primos(ulli x)
{
	ulli i = 2, count = 0; /* contador */
	if(isPrime(x))
	{
		count = count + 1;
	}
	while(i * i <= x)
	{
		if((x % i) == 0)
		{
			/*printf("%llu\n", i);*/
			count = count + digit_sum(i);
			x = x/i;
		}
		else 
			i = i + 1;
	}
	/*printf("%llu\n", x);*/
	count = count + digit_sum(x);
	return count;
}

bool isSmith(ulli n)
{
	if(digit_sum(n) == fatoracao_primos(n))
	{
		if(!isPrime(n))
			return true; 
		else
			return false;
	}
	else
		return false;
}

int main(void)
{
	int test_cases, i, j;
	ulli n;
	scanf("%d", &test_cases);
	for(i = 0; i < test_cases; i++)
	{
		scanf("%llu", &n);
		for(j = 0; j < 10000; j++)
		{
			n = n + 1;
			if(isSmith(n))
			{
				printf("%llu\n", n);
				j = 100000 * 3;
			}
		}
	}
	return 0;
}