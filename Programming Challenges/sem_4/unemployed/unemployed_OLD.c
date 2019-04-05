#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*void toStr(char digit[], int *size, int num)
{
	int i = 2;
	while(num / 10 > 0 && i >= 0)
	{
		digit[i] = num % 10;
		num = num / 10;
		*size = *size + 1;
		i = i - 1;
	}
	i = i - 1;
	digit[i] = num % 10;
	for(i = 0; i < 2; i++)
		printf("%c", digit[i]);
}*/

void clockwise_round(int *rnd, int people[], int n, int k)
{
	int count = 1;
	while(count != k)
	{
		*rnd = (*rnd + 1) % n;
		if(people[*rnd] != 1)
			count = count + 1;
	}
}

void counter_clockwise_round(int *rnd, int people[], int n, int m)
{
	int count = 1;
	while(count != m)
	{
		*rnd = ((*rnd - 1) % n);
		if(*rnd < 0)
			*rnd = *rnd + n;
		if(people[*rnd] != 1)
			count = count + 1;
	}
}

void selecionar(int rnd, int people[], int *selected)
{
	if(people[rnd] != 1)
	{
		people[rnd] = 1;
		*selected = *selected + 1;
	}
}

int main(void)
{
	int n, k, m, people[20], i, selected, rnd, rnd2, size;
	char digit[3];
	scanf("%d %d %d", &n, &k, &m);
	while(n != 0 && k != 0 && m != 0)
	{
		for(i = 0; i < 20; i++)
			people[i] = 0;
		selected = 0;
		rnd = 1;
		rnd2 = 0;
		if(n == 1)
		{
			printf("  1");
		}
		else
		{
			if(k % n == 0)
				k = n;
			else
				k = k % n;
			if(m % n == 0)
				m = n;
			else
				m = m % n;
			while(selected != n)
			{
				clockwise_round(&rnd, people, n, k);
				counter_clockwise_round(&rnd2, people, n, m);
				selecionar(rnd, people, &selected);
				selecionar(rnd2, people, &selected);
				if(rnd == 0)
					rnd = n;
				if(rnd2 == 0)
					rnd2 = n;
				if(rnd != rnd2)
				{
					if(rnd < 10)
						printf("  %d", rnd);
					else if(rnd < 100)
						printf(" %d", rnd);
					else
						printf("%d", rnd);
					if(rnd2 < 10)
						printf("  %d", rnd2);
					else if(rnd2 < 100)
						printf(" %d", rnd2);
					else
						printf("%d", rnd2);
					/*printf("  %d  %d", rnd, rnd2);*/
				}
				else
				{
					if(rnd < 10)
						printf("  %d", rnd);
					else if(rnd < 100)
						printf(" %d", rnd);
					else
						printf("%d", rnd);
					/*printf("  %d", rnd);*/
				}
				if(selected != n)
				{
					printf(",");
					clockwise_round(&rnd, people, n, 2);
					counter_clockwise_round(&rnd2, people, n, 2);
				}
			}
		}
		printf("\n");
		scanf("%d %d %d", &n, &k, &m);
	}
	return 0;
}