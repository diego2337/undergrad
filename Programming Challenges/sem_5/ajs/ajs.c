#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

int x = 1;

void judge(int n, int m, char answers[500][500], char inputs[500][500])
{
	int i, j, k, l;
	bool presentation_error = true, accepted = true;
	for(i = 0, k = 0; i < n && k < n; i++, k++)
	{
		for(j = 0, l = 0; j < strlen(answers[i]) || l < strlen(inputs[k]); j++, l++)
		{
			/*printf("answer: %c input: %c\n", answers[i][j], inputs[k][l]);*/
			if(answers[i][j] != inputs[k][l])
			{
				accepted = false;
				if(isdigit(answers[i][j]))
				{
					if(inputs[k][l] != ' ')
					{
						printf("Run #%d: Wrong Answer\n", x);
						presentation_error = false;
						j = strlen(answers[i]) + 10;
						l = strlen(inputs[k]) + 10;
						i = n + 10;
					}
					else
					{
						while(inputs[k][l] == ' ')
						{
							l++;
						}
						if(inputs[k][l] == answers[i][j])
						{
						}
						else
						{
							printf("Run #%d: Wrong Answer\n", x);
							presentation_error = false;
							j = strlen(answers[i]) + 10;
							l = strlen(inputs[k]) + 10;
							i = n + 10;
						}		
					}
				}
				else if(isdigit(inputs[k][l]))
				{
					if(answers[i][j] != ' ')
					{
						printf("Run #%d: Wrong Answer\n", x);
						presentation_error = false;
						j = strlen(answers[i]) + 10;
						l = strlen(inputs[k]) + 10;
						i = n + 10;
					}
					else
					{
						while(answers[i][j] == ' ')
						{
							j++;
						}
						if(answers[i][j] == inputs[k][l])
						{
						}
						else
						{
							printf("Run #%d: Wrong Answer\n", x);
							presentation_error = false;
							j = strlen(answers[i]) + 10;
							l = strlen(inputs[k]) + 10;
							i = n + 10;
						}		
					}
				}
				else
				{
					j = strlen(answers[i]) + 10;
					l = strlen(inputs[k]) + 10;
					i = n + 10;		
				}
			}
		}
	}
	if(!accepted && presentation_error)
		printf("Run #%d: Presentation Error\n", x);
	else if(accepted)
		printf("Run #%d: Accepted\n", x);
}

int main(void)
{
	int n, m, i, j;
	char answers[500][500], inputs[500][500], c;
	c = getchar();
	n = atoi(&c);
	c = getchar();
	while(n != 0)
	{
		for(i = 0; i < 500; i++)
		{
			for(j = 0; j < 500; j++)
			{
				answers[i][j] = 0;
				inputs[i][j] = 0;
			}
		}
		for(i = 0; i < n; i++)
		{
			for(j = 0; (c = getchar()) != '\n'; j++)
			{
				answers[i][j] = c;
			}
		}
		answers[i][j] = '\0';
		c = getchar();
		m = atoi(&c);
		c = getchar();
		for(i = 0; i < m; i++)
		{
			for(j = 0; (c = getchar()) != '\n'; j++)
			{
				inputs[i][j] = c;
			}
		}
		inputs[i][j] = '\0';
		/*for(i = 0; i < n; i++)
		{
			for(j = 0; j < strlen(answers[i]); j++)
				printf("%c", answers[i][j]);
			printf("\n");
		}
		for(i = 0; i < n; i++)
		{
			for(j = 0; j < strlen(inputs[i]); j++)
				printf("%c", inputs[i][j]);
			printf("\n");
		}*/
		if(n != m)
			printf("Run #%d: Presentation Error\n", x);
		else
			judge(n, m, answers, inputs);
		x = x + 1;
		c = getchar();
		n = atoi(&c);
		if(n != 0)
			c = getchar();
	}
	return 0;
}