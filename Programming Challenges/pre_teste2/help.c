#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

int main(void)
{
	int N, T, i, tempo[26], count, total_time;
	/*bool valido[26];*/
	char c, c2;
	scanf("%d", &N);
	scanf("\n");
	/*printf("%d", 'A');*/
	while(N != 0)
	{
		for(i = 0; i < 26; i++)
		{
			tempo[i] = 0;
		}
		count = 0;
		total_time = 0;
		for(i = 0; i < N; i++)
		{
			c = getchar();
			scanf("%d", &T);
			c2 = getchar();
			while(c2 == ' ')
				c2 = getchar();
			if(c2 == 'i' || c2 == 'I')
			{
				tempo[c-65] = tempo[c-65] + 20;
			}
			else
			{
				tempo[c-65] = tempo[c-65] + T;	
				total_time = total_time + tempo[c-65];
				count++;
			}
			c2 = getchar();
			while(c2 != '\n')
				c2 = getchar();
			scanf("\n");
		}
		printf("%d %d\n", count, total_time);
		/*for(i = 0; i < count; i++)
		{
			for(j = 0; j < 26; j++)
			{
				if(valido[j])
				{
					total_time = total_time + tempo[j];
					valido[j] = false;
					j = 27;
				}
			}
		}*/
		scanf("%d", &N);
		scanf("\n");
	}
	return 0;
}