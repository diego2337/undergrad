#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
typedef unsigned long long int ulli;

void fatoracao_primos(ulli x, int vec[15])
{
	ulli i = 2; /* contador */
	while(i * i <= x)
		if((x % i) == 0)
		{
			/*printf("%llu\n", i);*/
			vec[i] = vec[i] + 1;
			x = x/i;
		}
		else 
			i = i + 1;
	/*printf("%llu\n", x);*/
	vec[x] = vec[x] + 1;
}

int main(void)
{
	int n, i, j, vec[15];
	ulli snacks, snacks2;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < 15; j++)
			vec[j] = 0;
		scanf("%llu", &snacks);
		snacks2 = 1;
		fatoracao_primos(snacks, vec);
		for(j = 0; j < 15; j++)
		{
			if(vec[j] % 2 != 0)
				vec[j] = vec[j] + 1;
		}
		for(j = 0; j < 15; j++)
		{
			if(vec[j] != 0)
				snacks2 = snacks2 * pow(j, vec[j]);
		}
		printf("%llu\n", snacks2);
		/*scanf("%llu", &snacks);
		snacks2 = snacks;
		yes = false;
		if(ceil(sqrt(snacks2))-floor(sqrt(snacks2)) != 0)
		{
			for(j = 0; j < floor(sqrt(snacks)); j++)
			{
				snacks2 = snacks2 + snacks;
				if(ceil(sqrt(snacks2))-floor(sqrt(snacks2)) == 0)
				{
					j = floor(sqrt(snacks)) + 15;
					yes = true;
				}
			}
			if(!yes)
			{
				snacks2 = pow(snacks, 2);
			}
		}
		else
			snacks2 = snacks;
		printf("Caso #%d: %llu\n", i+1, snacks2);*/
	}
	return 0;
}