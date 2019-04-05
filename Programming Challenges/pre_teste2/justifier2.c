#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int N, i, j, max_strlen;
	char text[151][61], c;
	scanf("%d", &N);
	scanf("\n");
	while(N != 0)
	{
		for(i = 0; i < 151; i++)
		{
			for(j = 0; j < 61; j++)
				text[i][j] = 0;
		}
		for(i = 0; i < N; i++)
		{
			c = getchar();
			for(j = 0; j < 51; j++)
			{
				if(j == 0)
				{
					while(c == ' ')
					{
						c = getchar();
					}
					text[i][j] = c;
					c = getchar();
				}
				else
				{
					if(c == ' ')
					{
						text[i][j] = c;
						while(c == ' ')
						{
							c = getchar();
						}
						if(c == '\n')
							text[i][j] = 0;
					}	
					else if(c == '\n')
						j = 51 + 10;
					else
					{
						text[i][j] = c;
						c = getchar();
					}
				}
			}
		}
		/*for(i = 0; i < N; i++)
		{
			for(j = 0; j < strlen(text[i]); j++)
			{
				printf("%c", text[i][j]);
			}
			printf("\n");
		}*/
		max_strlen = 0;
		for(i = 0; i < N; i++)
		{
			if(max_strlen < strlen(text[i]))
				max_strlen = strlen(text[i]);
		}
		/*printf("max_strlen: %d\n", max_strlen);*/
		for(i = 0; i < N; i++)
		{
			for(j = 0; j < max_strlen-strlen(text[i]); j++)
			{
				printf(" ");
			}
			for(j = 0; j < strlen(text[i]); j++)
				printf("%c", text[i][j]);
			printf("\n");
		}
		scanf("%d", &N);
		scanf("\n");
		if(N != 0)
			printf("\n");
	}
	return 0;
}