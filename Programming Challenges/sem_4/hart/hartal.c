#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void count_hartals(int hartal, int n, int days[3651])
{
	int i;
	for(i = -1+hartal; i < n; i = i + hartal)
	{
		days[i % n] = 1;
	}
}

int main(void)
{
	int test_cases, n, days[3651], parties, hartal, i, j, count;
	scanf("%d", &test_cases);
	for(i = 0; i < test_cases; i++)
	{
		memset(days, 0, 3651);
		count = 0;
		scanf("%d %d", &n, &parties);
		for(j = 0; j < parties; j++)
		{
			scanf("%d", &hartal);
			count_hartals(hartal, n, days);
		}
		for(j = 0; j < n; j++)
		{
			if((j % 5) != 0 && (j % 6) != 0) 
			{
				if(days[j] == 1)
					count++;
			}
		}
		printf("%d\n", count);
	}
	return 0;
}