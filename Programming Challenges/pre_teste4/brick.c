#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int test_cases, i, j, k, team, cap;
	scanf("%d", &test_cases);
	for(i = 0; i < test_cases; i++)
	{
		team = cap = k = 0;
		scanf("%d", &team);
		k = team/2;
		for(j = 0; j < team; j++)
		{
			scanf("%d", &cap);
			if(j == k)
			{
				printf("%d\n", cap);
			}
		}
	}
	return 0;
}