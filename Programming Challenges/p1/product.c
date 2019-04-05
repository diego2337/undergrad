#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(void)
{
	int N, K, arr[100005], negatives[100005], i, j, tmp, tmp2, count, total_count;
	char c;
	bool zero, index;
	while(scanf("%d", &N) != EOF)
	{
		scanf("%d", &K);
		scanf("\n");
		total_count = 0;
		j = 0;
		for(i = 0; i < N; i++)
		{
			scanf("%d", &arr[i]);
			if(arr[i] <= 0)
			{
				negatives[j] = i;
				j++;
				total_count++;
			}
		}
		/*for(j = 0; j < total_count; j++)
				{
					printf("%d ", negatives[j]);
				}
				printf("\n");*/
		scanf("\n");
		for(i = 0; i < K; i++)
		{
			zero = false;
			index = false;
			count = 0;
			c = getchar();
			if(c == 'C')
			{
				scanf("%d %d", &tmp, &tmp2);
				arr[tmp-1] = tmp2;
				for(j = 0; j < total_count; j++)
				{
					if(negatives[j] == tmp-1 && tmp2 > 0)
					{
						negatives[j] = -1;
					}
					if(negatives[j] == tmp-1 && tmp2 <= 0)
						index = true;
				}
				if(!index && tmp2 <= 0)
				{
					negatives[total_count] = tmp-1;
					total_count++;
				}
				/*for(j = 0; j < total_count; j++)
				{
					printf("%d ", negatives[j]);
				}
				printf("\n");*/
			}
			else if(c == 'P')
			{
				scanf("%d %d", &tmp, &tmp2);
				for(j = 0; j < total_count; j++)
				{
					if(negatives[j] != -1 && arr[negatives[j]] == 0)
					{
						printf("0");
						zero = true;
						break;
					}
					else if(negatives[j] != -1 && negatives[j] <= tmp2-1 && negatives[j] >= tmp-1)
					{
						count++;
					}
				}
				if(!zero && count % 2 == 0)
					printf("+");
				else if(!zero && count % 2 == 1)
					printf("-");
				/*for(j = tmp-1; j <= tmp2-1; j++)
				{
					if(arr[j] == 0)
					{
						printf("0");
						zero = true;
						j = tmp2 + 10;
					}
					else if(arr[j] < 0)
					{
						count++;
					}
				}
				if(count % 2 == 0 && !zero)
				{
					printf("+");
				}
				else if(count % 2 == 1 && !zero)
				{
					printf("-");
				}*/
			}
			scanf("\n");
		}
		printf("\n");
	}
	return 0;
}