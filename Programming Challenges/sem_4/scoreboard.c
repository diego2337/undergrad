#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
	int problems[10];
	bool solved[10];
	int count;
	int penalty_time;
}score;

bool teams[101] = {false};

void init(score *judges)
{
	int i, j;
	for(i = 0; i < 101; i++)
	{
		judges[i].count = 0;
		judges[i].penalty_time = 0;
		for(j = 0; j < 10; j++)
			judges[i].problems[j] = 0;
		for(j = 0; j < 10; j++)
			judges[i].solved[j] = false;
	}
}

void print_scores(score judges[101], int n_teams)
{
	int i, j, k, max_count, max_index;
	for(i = 0; i < 101; i++)
	{
		if(judges[i].count != 0)
		{
			for(j = 0; j < 10; j++)
			{
				if(judges[i].solved[j])
				{
					judges[i].penalty_time += judges[i].problems[j];
				}
			}
		}
	}
	while(n_teams != 0)
	{
		max_count = 0;
		max_index = 0;
		for(i = 0; i < 101; i++)
		{
			if(judges[i].count != 0)
			{
				if(judges[i].count > max_count)
				{
					max_count = judges[i].count;
					max_index = i;
				}
				else if(judges[i].count == max_count)
				{
					if(judges[i].penalty_time < judges[max_index].penalty_time)
					{
						max_count = judges[i].count;
						max_index = i;
					}
				}
				/*printf("i: %d count: %d penalty_time: %d\n", i, judges[i].count, judges[i].penalty_time);*/
			}
		}
		if(max_index != 0)
			printf("%d %d %d\n", max_index, judges[max_index].count, judges[max_index].penalty_time);
		judges[max_index].count = 0;
		n_teams--;
	}
}

bool get_score(score judges[101], int *n_teams)
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
		/*printf("team: %d problem: %d chronos: %d result: %c\n", team, problem, chronos, aux);*/
		if(!teams[team])
		{
			teams[team] = true;
			*n_teams = *n_teams + 1;
		}
		if(aux == 'I')
		{
			judges[team].problems[problem] += 20;
		}
		else if(aux == 'C')
		{
			judges[team].problems[problem] += chronos;
			judges[team].solved[problem] = true;
			judges[team].count++;
		}
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
	int test_cases, i, n_teams = 0;
	score *judges;
	char aux2;
	aux2 = getchar();
	test_cases = atoi(&aux2);
	aux2 = getchar();

	for(i = 0; i < test_cases; i++)
	{
		n_teams = 0;
		judges = (score*)malloc(101*sizeof(score));
		init(judges);
		scanf("\n");
		while(get_score(judges, &n_teams));
		print_scores(judges, n_teams);
		if(i != test_cases-1)
			printf("\n");
		free(judges);
	}
	return 0;
}