#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


int factmod(int n, int m)
{
	if(n == 0)
		return 1;
	else
		return ((n)%((m))) * factmod(n-1, m);
}

void fatoracao_primos(long x, int powers[30000], int *max)
{
	long i = 2; /* contador */
	while(i * i <= x)
	{
		if((x % i) == 0)
		{
			/*printf("%ld\n", i);*/
			powers[i] = powers[i] + 1;
			if(i > *max)
				*max = i;
			x = x/i;
		}
		else i = i + 1;
	}
	/*printf("%ld\n", x);*/
	powers[x] = powers[x] + 1;
	if(x > *max)
		*max = x;
}

int get_powers(int n, int p)
{
    int res = 0, power;
    for (power = p ; power <= n ; power *= p)
        res += n/power;
    return res;
}

int main(void)
{
	int n, m, powers[30000], max, pode, i;
	bool not;
	while(scanf("%d %d", &n, &m) != EOF)
	{
		/* Decompor */
		memset(powers, 30000, 0);
		max = 0;
		not = false;
		fatoracao_primos(m, powers, &max);
		printf("%d\n", max);
		for(i = 2; i < max; i++)
		{
			if(powers[i] != 0)
				pode = get_powers(n, i);
			if(pode < powers[i])
			{
				not = true;
				break;
			}
		}
		if(!not)
			printf("%d divides %d!", m, n);
		else
			printf("%d does not divide %d!", m, n);
		printf("\n");
	}
	return 0;
}