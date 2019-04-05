#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int main(void)
{
	int test_cases, num_candidates, candidates[21], i, j, k, l, m, n, votes[1001][21], aux, max, min, min_index[21];
	char names[21][81], c;
	scanf("%d", &test_cases);
	scanf("\n");
	for(i = 0; i < test_cases; i++)
	{
		max = 0;
		min = 100000;
		scanf("%d", &num_candidates);
		c = getchar();
		c = getchar();
		for(j = 0; j < num_candidates; j++)
		{
			k = 0;
			while(c != '\n')
			{
				names[j][k] = c;
				k++;
				c = getchar();
			}
			c = getchar();
			candidates[j] = 0;
		}
		l = 0;
		m = 0;
		while(c != '\n' && l < 1000)
		{
			for(j = 0; j < num_candidates; j++)
			{
				k = 1;
				while(isdigit(c))
				{
					aux = atoi(&c) * (pow(10, k));
					k--;
					c = getchar();
				}
				if(k != -1)
					aux = aux / 10;
				k = 0;
				votes[l][j] = aux;
				if(j == 0)
				{
					candidates[aux] = candidates[aux] + 1;
				}
				c = getchar();
			}
			l++;
		}
		for(j = 1; j <= num_candidates; j++)
		{
			if(candidates[j] > max)
			{
				max = candidates[aux];
			}
			else if(candidates[j] != -1 && candidates[j] < min)
			{
				min = candidates[j];
				m = 0;
				min_index[m] = j;
				m++;
			}
			else if(candidates[j] != -1 && candidates[j] == min)
			{
				min_index[m] = j;
				m++;
			}
		}
		while(max <= l/2 && k < num_candidates)
		{
			min = 1000000;
			for(n = 0; n < m; n++)
			{
				candidates[min_index[n]] = -1;
				for(j = 0; j < l; j++)
				{
					if(votes[j][0] == min_index[n])
					{
						for(k = 0; k < num_candidates; k++)
						{
							candidates[k] = candidates[k+1];
						}
						candidates[votes[j][0]] = candidates[votes[j][0]] + 1;
					}
				}
			}
			for(j = 1; j <= num_candidates; j++)
			{
				if(candidates[j] > max)
				{
					max = candidates[aux];
				}
				else if(candidates[j] != -1 && candidates[j] < min)
				{
					min = candidates[j];
					m = 0;
					min_index[m] = j;
					m++;
				}
				else if(candidates[j] != -1 && candidates[j] == min)
				{
					min_index[m] = j;
					m++;
				}
			}
		}
		for(j = 0; j < num_candidates; j++)
		{
			if(candidates[j] == max)
			{
				for(k = 0; k < strlen(names[j]); k++)
					printf("%c", names[j][k]);
				printf("\n");
			}
		}
	}
	return 0;
}