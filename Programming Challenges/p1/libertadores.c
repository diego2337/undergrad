#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int i, j, i2, j2, k, team1, team2, N;
	char c;
	scanf("%d", &N);
	for(k = 0; k < N; k++)
	{
		team1 = team2 = 0;
		/* First game */
		scanf("%d", &i);
		scanf(" %c", &c);
		scanf("%d", &j);
		scanf("\n");
		if(i > j)
			team1 = 3;
		else if(i < j)
			team2 = 3;
		else
			team1 = team2 = 1;
		/* Second game */
		scanf("%d", &i2);
		scanf(" %c", &c);
		scanf("%d", &j2);
		if(i2 > j2)
			team2 = team2 + 3;
		else if(i2 < j2)
			team1 = team1 + 3;
		else
		{
			team1 = team1 + 1;
			team2 = team2 + 1;
		}
		if(team1 > team2)
		{
			printf("Time 1");
		}
		else if(team2 > team1)
			printf("Time 2");
		else
		{
			if((i+j2)-(i2+j) > (i2+j)-(i+j2))
				printf("Time 1");
			else if((i2+j)-(i+j2) < (i+j2)-(i2+j))
				printf("Time 2");
			else
			{
				if(j > j2)
					printf("Time 2");
				else if(j < j2)
					printf("Time 1");
				else
					printf("Penaltis");
			}
		}
		printf("\n");
	}
	return 0;
}