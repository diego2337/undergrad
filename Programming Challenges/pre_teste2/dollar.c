#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
	char dollar[11], cents[3], c;
	int i, j;
	c = getchar();
	while(c != EOF)
	{
		for(i = 0; i < 11; i++)
			dollar[i] = 0;
		for(i = 0; i < 3; i++)
			cents[i] = 0;
		j = 0;
		/* Dollar */
		while(c != '\n')
		{
			if(isdigit(c))
			{
				dollar[j] = c;
				j++;
			}
			c = getchar();
		}
		/* Cents */
		c = getchar();
		j = 0;
		while(c != '\n')
		{
			if(isdigit(c))
			{
				cents[j] = c;
				j++;
			}
			c = getchar();
		}
		/* Printing */
		if(strlen(dollar) != 0)
		{
			i = 0;
			j = strlen(dollar) % 3;
			printf("$");
			if(j != 0 && strlen(dollar) > 3)
			{
				for(i = 0; i < j; i++)
					printf("%c", dollar[i]);
				printf(",");
			}
			for(j = 0; i < strlen(dollar);)
			{
				if(j == 3)
				{
					printf(",");
					j = 0;
				}
				else
				{
					printf("%c", dollar[i]);
					i++;
					j++;
				}
			}
			printf(".");
			if(strlen(cents) == 1)
				printf("0%c", cents[0]);
			else
				printf("%c%c", cents[0], cents[1]);
		}
		printf("\n");
		c = getchar();
	}
	return 0;
}