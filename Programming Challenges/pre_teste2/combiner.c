#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

int main(void)
{
	int test_cases, i, j, k;
	bool first = true;
	char string1[51], string2[51], c;
	scanf("%d", &test_cases);
	scanf("\n");
	c = getchar();
	for(i = 0; i < test_cases; i++)
	{
		for(j = 0; j < 51; j++)
		{
			string1[j] = 0;
			string2[j] = 0;
		}
		j = 0;
		while(c != ' ')
		{
			string1[j] = c;
			j++;
			c = getchar();
		}
		while(c == ' ')
			c = getchar();
		j = 0;
		while(c != '\n')
		{
			string2[j] = c;
			j++;
			c = getchar();
		}
		/*for(j = 0; j < strlen(string1); j++)
		{
			printf("%c", string2[j]);
		}
		printf("\n");*/
		first = true;
		for(j = 0, k = 0; j < (strlen(string1)) || k < (strlen(string2));)
		{
			if(first)
			{
				if(j >= strlen(string1))
					first = false;
				else
				{
					printf("%c", string1[j]);
					j++;
					first = false;
				}
			}
			else if(!first)
			{
				if(k >= strlen(string2))
					first = true;
				else
				{
					printf("%c", string2[k]);
					k++;
					first = true;
				}
			}
		}
		printf("\n");
		c = getchar();
	}
	return 0;
}