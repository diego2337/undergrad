#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int **matrix, W, H, N, i, j, k, count, x1, y1, x2, y2;
	scanf("%d %d %d", &W, &H, &N);
	while(W != 0 && H != 0 && N != 0)
	{
		count = W*H;
		matrix = (int**)calloc(W, sizeof(int*));
		for(i = 0; i < W; i++)
		{
			*(matrix+i) = (int*)calloc(H, sizeof(int*));
		}
		for(i = 0; i < N; i++)
		{
			scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
			for(j = x1-1; j <= x2-1; j++)
			{
				for(k = y1-1; k <= y2-1; k++)
				{
					if(matrix[j][k] != 1)
					{
						matrix[j][k] = 1;
						count = count - 1;
					}
				}
			}
		}
		if(count == 0)
		{
			printf("There is no empty spots.\n");
		}
		else if(count == 1)
		{
			printf("There is one empty spot.\n");
		}
		else
			printf("There are %d empty spots.\n", count);
		for(i = 0; i < W; i++)
		{
			free(*(matrix+i));
		}
		free(matrix);
		scanf("\n");
		scanf("%d %d %d", &W, &H, &N);
	}
	return 0;
}