#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int n, sum, aux, assumed_total, i;
	while(scanf("%d", &n) != EOF)
	{
		sum = 0;
		for(i = 0; i < n; i++)
		{
			scanf("%d", &aux);
			sum = sum + aux;
		}
		scanf("%d", &assumed_total);
		if(sum == assumed_total)
			printf("Acertou\n");
		else
			printf("Errou\n");
	}
	return 0;
}