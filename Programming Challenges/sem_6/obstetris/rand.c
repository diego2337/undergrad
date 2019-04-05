#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(void)
{
	srand(time(NULL));
	int control, N, pontos, i, j, k;
	char nome;
	control = rand() % 1000 + 1;
	for(i = 0; i < control; i++)
	{
		N = rand() % 100 + 1;
		printf("%d\n", N);
		for(j = 0; j < N; j++)
		{
			nome = rand() % 26 + 97;
			printf("%c %c\n", nome, nome);
			for(k = 0; k < 12; k++)
			{
				pontos = rand() % 1000 + 1;
				if(k != 0)
					printf(" ");
				printf("%d", pontos);
			}
			printf("\n");
		}
	}
	printf("0");
	return 0;
}