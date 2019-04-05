#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int n, m, i, k, v, **elements, *indexes, num;
	while(scanf("%d", &n) != EOF)
	{
		scanf("%d", &m);
		indexes = (int*)calloc(n, sizeof(int));
		elements = (int**)calloc(n+1, sizeof(int));
		for(i = 0; i < n; i++)
		{
			*(elements+i) = (int*)calloc(n+1, sizeof(int));
		}
		for(i = 0; i < n; i++)
		{
			scanf("%d", &num);
			elements[num][indexes[num]] = i+1;
			indexes[num] = indexes[num] + 1;
		}
		for(i = 0; i < m; i++)
		{
			scanf("%d %d", &k, &v);
			if(elements[v][k-1] == 0)
				printf("0\n");
			else
				printf("%d\n", elements[v][k-1]);
			/*for(j = 0; j < n; j++)
			{
				if(elements[j] == v)
				{
					if(count == k)
					{
						printf("%d\n", j+1);
						printed = 1;
						j = n + 10;
					}
					else
						count++;
				}
			}
			if(printed == 0)
				printf("0\n");*/
		}		
		free(indexes);
	}
	return 0;
}