#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

typedef struct 
{
	char name[999];
	char sobrenome[999];
	char color[999];
	char size;
}student;

int compare(const void * a, const void * b)
{
	student aux = *(student*)a;
	student aux2 = *(student*)b;
	if(strcmp(aux.color, aux2.color) != 0)
		return strcmp(aux.color, aux2.color);
	if(aux.size != aux2.size)
		return aux2.size-aux.size;
	return strcmp(aux.name, aux2.name);
}

int main(void)
{
	student estudante[160];
	int n, i, j;
	char c;
	scanf("%d", &n);
	c = getchar();
	c = getchar();
	while(n != 0)
	{
		for(i = 0; i < n; i++)
		{
			j = 0;
			while(c != '\n' && c != EOF)
			{
				estudante[i].name[j] = c;
				j++;
				c = getchar();
			}
			estudante[i].name[j] = '\0';
			c = getchar();
			j = 0;
			while(c != ' ' && c != EOF)
			{
				estudante[i].color[j] = c;
				j++;
				c = getchar();
			}
			estudante[i].color[j] = '\0';
			c = getchar();
			estudante[i].size = c;
			c = getchar();
			c = getchar();
		}
		/*for(i = 0; i < n; i++)
		{
			printf("Nome: %s\tcor: %s\ttamanho: %c\n", estudante[i].name, estudante[i].color, estudante[i].size);
		}*/
		qsort(estudante, n, sizeof(student), compare);
		for(i = 0; i < n; i++)
		{
			printf("%s %c %s\n", estudante[i].color, estudante[i].size, estudante[i].name);
		}
		j = 0;
		n = 0;
		while(isdigit(c))
		{
			n = n*pow(10, j) + atoi(&c);
			j++;
			c = getchar();
		}
		if(n != 0)
			printf("\n");
		c = getchar();
	}
	return 0;
}