#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
	int days;
	int cost;
	int job_num;
	float ratio;
} job;

int compare(const void * a, const void * b)
{
	job aux = *(job*)a;
	job aux2 = *(job*)b;
	if(aux.ratio-aux2.ratio > 0)
		return 1;
	else if (aux.ratio-aux2.ratio == 0)
		return 0;
	else
		return -1;
}

int main(void)
{
	int test_cases, N, i, j;
	job opus[1001];
	scanf("%d", &test_cases);
	for(i = 0; i < test_cases; i++)
	{
		scanf("\n");
		scanf("%d", &N);
		for(j = 0; j < N; j++)
		{
			scanf("%d %d", &opus[j].days, &opus[j].cost);
			opus[j].job_num = j+1;
			opus[j].ratio = (float)opus[j].days/opus[j].cost;
		}
		qsort(opus, N, sizeof(job), compare);
		for(j = 0; j < N; j++)
		{
			if(j != 0)
				printf(" ");
			printf("%d", opus[j].job_num);
		}
		printf("\n");
		if(i != test_cases-1)
			printf("\n");
	}
	return 0;
}