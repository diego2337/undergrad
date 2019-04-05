#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

int main(void)
{
	bool error = true;
	char str[61], c;
	int i, j, k, value;
	c = getchar();
	while(c != EOF)
	{
		error = true;
		for(i = 0; i < 61; i++)
			str[i] = 0;
		i = 0;
		while(c != '\n')
		{
			while(!isdigit(c) && (c != 'l' && c != 'O' && c != 'o') && c != '\n')
			{
				c = getchar();
			}
			if(c != '\n')
			{
				if(c == 'l')
				{
					str[i] = '1';
					error = false;
				}
				else if(c == 'O' || c == 'o')
				{
					str[i] = '0';
					error = false;
				}
				else if(isdigit(c))
				{
					str[i] = c;
					error = false;
				}
				i++;
				c = getchar();
			}
		}
		value = 0;
		k = 0;
		while(str[k] == '0')
			k++;
		if(strlen(str)-k > 10)
			error = true;
		if(strlen(str)-k == 10 && (str[k] > '2' || str[k+1] > '1' || str[k+2] > '4' || str[k+3] > '7' || str[k+4] > '4' 
			|| str[k+5] > '8' || str[k+6] > '3' || str[k+7] > '6' || str[k+8] > '4' || str[k+9] > '7'))
			error = true;
		else
		{
			for(i = strlen(str)-1, j = 1; i >= 0; i--, j = j * 10)
			{
				c = str[i];
				value = value + (atoi(&c) * j);
				if(value < 0)
				{
					error = true;
					i = -1;
				}
			}
		}
		if(error)
			printf("error");
		else
		{
			printf("%d", value);
		}
		printf("\n");
		c = getchar();
	}
	return 0;
}