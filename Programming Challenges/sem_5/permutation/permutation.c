#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void find_common(char a[], char b[], char common[])
{
	int i, j, k = 0;
	/* Se sim, iterar por a*/
	if(strlen(a) < strlen(b))
	{
		for(i = 0; i < strlen(a); i++)
		{
			for(j = 0; j < strlen(b); j++)
			{
				if(a[i] == b[j])
				{
					common[k] = a[i];
					k++;
					b[j] = '!';
					j = strlen(b) + 10;
				}
			}
		}
	}
	else
	{
		for(i = 0; i < strlen(b); i++)
		{
			for(j = 0; j < strlen(a); j++)
			{
				if(a[j] == b[i])
				{
					common[k] = a[j];
					k++;
					a[j] = '!';
					j = strlen(a) + 10;
				}	
			}	
		}
	}
}

int main(void)
{
	int i, j, min, min_value;
	char a[10001], b[10001], c, common[10001];
	while((c = getchar()) != EOF)
	{
		for(i = 0; i < 10001; i++)
		{
			a[i] = 0;
			b[i] = 0;
			common[i] = 0;
		}
		i = 0;
		a[i] = c;
		i++;
		while((c = getchar()) != '\n')
		{
			a[i] = c;
			i++;
		}
		i = 0;
		while((c = getchar()) != '\n')
		{
			b[i] = c;
			i++;
		}
		find_common(a, b, common);
		min = 1000;
		min_value = 1000;
		for(j = 0; j < strlen(common); j++)
		{
			for(i = 0; i < strlen(common); i++)
			{
				if(common[i] < min_value && common[i] != '}')
				{
					min = i;
					min_value = common[i];
				}
			}
			printf("%c", common[min]);
			common[min] = '}';
			min = 1000;
			min_value = 1000;
		}
		printf("\n");
	}
	return 0;
}