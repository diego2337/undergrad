#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void)
{
	int schedules, i, j, max_nap[1], last_schedule[1], cur_schedule[1];
	char c;
	scanf("%d", &schedules);
	printf("this %d\n", schedules);
	exit(0);
	while(schedules != EOF)
	{
		max_nap[0] = 0;
		max_nap[1] = 0;
		last_schedule[0] = 10;
		last_schedule[1] = 0;
		cur_schedule[0] = 0;
		cur_schedule[1] = 0;
		c = getchar();
		c = getchar();
		fflush(stdout);
		for(j = 0; j < schedules; j++)
		{
			i = 0;
			while(c != ':')
			{
				cur_schedule[0] = (cur_schedule[0]*pow(10, i)) + atoi(&c);
				printf("%d\n", cur_schedule[0]);
				exit(0);
				c = getchar();
				printf("%d\n", cur_schedule[0]);
				i++;
			}
			c = getchar();
			i = 0;
			while(c != ' ')
			{	
				cur_schedule[1] = cur_schedule[1]*pow(2, i) + atoi(&c);
				c = getchar();
				fflush(stdout);
				printf("dddd %c", c);
				i++;
			}
			if(cur_schedule[0]-last_schedule[0] != 0 || cur_schedule[1]-last_schedule[1] != 0)
			{
				if(max_nap[0] < cur_schedule[0]-last_schedule[0] && max_nap[1] < cur_schedule[1]-last_schedule[1])
				{
					max_nap[0] = cur_schedule[0]-last_schedule[0];
					max_nap[1] = cur_schedule[1]-last_schedule[1];
				}
			}
			cur_schedule[0] = 0;
			cur_schedule[1] = 0;
			c = getchar();
			i = 0;
			while(c != ':')
			{
				cur_schedule[0] = cur_schedule[0]*pow(2, i) + atoi(&c);
				c = getchar();
				fflush(stdout);
				printf("ee eee %c", c);
				i++;
			}
			c = getchar();
			while(c != ' ')
			{	
				cur_schedule[1] = cur_schedule[1]*pow(2, i) + atoi(&c);
				c = getchar();
				fflush(stdout);
				printf("ggg %c", c);
				i++;
			}
			last_schedule[0] = cur_schedule[0];
			last_schedule[1] = cur_schedule[1];
			while(c != '\n' && c != EOF)
			{
				c = getchar();
			}
			c = getchar();
		}
		scanf("%d", &schedules);
	}
	return 0;
}