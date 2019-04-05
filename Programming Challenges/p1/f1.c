#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(void)
{
	int G, P, K, S, i, j, l, pilots[201][201], scores[201], results[201], max;
	bool space;
	scanf("%d %d", &G, &P);
	while(G != 0 && P != 0)
	{
		for(i = 0; i < G; i++)
		{
			for(j = 0; j < P; j++)
			{
				scanf("%d", &l);
				pilots[i][l-1] = j;
			}
		}
		scanf("%d", &S);
		for(i = 0; i < S; i++)
		{
			max = 0;
			space = false;
			for(j = 0; j < P; j++)
				results[j] = 0;
			scanf("%d", &K);
			for(j = 0; j < K; j++)
			{
				scanf("%d", &scores[j]);
			}
			for(j = 0; j < G; j++)
			{
				for(l = 0; l < K; l++)
				{
					results[pilots[j][l]] = results[pilots[j][l]] + scores[l];
					if(results[pilots[j][l]] >= max)
						max = results[pilots[j][l]];
				}
			}
			for(j = 0; j <= K; j++)
			{
				if(results[j] == max)
				{
					if(space)
						printf(" ");
					else
						space = true;
					printf("%d", j+1);
				}
			}
			printf("\n");
		}
		scanf("%d %d", &G, &P);
	}
	printf("\n");
	return 0;
}