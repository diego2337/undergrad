#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double measure(char c)
{
	switch(c)
	{
		case 'W':
			return 1;
			break;
		case 'H':
			return (double)1/2;
			break;
		case 'Q':
			return (double)1/4;
			break;
		case 'E':
			return (double)1/8;
			break;
		case 'S':
			return (double)1/16;
			break;
		case 'T':
			return (double)1/32;
			break;
		case 'X':
			return (double)1/64;
			break;
		default:
			return 0;
			break;
	}
}

int main(void)
{
	int i, j, count;
	double total;
	char c, compasso[201];
	c = getchar();
	while(c != '*')
	{
		while(c != '/')
			c = getchar();
		c = getchar();
		count = 0;
		while(c != '\n')
		{
			i = 0;
			total = 0;
			while(c != '/')
			{
				compasso[i] = c;
				c = getchar();
				i++;
			}
			for(j = 0; j < i; j++)
			{
				total = total + measure(compasso[j]);
			}
			if(total == 1)
			{
				count++;
			}
			c = getchar();
		}
		printf("%d\n", count);
		c = getchar();
	}
	return 0;
}