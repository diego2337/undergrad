#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int main(void)
{
	char num[12], cutoff[12], c;
	int i, dot, cutoff_dot;
	unsigned int number;
	bool roundup;
	c = getchar();
	while(c != EOF)
	{
		for(i = 0; i < 12; i++)
		{
			num[i] = '0';
			cutoff[i] = '0';
		}
		i = 0;
		dot = 0;
		roundup = true;
		while(c != '\n')
		{
			if(c == '.')
				dot = i;
			num[i] = c;
			i++;
			c = getchar();
		}
		num[i] = '\0';
		number = 0;
		if(dot != 0)
		{
			for(i = 0; i < dot; i++)
			{
				c = num[i];
				number += atoi(&c) * pow(10, (dot-1)-i);
			}
		}
		else
		{
			for(i = 0; i < strlen(num); i++)
			{
				c = num[i];
				number += atoi(&c) * pow(10, (strlen(num)-1)-i);
			}	
		}
		/* '\n' */
		c = getchar();
		i = 0;
		while(c != '\n')
		{
			if(c == '.')
				cutoff_dot = i;
			cutoff[i] = c;
			i++;
			c = getchar();
		}
		if(dot == 0)
		{
			printf("%d", number);
		}
		else
		{
			dot++;
			cutoff_dot++;
			for(i = 0; i < 12; i++)
			{
				if(atoi(&num[dot] - cutoff[cutoff_dot]) < 0)
				{
					roundup = false;
					i = 15;
				}
				else
				{
					dot++;
					cutoff_dot++;
				}
			}
			if(roundup)
			{
				number++;
				printf("%d", number);
			}
			else
			{
				number--;
				printf("%d", number);
			}
		}
		printf("\n");
		c = getchar();
	}
	return 0;
}