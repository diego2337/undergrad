#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

unsigned long long int facts[21] = 
{1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800, 479001600, 6227020800u, 87178291200u, 1307674368000u, 20922789890000u, 
	355687428100000u, 6402373706000000u, 121645100400000000u, 2432902008000000000u};

unsigned long long int fact(unsigned long long int x)
{
	if(x == 1 || x == 0)
		return 1;
	else
		return x * fact(x-1);
}

int main(void)
{
	int x, y;
	unsigned long long int result;
	while(scanf("%d %d", &x, &y) != EOF)
	{
		result = fact(x) + fact(y);
		printf("%llu\n", result);
	}	
	return 0;
}