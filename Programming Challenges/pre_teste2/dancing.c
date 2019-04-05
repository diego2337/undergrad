#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

int main(void)
{
	char c;
	bool upper = true;
	c = getchar();
	while(c != EOF)
	{
		if(upper)
		{
			while(c == ' ')
			{
				printf(" ");
				c = getchar();
			}
			if(c == '\n')
			{
				printf("\n");
				upper = true;
			}
			else
			{
				printf("%c", toupper(c));
				upper = false;
			}
		}
		else 
		{
			while(c == ' ')
			{
				printf(" ");
				c = getchar();
			}
			if(c == '\n')
			{
				printf("\n");
				upper = true;
			}
			else
			{
				printf("%c", tolower(c));
				upper = true;	
			}
		}
		c = getchar();
	}
	return 0;
}