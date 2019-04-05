#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	srand(time(NULL));
	int i = 0, j, N, T, G, goal1, goal2;
	N = rand() % 1000 + 1;
	printf("%d\n", N);
	for(i = 0; i < N; i++)
	{
		printf("Campeonato %d\n", i);
		T = rand() % 30 + 1;
		printf("%d\n", T);
		for(j = 0; j < T; j++)
		{
			printf("Time %d\n", j);
		}
		/*G = rand() % 1000 + 1;*/
		printf("%d\n", T-1);
		for(j = 0; j < T-1; j++)
		{
			goal1 = rand() % 20;
			goal2 = rand() % 20;
			printf("Time %d#%d@%d#Time %d\n", j, goal1, goal2, j+1);
		}
	}
	return 0;
}