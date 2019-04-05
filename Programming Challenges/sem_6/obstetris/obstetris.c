#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct 
{
	int score;
	char nome[310];
	char sobrenome[310];
} tetris;

int compare_str (const void * a, const void * b)
{
	tetris aux = *(tetris *) a;
	tetris aux2 = *(tetris *) b;

	if (aux.score != aux2.score) return aux2.score - aux.score;
	if (strcmp (aux.nome, aux2.nome) != 0) return strcmp (aux.nome, aux2.nome);
	return strcmp( aux.sobrenome, aux2.sobrenome );
} 



int main(void)
{
	int J, i, j, k, tests = 1, max, min, aux, fake_score, first = 0;
	tetris players[310];
	char c;
	scanf("%d", &J);
	c = getchar();
	while(J != 0)
	{
		for(i = 0; i < J; i++)
		{
			players[i].score = 0;
			players[i].nome[0] = '\0';
			players[i].sobrenome[0] = '\0';
		}
		first = 1;
		for(i = 0; i < J; i++)
		{
			k = 0;
			max = 0;
			min = 10000000;
			while(!isalpha(c))
				c = getchar();
			while(c != ' ' && c != EOF && !isdigit(c))
			{
				players[i].nome[k] = c;
				k++;
				c = getchar();
			}
			players[i].nome[k] = '\0';
			c = getchar();
			k = 0;
			while(c != '\n' && c != EOF && !isdigit(c))
			{
				players[i].sobrenome[k] = c;
				k++;
				c = getchar();
			}
			players[i].sobrenome[k] = '\0';
			for(k = 0; k < 12; k++)
			{
				scanf("%d", &aux);
				if(aux > max)
					max = aux;
				if(aux < min)
					min = aux;
				players[i].score = players[i].score + aux;
			}	
			players[i].score = players[i].score - max - min;
		}
		qsort(players, J, sizeof(tetris), compare_str);
		k = 0;
		j = 1;
		fake_score = -1;
		printf("Teste %d\n", tests);
		for(i = 0; i < J; i++, j++)
		{
			if(players[i].score == fake_score)
			{
				if(first)
				{
					k--;
					first = 0;
				}
				printf("%d %d %s\n", k, players[i].score, players[i].nome);
			}
			else
			{
				k = j;
				printf("%d %d %s\n", k, players[i].score, players[i].nome);
				k++;
				first = 1;
			}
			fake_score = players[i].score;
		}
		printf("\n");
		scanf("%d", &J);
		c = getchar();
		tests++;
	}
	return 0;
}