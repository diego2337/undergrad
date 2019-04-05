#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef unsigned long long int ulli;

ulli sum(ulli a, ulli b)
{
	ulli count = 0;
	count = (b*(b+1)/2)-((a-1)*(a)/2);
	return count;
}

int main(void)
{
	ulli a, b;
	scanf("%llu %llu", &a, &b);
	printf("%llu\n", sum(a, b));
	return 0;
}