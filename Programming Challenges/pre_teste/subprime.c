#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

void charge(int debtor, int creditor, int value, int reserves[20])
{
	reserves[debtor] = reserves[debtor] - value;
	reserves[creditor] = reserves[creditor] + value;
}

int main(void)
{
	int B, N, i, j, reserves[20], debtor, creditor, value;
	bool bailout;
	scanf("%d %d", &B, &N);
	while(B != 0 && N != 0)
	{
		bailout = false;
		for(i = 0; i < B; i++)
		{
			scanf("%d", &reserves[i]);
		}
		for(i = 0; i < N; i++)
		{
			scanf("%d %d %d", &debtor, &creditor, &value);
			/* -1 para indicar indice */
			charge(debtor-1, creditor-1, value, reserves);
		}
		for(i = 0; i < B; i++)
		{
			if(reserves[i] < 0)
				bailout = true;
		}
		if(bailout)
			printf("N\n");
		else
			printf("S\n");
		scanf("%d %d", &B, &N);
	}
	return 0;
}