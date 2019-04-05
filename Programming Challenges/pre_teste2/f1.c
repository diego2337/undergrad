#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void compute_scores(int G, int races[101][101], int S, int scores[11][102], int P)
{
	int i, j, k, results[101] = {0}, max = -1, max_index[101] = {0}, max_count = 0;
	for(i = 0; i < S; i++)
	{
		for(j = 0; j < 101; j++)
		{
			results[j] = 0;
			max_index[j] = 0;
		}
		max = -1;
		max_count = 0;
		for(j = 0; j < scores[i][0]; j++)
		{
			/* Iterate through all lines of the jth column of races */
			for(k = 0; k < G; k++)
			{
				results[races[k][j]-1] += scores[i][j+1];
			}
		}
		/*for(j = 0; j < P; j++)
		{
			printf("%d ", results[j]);
		}
		printf("\n");*/
		for(j = 0, k = 0; j < P; j++)
		{
			if(max < results[j])
			{
				k = 0;
				max_count = 1;
				max = results[j];
				max_index[k] = j;
			}
			else if(max == results[j])
			{
				k++;
				max_index[k] = j;
				max_count++;
			}
		}
		for(j = 0; j < max_count; j++)
		{
			printf("%d", max_index[j]+1);
			if(j+1 != max_count)
				printf(" ");
		}
		printf("\n");
	}
}

int main(void)
{
	int i, j, G, P, races[101][101], S, K, scores[11][102];
	scanf("%d %d", &G, &P);
	while(G != 0 && P != 0)
	{
		for(i = 0; i < 101; i++)
		{
			for(j = 0; j < 101; j++)
				races[i][j] = 0;
		}
		for(i = 0; i < 11; i++)
		{
			for(j = 0; j < 101; j++)
				scores[i][j] = 0;
		}
		for(i = 0; i < G; i++)
		{
			for(j = 0; j < P; j++)
			{
				scanf("%d", &races[i][j]);
			}
		}
		scanf("%d", &S);
		for(i = 0; i < S; i++)
		{
			scanf("%d", &K);
			scores[i][0] = K;
			for(j = 1; j <= K; j++)
			{
				scanf("%d", &scores[i][j]);
			}
		}
		compute_scores(G, races, S, scores, P);
		scanf("%d %d", &G, &P);
	}
	return 0;
}