#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
	char str[101];
	int str_size;
} str_struct;

int compare(const void * a, const void * b)
{
	str_struct aux = *(str_struct*)a;
	str_struct aux2 = *(str_struct*)b;
	return aux2.str_size-aux.str_size;
}

int main(void)
{
	str_struct constituo[101];
	char c;
	int N, i, j, k;
	scanf("%d", &N);
	c = getchar();
	c = getchar();
	for(i = 0; i < N; i++)
	{
		j = 0;
		while(c != '\n' && c != EOF)
		{
			k = 0;
			while(c != ' ' && c != '\n' && c != EOF)
			{
				constituo[j].str[k] = c;
				k++;
				c = getchar();
			}
			constituo[j].str[k] = '\0';
			constituo[j].str_size = strlen(constituo[j].str);
			j++;
			if(c != '\n')
				c = getchar();
		}
		qsort(constituo, j, sizeof(str_struct), compare);
		for(k = 0; k < j; k++)
		{
			if(k != 0)
				printf(" ");
			printf("%s", constituo[k].str);
		}
		printf("\n");
		c = getchar();
	}
	return 0;
}