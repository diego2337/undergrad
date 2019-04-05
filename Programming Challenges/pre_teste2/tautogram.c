#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

int main(void)
{	
	char letter, c;
	bool tautogram;
	c = getchar();
	while(c != '*')
	{
		tautogram = true;
		letter = tolower(c);
		while(c != '\n')
		{
			c = getchar();
			while(c != ' ' && c != '\n')
			{
				c = getchar();
			}
			if(c == ' ')
				c = getchar();
			if(c != '\n' && letter != tolower(c))
				tautogram = false;
		}
		if(tautogram)
			printf("Y\n");
		else
			printf("N\n");
		c = getchar();
	}
	return 0;
}