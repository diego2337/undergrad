#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

int main(void)
{
	char tag[11], line[51], aux[51], numero[5], c;
	int i, j, k;
	bool tegui = false;
	c = getchar();
	while(c != EOF)
	{
		tegui = false;
		for(i = 0; i < 11; i++)
			tag[i] = 0;
		for(i = 0; i < 51; i++)
		{
			line[i] = 0;
		}
		for(i = 0; i < 5; i++)
			numero[i] = 0;
		/* Read the original tag */
		i = 0;
		while(c != '\n')
		{
			tag[i] = c;
			i++;
			c = getchar();
		}
		c = getchar();
		/* Read the replacement */
		i = 0;
		while(c != '\n')
		{
			numero[i] = c;
			i++;
			c = getchar();
		}
		/*for(i = 0; i < strlen(numero); i++)
			printf("NUMERO HOMBRE %c\n", numero[i]);*/
		/* Read the line */
		i = 0;
		j = 0;
		c = getchar();
		while(c != '\n')
		{
			for(j = 0; j < 51; j++)
				aux[j] = 0;
			j = 0;
			line[i] = c;
			if(line[i] == '<')
				tegui = true;
			else if(line[i] == '>')
				tegui = false;
			else if(tolower(line[i]) == tolower(tag[j]) && tegui)
			{
				k = 0;
				aux[k] = line[i];
				/*k++;
				j++;
				c = getchar();
				aux[k] = c;*/
				while(tolower(aux[k]) == tolower(tag[j]) && j < strlen(tag))
				{
					k++;
					j++;
					c = getchar();
					aux[k] = c;
				}
				if(j == strlen(tag))
				{
					j = 0;
					k = i;
					ungetc(c, stdin);
					while(k < (i+strlen(numero)))
					{
						line[k] = numero[j];
						k++;
						j++;
					}
					i = k-1;
				}
				else
				{
					for(j = 0; j < strlen(aux); j++)
					{
						line[i] = aux[j];
						i++;
					}
					i--;
				}
			}
			i++;
			c = getchar();
		}
		c = getchar();
		for(i = 0; i < strlen(line); i++)
		{
			printf("%c", line[i]);
		}
		printf("\n");
	}
	return 0;
}