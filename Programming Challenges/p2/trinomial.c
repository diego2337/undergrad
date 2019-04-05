#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
	unsigned long long int n, i;
	scanf("%llu", &n);
	i = pow(3, n);
	printf("%llu\n", i);
	return 0;
}