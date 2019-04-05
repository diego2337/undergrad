#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
	int J, i, k, max, min, score[13], final_result[310];
	char c, players[310][310], players_last_name[310][310];
	scanf("%d", &J);
	while(J != 0)
	{
		c = getchar();
		max = 0;
		min = 10000000;
		for(i = 0; i < J; i++)
		{
			k = 0;
			while(c != ' ')
			{
				players[i][k] = c;
				k++;
				c = getchar();
			}
			c = getchar();
			k = 0;
			while(c != '\n')
			{
				players_last_name[i][k] = c;
				k++;
				c = getchar();
			}
			for(k = 0; k < 12; k++)
			{
				scanf("%d", &score[k]);
				if(score[k] > max)
					max = score[k];
				if(score[k] < min)
					min = score[k];
			}
			for(k = 0; k < 12; k++)
			{
				if(score[k] != min || score[k] != max)
				{
					final_result[i] = final_result[i] + score[k];
				}
			}
					
		}
		scanf("%d", &J);
	}
	return 0;
}