#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(void)
{
	int i, i2, m, n, j, k;
	FILE *arq;
	int v[100];
	srand(time(NULL));
	arq = fopen("sortmod.txt", "w");
	i = rand() % 50;
	fprintf(arq, "%d\n", i);
	for(i2 = 0; i2 < i; i2++)
	{
		n = rand() % 100;
		m = (rand() % 100) + 1;
		fprintf(arq, "%d %d\n", n, m);
		for(j = 0; j < n; j++)
		{
			v[j] = rand() % 100;
			fprintf(arq, "%d ", v[j]);
		}
		fprintf(arq, "\n");
	}

}