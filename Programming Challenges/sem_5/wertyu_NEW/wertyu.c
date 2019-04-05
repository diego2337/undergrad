#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char keyboard[5][13] = {'`', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=',
						'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', '[', ']', '\\',
						'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', ';', '\'', '!', '!',
						'Z', 'X', 'C', 'V', 'B', 'N', 'M', ',', '.', '/', '!', '!', '!'};

char decode(char c)
{
	int i, j;
	if(c == ' ')
		return c;
	else
	{
		for(i = 0; i < 5; i++)
		{
			for(j = 0; j < 13; j++)
			{
				if(islower(c))
				{
					if(toupper(c) == keyboard[i][j])
					{
						return tolower(keyboard[i][j]);
					}
				}
				else
				{
					if(c == keyboard[i][j])
					{
						if(j == 0)
							return keyboard[i][j];
						else
							return keyboard[i][j-1];
					}
				}
			}
		}
	}
}

int main(void)
{
	char c;
	while((c = getchar()) != EOF)
	{
		if(c == '\n')
			printf("\n");
		else
			printf("%c", decode(c));
	}
	printf("\n");
	return 0;
}