#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
	/* data */
	int size;
	int count;
}bota;

int pair(int left[], int right[])
{
	int i, pairs = 0;
	for(i = 30; i < 61; i++)
	{
		if(left[i] != 0 && right[i] != 0)
		{	
			if(left[i] < right[i])
				pairs += left[i];
			else
				pairs += right[i];
		}
	}
	return pairs;
}

int main(void)
{
	int n, index, i, pairs;
	int left[101], right[101];
	char where_to;
	while(scanf("%d", &n) != EOF)
	{
		pairs = 0;
		for(i = 30; i < 61; i++)
		{
			left[i] = 0;
			right[i] = 0;
		}
		for(i = 0; i < n; i++)
		{
			scanf("%d %c", &index, &where_to);
			if(where_to == 'E')
			{
				left[index]++;
			}
			else
				right[index]++;
		}
		pairs = pair(left, right);
		printf("%d\n", pairs);
	}
	return 0;
}