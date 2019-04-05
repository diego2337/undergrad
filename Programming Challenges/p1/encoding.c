#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(void)
{
	char sequence[1000000], c;
	int i, j, k, count;
	bool seq = false;
	c = getchar();
	while(c != EOF)
	{
		i = 0;
		j = 0;
		count = 1;
		seq = false;
		while(c != '\n')
		{
			sequence[i] = c;
			if(count == 9)
			{
				printf("%d%c", count, sequence[i-1]);
				count = 1;
				j = i;		
			}
			else if(i > 0 && sequence[i-1] == sequence[i])
			{
				if(seq)
				{
					printf("1");
					for(k = j; k < i-1; k++)
					{
						if(sequence[k] == '1')
							printf("1");
						printf("%c", sequence[k]);
					}
					printf("1");
					j = i-1;
					seq = false;
				}
				count++;
			}
			else if(i > 0 && count > 1 && sequence[i-1] != sequence[i])
			{
				printf("%d%c", count, sequence[i-1]);
				count = 1;
				j = i;
			}
			else if(i > 0 && count == 1 && sequence[i-1] != sequence[i])
			{
				seq = true;
				/* Do nothing */
			}
			i++;
			c = getchar();
			if(c == '\n')
			{
				if(i > 0 && count == 1 && sequence[i-1] != sequence[i])
				{
					printf("1");
					for(k = j; k < i; k++)
					{
						if(sequence[k] == '1')
							printf("1");
						printf("%c", sequence[k]);
					}
					printf("1");
					j = i-1;
				}
				else if(i > 0 && count > 1)
				{
					printf("%d%c", count, sequence[i-1]);
					count = 1;
					j = i;		
				}
				printf("\n");
			}
		}
		c = getchar();
	}
	return 0;
}