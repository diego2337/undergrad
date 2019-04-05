#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
	char team_name[20];
}team_string;

int draws(int *times_score, int matches, int teams)
{
	int i, total_score = 0, points = 0;
	int triple = matches * 3;
	for(i = 0; i < teams; i++)
	{
		total_score += times_score[i];
	}
	if(triple - total_score > matches)
		return matches;
	else
		return triple - total_score;
}

int main(void)
{
	team_string *times;
	int *times_score;
	bool first = true;
	int teams = -1, matches = -1, i, empates = 0;
	scanf("%d %d", &teams, &matches);
	while(teams != 0 || matches != 0)
	{
		if(first)
		{
			first = false;
		}
		else if(!first)
			printf("\n");
		times = (team_string*)malloc(sizeof(team_string));
		times_score = (int*)malloc(sizeof(int));
		for(i = 0; i < teams; i++)
		{
			scanf(" %s", times[i].team_name);
			scanf("%d", &times_score[i]);
		}
		if(matches == 0)
			empates = 0;
		else
			empates = draws(times_score, matches, teams);
		printf("%d", empates);
		scanf("%d %d", &teams, &matches);
	}
	return 0;
}