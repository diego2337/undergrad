#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lcs(char string1[51], char string2[51])
{
	int m = strlen(string1);
	int n = strlen(string2);
	int max = 0, max_i = 0, max_j = 0;
	int c[52][52], i, j;
	for(j = 0; j <= m; j++)
	{
		c[0][j] = 0;
	}
	for(j = 0; j <= n; j++)
		c[j][0] = 0;
	for(i = 1; i <= m; i++)
	{
		for(j = 1; j <= n; j++)
		{
			if(string1[i-1] == string2[j-1])
				c[i][j] = c[i-1][j-1]+1;
			else if(c[i-1][j] >= c[i][j-1])
				c[i][j] = c[i-1][j];
			else
				c[i][j] = c[i][j-1];
			if(c[i][j] > max)
			{
				max = c[i][j];
				max_i = i;
				max_j = j;
			}
		}
	}
	return c[max_i][max_j];
}

int main(void)
{
	char string1[51], string2[51], c;
	int i;
	c = getchar();
	while(c != EOF)
	{
		for(i = 0; i < 51; i++)
		{
			string1[i]=0;
			string2[i]=0;
		}
		i = 0;
		string1[i] = c;
		c = getchar();
		i++;
		while(c != '\n')
		{
			string1[i] = c;
			i++;
			c = getchar();
		}
		string1[i] = '\0';
		c = getchar();
		i = 0;
		while(c != '\n')
		{
			string2[i] = c;
			i++;
			c = getchar();
		}
		string2[i] = '\0';
		printf("%d", lcs(string1, string2));
		printf("\n");
		c = getchar();
	}
	return 0;
}