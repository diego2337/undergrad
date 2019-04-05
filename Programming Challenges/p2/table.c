#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef unsigned long long int ulli;

/* sum of prime factors times 2 */
ulli dec(ulli x)
{
	ulli i = 2, count = 0; /* contador */
	while(i * i <= x)
		if((x % i) == 0)
		{
			/*printf("%llu\n", i);*/
			count++;
			x = x/i;
		}
		else 
			i = i + 1;
	/*printf("%llu\n", x);*/
	count++;
	return count*2;
}

ulli f(ulli N)
{
	if(N == 1)
	{
		return 1;
	}
	else
	{
		puts("wheres that guy");
		printf("%llu\n", dec(N));
		return pow(N, 2) - ((N-1) + dec(N) + f(N-1));
	}
}

int main(void)
{
	ulli N;
	scanf("%llu", &N);
	while(N != 0)
	{
		printf("%llu\n", f(N));
		scanf("%llu", &N);
	}

	return 0;
}