#include <stdio.h>
#include <stdlib.h>
#include <math.h>

unsigned long long int bhaskara(unsigned long long int n)
{
	return (sqrt(1 + 4*2*n)-1)/2;
}

int main(void)
{
	unsigned long long int n, test_cases, i;
	scanf("%llu", &test_cases);
	for(i = 0; i < test_cases; i++)
	{
		scanf("%llu", &n);
		printf("%llu\n", bhaskara(n));
	}
	return 0;
}