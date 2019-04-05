#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
	int N, L, i, j, k, value;
	char c;
	scanf("%d", &N);
	for(i = 0; i < N; i++)
	{
		value = 0;
		scanf("%d", &L);
		scanf("\n");
		for(j = 0; j < L; j++)
		{
			k = 0;
			c = getchar();
			while(c != '\n')
			{
				/* Valor = caracter - 65 + j + k */
				value = value + (c-65) + j + k;
				k++;
				c = getchar();
			}
		}
		printf("%d\n", value);
	}
	return 0;
}