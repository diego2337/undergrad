#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char min(char common_a[], char common_b[], int j)
{
	common_a[j] = common_a[j] - 1;
	common_b[j] = common_b[j] - 1;
	return j+97;
}

int main(void)
{
	int i, j, max;
	char c, common_a[27], common_b[27];
	c = getchar();
	while(c != EOF)
	{
		for(i = 0; i < 27; i++)
		{
			common_a[i] = 0;
			common_b[i] = 0;
		}
		max = 0;
		while(c != '\n')
		{
			if(isalpha(c))
			{
				common_a[tolower(c)-97] = common_a[tolower(c)-97] + 1;
				if(common_a[tolower(c)-97] > max)
					max = common_a[tolower(c)-97];
			}
			c = getchar();
		}
		c = getchar();
		while(c != '\n')
		{
			if(isalpha(c))
			{
				common_b[tolower(c)-97] = common_b[tolower(c)-97] + 1;
				if(common_b[tolower(c)-97] > max)
					max = common_b[tolower(c)-97];
			}
			c = getchar();
		}
		for(j = 0; j < 27; j++)
		{
			while(common_a[j] != 0 && common_b[j] != 0)
			{
				printf("%c", min(common_a, common_b, j));
			}
		}
		printf("\n");
		c = getchar();
	}
	return 0;
}