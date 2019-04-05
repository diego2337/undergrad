#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

void fill(bool horizon, char *n, int blank_columns, int lines, float blank_lines)
{
	int i, j, k;
	if(horizon)
	{
		for(i = 0; i < strlen(n); i++)
		{
			switch(n[i])
			{
				case '1':
					printf(" ");
					for(j = 0; j < blank_columns; j++)
						printf(" ");
					printf(" ");
					break;
				case '4':
					if(lines < ceil(blank_lines/2) || lines == blank_lines)
					{
						printf(" ");
						for(j = 0; j < blank_columns; j++)
							printf(" ");
						printf(" ");
					}
					else
					{
						printf(" ");
						for(j = 0; j < blank_columns; j++)
							printf("-");
						printf(" ");	
					}
					break;
				case '7':
					if(lines == 1)
					{
						printf(" ");
						for(j = 0; j < blank_columns; j++)
							printf("-");
						printf(" ");	
					}
					else
					{
						printf(" ");
						for(j = 0; j < blank_columns; j++)
							printf(" ");
						printf(" ");
					}
					break;
				case '0':
					if(lines == ceil(blank_lines/2))
					{
						printf(" ");
						for(j = 0; j < blank_columns; j++)
							printf(" ");
						printf(" ");
					}
					else
					{
						printf(" ");
						for(j = 0; j < blank_columns; j++)
							printf("-");
						printf(" ");
					}
					break;
				default:
					printf(" ");
					for(j = 0; j < blank_columns; j++)
						printf("-");
					printf(" ");
					break;
			}
			if(i != strlen(n)-1)
				printf(" ");
		}	
	}
	else
	{
		for(i = 0; i < strlen(n); i++)
		{
			switch(n[i])
			{
				case '1':
					printf(" ");
					for(j = 0; j < blank_columns; j++)
						printf(" ");
					printf("|");
					break;
				case '2':
					if(lines < ceil(blank_lines/2))
					{
						for(j = 0; j < blank_columns; j++)
							printf(" ");
						printf(" ");
						printf("|");
					}
					else
					{
						printf("|");
						for(j = 0; j < blank_columns; j++)
							printf(" ");
						printf(" ");
					}
					break;
				case '3':
					for(j = 0; j < blank_columns; j++)
						printf(" ");
					printf(" ");
					printf("|");
					break;
				case '4':
					if(lines < ceil(blank_lines/2))
					{
						printf("|");
						for(j = 0; j < blank_columns; j++)
							printf(" ");
						printf("|");
					}
					else
					{
						for(j = 0; j < blank_columns; j++)
							printf(" ");
						printf(" ");
						printf("|");
					}
					break;
				case '5':
					if(lines < ceil(blank_lines/2))
					{
						printf("|");
						for(j = 0; j < blank_columns; j++)
							printf(" ");
						printf(" ");
					}
					else
					{
						for(j = 0; j < blank_columns; j++)
							printf(" ");
						printf(" ");
						printf("|");
					}
					break;
				case '6':
					if(lines < ceil(blank_lines/2))
					{
						printf("|");
						for(j = 0; j < blank_columns; j++)
							printf(" ");
						printf(" ");
					}
					else
					{
						printf("|");
						for(j = 0; j < blank_columns; j++)
							printf(" ");
						printf("|");
					}
					break;
				case '7':
				printf(" ");
					for(j = 0; j < blank_columns; j++)
						printf(" ");
					printf("|");
					break;
				case '8':
					printf("|");
					for(j = 0; j < blank_columns; j++)
						printf(" ");
					printf("|");
					break;
				case '9':
					if(lines < ceil(blank_lines/2))
					{
						printf("|");
						for(j = 0; j < blank_columns; j++)
							printf(" ");
						printf("|");
					}
					else
					{
						for(j = 0; j < blank_columns; j++)
							printf(" ");
						printf(" ");
						printf("|");	
					}
					break;
				case '0':
					printf("|");
					for(j = 0; j < blank_columns; j++)
						printf(" ");
					printf("|");
					break;
			}
			if(i != strlen(n)-1)
				printf(" ");
		}
	}
}

void display(int s, char *n)
{
	int i, j, blank_columns, lines = 1;
	float blank_lines;
	bool horizon = true;
	blank_columns = (s + 2) -1;
	blank_lines = 2*s + 3;
	for(i = 0; i < blank_lines; i++)
	{
		/* Preenche horizontalmente */
		if(lines == 1 || lines == ceil(blank_lines/2) || lines == blank_lines)
		{
			horizon = true;
			fill(horizon, n, blank_columns-1, lines, blank_lines);
		}
		else
		{
			horizon = false;
			fill(horizon, n, blank_columns-1, lines, blank_lines);
		}
		printf("\n");
		lines++;
	}

}

int main(void)
{
	int s, i, j, blank_columns;
	char n[9];
	scanf("%d %s", &s, n);
	while(s != 0 || atoi(n) != 0)
	{
		display(s, n);
		printf("\n");
		scanf("%d %s", &s, n);
	}
	return 0;
}