#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int min(int A, int B)
{
	if(A-B < 0)
		return A;
	else
		return B;
}

int max(int A, int B)
{
	if(A-B < 0)
		return B;
	else
		return A;
}

int lus(int aCards[100000], int bCards[100000], int A, int B)
{
	int prev, i, j, k, k2, count = 0;
	bool uncommon;
		for(j = 0; j < B; j++)
		{
			k = j;
			uncommon = true;
			if(count == A)
				break;
			if(bCards[j] == prev)
			{}	/* Do nothing*/
			else
			{
				for(k2 = k; k2 < A || !uncommon; k2++)
				{
					if(aCards[k2] == bCards[j])
					{
						uncommon = false;
					}
				}
				for(k2 = k; k2 < B || !uncommon; k2++)
				{
					if(bCards[k2] == aCards[j])
					{
						uncommon = false;
					}
				}
				if(uncommon)
				{
					count++;
				}
			}
			prev = bCards[j];
		}
	return count;
}

int main(void)
{
	int A, B, aCards[100000], bCards[100000], i, maxTrade;
	scanf("%d %d", &A, &B);
	while(A != 0 && B != 0)
	{
		maxTrade = 0;
		for(i = 0; i < A; i++)
		{
			scanf("%d", &aCards[i]);
		}
		for(i = 0; i < B; i++)
		{
			scanf("%d", &bCards[i]);
		}
		i = min(A, B);
		if(i == A)
			maxTrade = lus(aCards, bCards, A, B);
		else
			maxTrade = lus(bCards, aCards, A, B);
		printf("%d\n", maxTrade);
		scanf("%d %d", &A, &B);
	}
	return 0;
}