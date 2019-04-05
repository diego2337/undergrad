#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

void round(int people[10000], int *rnd, int n, int k)
{
	int count = 0;
	while(count != k)
	{
		*rnd = (*rnd + 1) % n;
		if(people[*rnd] != 1)
			count++;
	}
}

void suicide(int people[10000], int rnd)
{
	people[rnd] = 1;
}

int main(void)
{
	int test_cases, n, k, i, j = 0, death_count = 1, rnd, people[10000] = {0};
	scanf("%d", &test_cases);
	for(i = 0; i < test_cases; i++)
	{
		for(j = 0; j < 10000; j++)
			people[j] = 0;
		scanf("%d %d", &n, &k);
		rnd = k - 1;
		suicide(people, rnd);
		death_count++;
		while(death_count != n)
		{
			round(people, &rnd, n, k);
			suicide(people, rnd);
			for(j = 0; j < n; j++)
				printf("%d", people[j]);
			printf("\n");
			death_count++;
		}
		printf("Case %d: ", i+1);
		for(j = 0; j < n; j++)
		{
			if(people[j] == 0)
				printf("%d", j+1);
		}
		printf("\n");
	}
	return 0;
}