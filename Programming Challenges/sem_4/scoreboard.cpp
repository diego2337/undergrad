#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
	int problems[10];
	bool solved[10];
}time;

bool get_score(int judges[10][101])
{
	char aux;
	int i = 0, team = 0, chronos = 0, problem = 0;
	aux = getchar();
	if(aux != '\n')
	{
		while(aux != ' ')
		{
			team = atoi(&aux) + (team * pow(10, i));
			aux = getchar();
			i++;
		}
		aux = getchar();
		problem = atoi(&aux);
		aux = getchar();
		aux = getchar();
		i = 0;
		while(aux != ' ')
		{
			chronos = atoi(&aux) + (chronos * pow(10, i));
			aux = getchar();
			i++;
		}
		aux = getchar();
		printf("team: %d problem: %d chronos: %d result: %c\n", team, problem, chronos, aux);
		/* '\n' */
		aux = getchar();
		return true;
	}
	else
	{
		return false;
	}
}

int main(void)
{
	int test_cases;

	char aux2;
	string aux;
	aux2 = getchar();
	test_cases = atoi(&aux2);
	aux2 = getchar();
	for(int i = 0; i < test_cases; i++)
	{
		aux2 = getchar();
		while(get_score(judges));
	}
	return 0;
}