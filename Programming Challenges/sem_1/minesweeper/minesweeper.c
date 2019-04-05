/* Autor: Diego Silva Cintra 
   Data: 27/02/2015 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sweep(char **mine, int **sweeper, int n, int m)
{
	int i, j, count;
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < m; j++)
		{
			count = 0;
			if(mine[i][j] == '*')
				sweeper[i][j] = -1;
			else
			{
				if(i-1 >= 0 && mine[i-1][j] == '*')
					count++;
				if(i-1 >= 0 && j+1 < m && mine[i-1][j+1] == '*')
					count++;
				if(j+1 < m && mine[i][j+1] == '*')
					count++;
				if(i+1 < n && j+1 < m && mine[i+1][j+1] == '*')
					count++;
				if(i+1 < n && mine[i+1][j] == '*')
					count++;
				if(i+1 < n && j-1 >= 0 && mine[i+1][j-1] == '*')
					count++;
				if(j-1 >= 0 && mine[i][j-1] == '*')
					count++;
				if(i-1 >= 0 && j-1 >= 0 && mine[i-1][j-1] == '*')
					count++;
				sweeper[i][j] = count;
			}
		}
	}
}

int main(void)
{
	int i=1, j=1, it, it2, times = 1, i_result, j_result;
	char **mine;
	int **sweeper;
	while(scanf("%d %d", &i, &j) && i != 0 && j != 0)
	{
		mine = (char**)malloc (i*sizeof(char*));	
		sweeper = (int**)malloc (i*sizeof(int*));
		for(it = 0; it < i; it++)
		{
			*(mine+it) = (char*)malloc (j*sizeof(char*));
			*(sweeper+it) = (int*)malloc (j*sizeof(int*));
			for(it2 = 0; it2 < j; it2++)
			{
				scanf(" %c", &(*(*(mine+it)+it2)));
				(*(*(sweeper+it)+it2)) = 0;
			}
		}
		sweep(mine, sweeper, i, j);
		if(times != 1)
			printf("\n");
		printf("Field #%d:\n", times);
		for(i_result = 0; i_result < i; i_result++)
		{
			for(j_result = 0; j_result < j; j_result++)
			{
				if(sweeper[i_result][j_result] == -1)
					printf("*");
				else
					printf("%d", sweeper[i_result][j_result]);
			}
			printf("\n");
		}
		times++;
		free(mine);
		free(sweeper);
	}
	return 0;
}