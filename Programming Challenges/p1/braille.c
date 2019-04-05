#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int i, j, D, aux;
	char c, sequence[3][400];
	while(scanf("%d", &D) != 0)
	{
		c = getchar();
		for(i=0;i<3;i++)
		{
			for(j=0;j<400;j++)
				sequence[i][j] = 0;
		}
		c = getchar();
		/* \n */
		c = getchar();
		c = getchar();
		if(c == 'S' || c == 's')
		{
			while(c != '\n')
			{
				sequence[0][i] = c;
				c = getchar();
			}
		}
		else if(c == 'B' || c == 'b')
		{
			aux = D-1;
			D = D*2 + aux;
			for(i = 0; i < 3; i++)
			{
				while(c != '\n')
				{
					sequence[i][j] = c;
					c = getchar();
				}
				c = getchar();
			}
		}
		for(i = 0; i < 3; i++)
		{
			for(j = 0; j < D; j++)
				printf("%c", sequence[i][j]);
			printf("\n");
		}
	}
	return 0;
}