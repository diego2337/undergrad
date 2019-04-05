#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

int compare(const void *a, const void *b)
{
	return ((*(int*)a) - (*(int *)b));
}

int walk_the_plank(int planks[100000], int N, int M, int n_planks, bool line)
{
	/* Linha por linha ou coluna por coluna */
	int i, j, aux, rem, total = 0, filled = 0, p_copy[n_planks];
	aux = n_planks-1;
	for(i = 0; i < n_planks; i++)
		p_copy[i] = planks[i];
	/* Colunas */
	if(!line)
	{
		for(aux; aux >= 0; aux--)
		{
			rem = abs(p_copy[aux] - M);
			if(rem != 0)
			{
				for(i = 0; i < aux; i++)
				{
					if(p_copy[i] == rem)
					{
						p_copy[aux] = -1;
						p_copy[i] = -1;
						total = total + 2;
						filled++;
						i = aux + 15;
					}
				}
			}
			else
			{
				p_copy[aux] = -1;
				total++;
				filled++;
			}
		}
	}
	else /* Linhas */
	{
		for(aux; aux >= 0; aux--)
		{
			rem = abs(p_copy[aux] - N);
			if(rem != 0)
			{
				for(i = 0; i < aux; i++)
				{
					if(p_copy[i] == rem)
					{
						p_copy[aux] = -1;
						p_copy[i] = -1;
						total = total + 2;
						filled++;
						i = aux + 15;
					}
				}
			}
			else
			{
				p_copy[aux] = -1;
				total++;
				filled++;
			}
		}
	}
	if((!line && filled == N) || (line && filled == M))
		return total;
	else
		return -1;
}

int main(void)
{
	int N, M, width, n_planks, planks[100000], i, result, result2;
	scanf("%d %d", &N, &M);
	while(N != 0 || M != 0)
	{
		for(i = 0; i < 100000; i++)
			planks[i] = 10000;
		scanf("%d", &width);
		scanf("%d", &n_planks);
		for(i = 0; i < n_planks; i++)
		{
			scanf("%d", &planks[i]);
		}
		qsort((void*)planks, n_planks, sizeof(int), compare);
		for(i = 0; i < n_planks; i++)
		{
			if(planks[i] > N && planks[i] > M)
			{
				n_planks = i - 1;
				i = n_planks + 10;
			}
		}
		result = walk_the_plank(planks, N, M, n_planks, false);
		result2 = walk_the_plank(planks, N, M, n_planks, true);
		if(result == -1 && result2 == -1)
			printf("impossivel\n");
		else if(result == -1)
			printf("%d\n", result2);
		else
			printf("%d\n", result);
		scanf("%d %d", &N, &M);
	}
	return 0;
}