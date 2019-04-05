#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

typedef struct 
{
	char name[101];
	int points, games, wins, ties, losses, total_goals, pro_goals, cons_goals;
} quadrigis;

int compare(const void * a, const void * b)
{
	int i;
	quadrigis aux = *(quadrigis*)a;
	quadrigis aux2 = *(quadrigis*)b;
	if(aux.points != aux2.points) return aux2.points - aux.points;
	if(aux.wins != aux2.wins) return aux2.wins - aux.wins;
	if(aux.total_goals != aux2.total_goals) return aux2.total_goals - aux.total_goals;
	if(aux.pro_goals != aux2.pro_goals) return aux2.pro_goals - aux.pro_goals;
	if(aux.games != aux2.games) return aux.games - aux2.games;
	for(i = 0; i < strlen(aux.name); i++)
	{
		aux.name[i] = tolower(aux.name[i]);
	}
	for(i = 0; i < strlen(aux2.name); i++)
	{
		aux2.name[i] = tolower(aux2.name[i]);
	}
	return strcmp(aux.name, aux2.name);
}

int match_team(char team[101], quadrigis teams[1000], int T)
{
	int i;
	for(i = 0; i < T; i++)
	{
		if(strcmp(team, teams[i].name) == 0)
		{
			return i;
		}
	}
	return -1;
}

int main(void)
{
	int N, T, G, i, j, k, aux, score1, score2;
	char c, cup[301], team[101];
	quadrigis teams[3000];
	scanf("%d", &N);
	c = getchar();
	c = getchar();
	for(i = 0; i < N; i++)
	{
		k = 0;
		while(!isalpha(c))
			c = getchar();
		while(c != '\n')
		{
			cup[k] = c;
			k++;
			c = getchar();
		}
		cup[k] = '\0';
		scanf("%d", &T);
		while(!isalpha(c))
			c = getchar();
		for(j = 0; j < T; j++)
		{
			k = 0;
			while(c != '\n')
			{
				teams[j].name[k] = c;
				k++;
				c = getchar();
			}
			teams[j].name[k] = '\0';
			teams[j].points = teams[j].games = teams[j].wins = teams[j].ties = teams[j].losses = 
			teams[j].total_goals = teams[j].pro_goals = teams[j].cons_goals = 0;
			if(j != T-1)
				c = getchar();
		}
		scanf("%d", &G);
		c = getchar();
		for(j = 0; j < G; j++)
		{
			k = 0;
			score1 = 0;
			score2 = 0;
			while(!isalpha(c) && c != EOF)
				c = getchar();
			while(c != '#')
			{
				team[k] = c;
				k++;
				c = getchar();
			}
			team[k] = '\0';
			k = match_team(team, teams, T);
			if(k != -1)
			{
				strcpy(teams[k].name, team);
				teams[k].games = teams[k].games + 1;
				c = getchar();
				aux = 0;
				while(isdigit(c))
				{
					score1 = score1 * pow(10, aux) + atoi(&c);
					aux++;
					c = getchar();
				}
				teams[k].pro_goals = teams[k].pro_goals + score1;
				c = getchar();
				aux = 0;
				while(isdigit(c))
				{
					score2 = score2 * pow(10, aux) + atoi(&c);
					aux++;
					c = getchar();
				}
				teams[k].cons_goals = teams[k].cons_goals + score2;
				if(score1 > score2)
				{
					teams[k].wins = teams[k].wins + 1;
					teams[k].points = teams[k].points + 3;
				}
				else if(score1 == score2)
				{
					teams[k].ties = teams[k].ties + 1;
					teams[k].points = teams[k].points + 1;
				}
				else
				{
					teams[k].losses = teams[k].losses + 1;	
				}
				teams[k].total_goals = (teams[k].pro_goals-teams[k].cons_goals);
				/*puts("--------------------------");
				printf("Time: %s\n", teams[k].name);
				printf("Games: %d\n", teams[k].points);
				printf("Jogos: %d\n", teams[k].games);
				printf("Gols-pro: %d\n", teams[k].pro_goals);
				printf("Gols-contra: %d\n", teams[k].cons_goals);
				printf("Wins: %d\n", teams[k].wins);
				printf("Ties: %d\n", teams[k].ties);
				printf("Losses: %d\n", teams[k].losses);
				printf("Total: %d\n", teams[k].total_goals);
				puts("--------------------------");*/
			}
			c = getchar();
			k = 0;
			while(c != '\n' && c != EOF)
			{
				team[k] = c;
				k++;
				c = getchar();
			}
			team[k] = '\0';
			k = match_team(team, teams, T);
			if(k != -1)
			{
				strcpy(teams[k].name, team);
				teams[k].games = teams[k].games + 1;
				teams[k].pro_goals = teams[k].pro_goals + score2;
				teams[k].cons_goals = teams[k].cons_goals + score1;
				if(score1 < score2)
				{
					teams[k].wins = teams[k].wins + 1;
					teams[k].points = teams[k].points + 3;
				}
				else if(score1 == score2)
				{
					teams[k].ties = teams[k].ties + 1;
					teams[k].points = teams[k].points + 1;	
				}
				else
				{
					teams[k].losses = teams[k].losses + 1;
				}
				teams[k].total_goals = (teams[k].pro_goals-teams[k].cons_goals);
				/*puts("--------------------------");
				printf("Time2: %s\n", teams[k].name);
				printf("Games: %d\n", teams[k].points);
				printf("Jogos: %d\n", teams[k].games);
				printf("Gols-pro: %d\n", teams[k].pro_goals);
				printf("Gols-contra: %d\n", teams[k].cons_goals);
				printf("Wins: %d\n", teams[k].wins);
				printf("Ties: %d\n", teams[k].ties);
				printf("Losses: %d\n", teams[k].losses);
				printf("Total: %d\n", teams[k].total_goals);
				puts("--------------------------");*/
				c = getchar();
			}
		}
		qsort(teams, T, sizeof(quadrigis), compare);
		printf("%s\n", cup);
		for(j = 0; j < T; j++)
		{
			printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n", j+1, teams[j].name, teams[j].points,
			teams[j].games, teams[j].wins, teams[j].ties, teams[j].losses, teams[j].total_goals, teams[j].pro_goals, teams[j].cons_goals);
		}
		if(i != N-1)
			printf("\n");
	}
	return 0;
}