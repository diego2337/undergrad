#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void count_hartals(int hartal, int n, int days[])
{
	int i;
	for(i = -1+hartal; i < n; i = i + hartal)
	{
		days[i % n] = 1;
	}
}

int main(void)
{
	int test_cases, n, days[3650], parties, hartal, i, j, count;
	scanf("%d", &test_cases);
	for(i = 0; i < test_cases; i++)
	{
		count = 0;
		scanf("%d %d", &n, &parties);
		for(j = 0; j < 3650; j++)
			days[j] = 0;
		for(j = 0; j < parties; j++)
		{
			scanf("%d", &hartal);
			count_hartals(hartal, n, days);
		}
		for(j = 0; j <= n; j++)
		{
			if(days[j] == 1 && j % 7 != 5 && j % 7 != 6)
				count++;
		}
		printf("%d\n", count);
	}
	return 0;
}