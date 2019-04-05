#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fatorial(int num)
{
	if(num == 1)
		return 1;
	else if(num == 0)
		return 1;
	else
		return num * fatorial(num-1);
}

int main(void)
{
	int n, k, i, denominador, num;
	while(scanf("%d", &n) != EOF)
	{
		scanf("%d", &k);
		denominador = 1;
		for(i = 0; i < k; i++)
		{
			scanf("%d", &num);
			denominador = denominador * fatorial(num);
		}
		printf("%d\n", fatorial(n)/denominador);
	}
	return 0;
}