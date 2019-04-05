#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
	int i;
	unsigned long long int n, x;
	scanf("%llu", &n);
	for(i = 0; i < n; i++)
	{
		scanf("%llu", &x);
		x = pow(2, x) - 1;
		x = x / 12;
		if(x < 1000)
		{
			printf("0");
		}
		else
		{
			x = x / 1000;
			printf("%llu", x);
		}
		printf(" kg\n");
	}
	return 0;
}