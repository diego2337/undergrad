#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

int main(void)
{
	bool isWord;
	char c, hidden_msg[51];
	int n, i, j;
	scanf("%d", &n);
	scanf("\n");
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < 51; j++)
			hidden_msg[j] = 0;
		isWord = false;
		j = 0;
		c = getchar();
		while(c != '\n')
		{
			if(!isWord)
			{
				while(c == ' ')
					c = getchar();
				if(c != '\n')
				{
					hidden_msg[j] = c;
					j++;
					isWord = true;
					c = getchar();
				}
			}
			else
			{
				while(isalpha(c))
					c = getchar();
				isWord = false;
			}
		}
		for(j = 0; j < strlen(hidden_msg); j++)
			printf("%c", hidden_msg[j]);
		printf("\n");
	}
	return 0;
}