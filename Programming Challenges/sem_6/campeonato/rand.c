#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	srand(time(NULL));
	int i = 0, j, N, T, G, goal1, goal2, team1, team2;
	char teams[31][101];
	N = rand() % 1000 + 1;
	printf("%d\n", N);
	for(i = 0; i < N; i++)
	{
		printf("Campeonato %d\n", i);
		T = rand() % 30 + 1;
		printf("%d\n", T);
		for(j = 0; j < T; j++)
		{
			teams[j][0]= 'T';
			teams[j][1] = 'i';
			teams[j][2] = 'm';
			teams[j][3] = 'e';
			teams[j][4] = ' ';
			teams[j][5] = j;
			teams[j][6] = '\0';
		}
		G = rand() % 1000 + 1;
		printf("%d\n", G);
		for(j = 0; j < G; j++)
		{
			goal1 = rand() % 20;
			goal2 = rand() % 20;
			team1 = rand() % 30;
			team2 = rand() % 30;
			printf("%s#%d@%d#%s\n", teams[team1], goal1, goal2, teams[team2]);
		}
	}
	return 0;
}