#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(void)
{
	int N, s_grid[1001], c_grid[1001], positions[1001], i;
	bool defective;
	scanf("%d", &N);
	while(N != 0)
	{
		defective = false;
		for(i = 0; i < N; i++)
		{
			scanf("%d %d", &c_grid[i], &positions[i]);
			s_grid[i] = 0;
		}
		for(i = 0; i < N; i++)
		{
			if(i+positions[i] < 0 || i+positions[i] > N || s_grid[i+positions[i]] != 0)
			{
				printf("-1");
				defective = true;
				i = N + 10;
			}
			else
			{
				s_grid[i+positions[i]] = c_grid[i]; 
			}
		}
		if(!defective)
		{
			for(i = 0; i < N; i++)
			{
				printf("%d", s_grid[i]);
				if(i != N-1)
					printf(" ");
			}
		}
		printf("\n");
		scanf("%d", &N);
	}
	return 0;
}