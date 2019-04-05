#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void flip(int pancakes[31], int min, int i)
{
	int j = i-1, temp;
	while(min < j)
	{
		temp = pancakes[min];
		pancakes[min] = pancakes[j];
		pancakes[j] = temp;
		min++;
		j--;
	}
}

int main(void)
{
	int pancakes[31], original[31], flips[31], i, j, sorted, min, min_index;
	char c;
	c = getchar();
	while(c != EOF)
	{
		i = 0;
		sorted = 0;
		min = min_index = 1000000;
		for(j = 0; j < 31; j++)
			flips[j] = 0;
		while(c != '\n' && c != EOF)
		{
			pancakes[i] = atoi(&c);
			c = getchar();
			while(isdigit(c))
			{
				pancakes[i] = pancakes[i]*10 + atoi(&c);
				c = getchar();
			}
			if(pancakes[i] < min_index)
			{
				min = i;
				min_index = pancakes[i];
			}
			original[i] = pancakes[i];
			if(c != '\n')
				c = getchar();
			i++;
		}
		while(sorted != i)
		{
			if(min == sorted)
			{
				pancakes[sorted] = 10000000;
				sorted++;
			}
			else
			{
				if(min != i-1)
				{
					flip(pancakes, min, i);
				}
				if(sorted != i-1)
					flip(pancakes, sorted, i);
				flips[min+1] = flips[min+1] + 1;
				flips[sorted+1] = flips[sorted+1] + 1;
				pancakes[sorted] = 10000000;
				sorted++;
			}
			/* Achar novo min */
			min = min_index = 10000000;
			for(j = 0; j < i; j++)
			{
				if(pancakes[j] < min_index)
				{
					min = j;
					min_index = pancakes[j];
				}
			}
		}
		for(j = 0; j < i; j++)
		{
			printf("%d ", original[j]);
		}
		printf("\n");
		for(j = 1; j < i; j++)
		{
			if(flips[j] != 0)
				printf("%d ", j);
		}
		printf("0");
		printf("\n");
		c = getchar();
	}
	return 0;
}