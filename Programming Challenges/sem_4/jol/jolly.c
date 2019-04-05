#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

bool jolly_jump(int jollies[3001], int n)
{
	int i, j, count = 0;
	bool jolly = true;
	for(i = 0, j = 1; i < n-1; i++)
	{
		if(j < n)
		{
			count += abs(jollies[i]-jollies[j]);
			if(abs(jollies[i]-jollies[j]) < 1 || abs(jollies[i]-jollies[j]) > n-1)
			{
				jolly = false;
			}
		}
		j++;
	}
	if(count == ((n-1)*(1+n-1)/2) && jolly)
		return true;
	else
		return false;
}

int main(void)
{
	int n, i, jollies[3001];
	while(scanf("%d", &n) != EOF)
	{
		for(i = 0; i < n; i++)
			jollies[i] = 0;
		for(i = 0; i < n; i++)
		{
			scanf("%d", &jollies[i]);
		}
		if(jolly_jump(jollies, n))
		{
			printf("Jolly\n");
		}
		else
		{
			printf("Not jolly\n");
		}
	}
	return 0;
}