#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max, max2, max_index, max2_index, min, min2, min_index, min2_index;

int compare(const void * a, const void * b)
{
	return *(int*)a - *(int*)b;
}

void cross(int people[2000], int n, int crossed, int total_time)
{
	int goes[2000], comes[2000], i = 0, j = 0, k, l;
	while(crossed < n)
	{
		if(2*min+max+max2 < 2*min2+min+max)
		{
			crossed = crossed + 2;
			goes[i] = min;
			i++;
			goes[i] = max;
			i++;
			if(crossed != n)
			{
				comes[j] = min;
				j++;
				goes[i] = min;
				i++;
				goes[i] = max2;
				i++;
				if(crossed+1 < n)
				{
					comes[j] = min;
					j++;
					total_time = total_time + 2*min+max+max2;
				}
				else
				{
					total_time = total_time + min+2*max;
					crossed++;
				}
			}
			else
			{
				total_time = total_time + max;
			}
		}
		else
		{
			crossed = crossed + 2;	
			goes[i] = min;
			i++;
			goes[i] = min2;
			i++;
			if(crossed < n)
			{
				comes[j] = min;
				j++;
				goes[i] = max2;
				i++;
				goes[i] = max;
				i++;
				if(crossed+1 < n)
				{
					comes[j] = min2;
					j++;
					total_time = total_time + 2*min2+min+max;
				}
				else
				{
					total_time = total_time + 2*min2+max;
					crossed++;
				}
			}
			else
			{
				total_time = total_time + min2;
			}
		}
		people[n-1] = -1;
		people[n-2] = -1;
		max = people[n-1-crossed];
		max2 = people[n-1-(crossed+1)];
		min = people[0];
		min2 = people[1];
	}
	printf("%d\n", total_time);
	for(k = 0, l = 0; k < i; k=k+2)
	{
		if(k != 0 && k % 2 == 0)
		{
			printf("%d\n", comes[l]);
			l++;
		}
		printf("%d %d\n", goes[k], goes[k+1]);
	}
}

int main(void)
{
	int test_cases, n, i, j, people[2000], crossed, total_time;
	scanf("%d", &test_cases);
	for(i = 0; i < test_cases; i++)
	{
		scanf("\n");
		scanf("%d", &n);
		max = max2 = crossed = total_time = 0;
		min = min2 = 100000;
		for(j = 0; j < n; j++)
		{
			scanf("%d", &people[j]);
		}
		qsort(people, n, sizeof(int), compare);
		max = people[n-1];
		max2 = people[n-2];
		min = people[0];
		min2 = people[1];
		if(n == 0)
			printf("0\n0 0\n");
		else if(n == 1)
			printf("%d\n%d\n", people[0], people[0]);
		else
			cross(people, n, crossed, total_time);
		if(i != test_cases-1)
			printf("\n");
	}
	return 0;
}