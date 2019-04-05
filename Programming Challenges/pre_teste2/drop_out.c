#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

int main(void)
{
	int N, i, j, j2, k, active, cards[53], min = 1000000, min_index[21], dropouts;
	bool out[21] = {false};
	char players[21][20], c;
	scanf("%d", &N);
	scanf("\n");
	while(N != 0)
	{
		for(i = 0; i < 21; i++)
		{
			for(j = 0; j < 20; j++)
				players[i][j] = 0;
		}
		c = getchar();
		i = 0;
		for(i = 0; i < N; i++)
		{
			j = 0;
			while(c == ' ')
			{
				c = getchar();
			}
			players[i][j] = c;
			j++;
			while(c != ' ' && c != '\n')
			{
				printf("%c\n", c);
				players[i][j] = c;
				j++;
				c = getchar();
			}
			c = getchar();
		}
		/*for(i = 0; i < N; i++)
		{
			for(j = 0; j < strlen(players[i])-1; j++)
			{
				printf("%c", players[i][j]);
			}
			printf("\n");
		}*/
		/* Read cards */
		for(i = 0; i < 52; i++)
		{
			scanf("%d", &cards[i]);
		}
		active = N;
		i = 0;
		while(active != 0)
		{
			for(j = 0; j < 21; j++)
			{
				if(out[j])
					break;
			}
			memset(min_index, 0, 21);
			min = 1000000;
			dropouts = 1;
			k = 0;
			for(j2 = j; j2 < active+j; j2++)
			{
				if(cards[i] < min)
				{
					min = cards[i];
					min_index[k] = j2;
					k++;
				}
				else if(cards[i] == min)
				{
					dropouts++;
					min_index[k] = j2;
					k++;
				}
				i++;
			}
			if(dropouts != active)
			{
				for(k = 0; k < dropouts; k++)
				{
					out[min_index[k]] = true;
				}
			}
			active = active - dropouts;
		}
		for(i = 0; i < 21; i++)
		{
			if(out[i])
			{
				for(j = 0; j < strlen(players[i])-1; j++)
					printf("%c", players[i][j]);
			}
		}
		scanf("%d", &N);
		scanf("\n");
	}
	return 0;
}