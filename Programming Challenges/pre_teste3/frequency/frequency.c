#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
	int character, frequencies;
}freq;

int compare(const void * a, const void * b)
{
	freq aux = *(freq*)a;
	freq aux2 = *(freq*)b;
	if(aux.frequencies == aux2.frequencies)
	{
		return aux2.character-aux.character; 
	}
	return aux.frequencies - aux2.frequencies;
}

int main(void)
{
	freq frequencias[97], aux[97];
	int i, j, k, min, max;
	char c;
	c = getchar();
	while(c != EOF)
	{
		max = 0;
		min = 97;
		for(i = 0; i < 97; i++)
		{
			frequencias[i].frequencies = 0;
		}
		i = 0;
		while(c != '\n' && c != '\r' && c != EOF)
		{
			frequencias[c-32].character = c;
			frequencias[c-32].frequencies = frequencias[c-32].frequencies + 1;
			i++;
			if(c-32 > max)
				max = c-32;
			if(c-32 < min)
				min = c-32;
			c = getchar();
		}
		for(j = min, k = 0; j <= max; j++, k++)
		{
			aux[k].character = frequencias[j].character;
			aux[k].frequencies = frequencias[j].frequencies;
		}
		qsort(aux, k, sizeof(freq), compare);
		for(j = 0; j < k; j++)
		{
			if(aux[j].frequencies != 0)
			{
				printf("%d %d", aux[j].character, aux[j].frequencies);
				printf("\n");
			}
			frequencias[j].frequencies = 0;
		}
		c = getchar();
		if(c != EOF)
			printf("\n");
	}
	return 0;
}