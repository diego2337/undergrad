#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


void toBin(int n, int *b1)
{
	int c, i = 0, aux;
	for(c = 31, i; c >= 0; c--, i++)
	{
		aux = n >> c;
		if(aux & 1)
			*b1 = *b1 + 1;
	}
}

int main(void)
{
	int N, num, b1, b2, i, j, k;
	char M[10], c;
	scanf("%d", &N);
	scanf("\n");
	c = getchar();
	for(i = 0; i < N; i++)
	{
		j = 0;
		num = 0;
		b1 = 0;
		b2 = 0;
		while(c != '\n')
		{
			printf("j: %d\n", j);
			M[j] = c;
			c = getchar();
			j++;
		}
		for(k = 0; k < j; k++)
		{
			c = M[k];
			num = num + atoi(&c) * pow(10, (j-1)-k);
		}
		toBin(num, &b1);
		for(k = 0; k < j; k++)
		{
			c = M[k];
			toBin(atoi(&c), &b2);
		}
		printf("%d %d\n", b1, b2);
		c = getchar();
	}
	return 0;
}