#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct 
{
	int hours, minutes, seconds;
}timestamp;

void change_speed(int *speed, int change)
{
	*speed = change;
}

void query(timestamp tempo, timestamp last_change, int speed, double *total_km, int p)
{
	double km_h = (double) speed / 60;
	km_h = km_h / 60;
	/**total_km = *total_km + ((abs(tempo.hours-last_change.hours)*60*60*km_h) + 
		(abs(tempo.minutes-last_change.minutes)*60*km_h)
		+ abs(tempo.seconds-last_change.seconds)*km_h);*/
	*total_km = *total_km + abs((tempo.hours*60*60+tempo.minutes*60+tempo.seconds)
		-
		(last_change.hours*60*60+last_change.minutes*60+last_change.seconds))*km_h;
	if(p == 1)
		printf("%02d:%02d:%02d %.2lf km\n", tempo.hours, tempo.minutes, tempo.seconds, *total_km);
}

int main(void)
{
	timestamp tempo, last_change;
	int change, speed = 0, first = 1;
	double total_km = 0.00000000;
	char c;
	last_change.hours = 0;
	last_change.minutes = 0;
	last_change.seconds = 0;
	while(scanf("%d:", &tempo.hours) != EOF)
	{
		scanf("%d:%d", &tempo.minutes, &tempo.seconds);
		c = getchar();
		while(!isdigit(c) && c != '\n' && c != EOF)
		{
			c = getchar();
		}
		if(isdigit(c))
		{
			ungetc(c, stdin);
			scanf("%d", &change);
			if(first == 0)
				query(tempo, last_change, speed, &total_km, 0);
			else
				first = 0;
			change_speed(&speed, change);
		}
		else
		{
			query(tempo, last_change, speed, &total_km, 1);
		}
		last_change.hours = tempo.hours;
		last_change.minutes = tempo.minutes;
		last_change.seconds = tempo.seconds;
	}
	return 0;
}