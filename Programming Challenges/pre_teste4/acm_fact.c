#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fact(int x)
{
	if(x == 0 || x == 1)
		return 1;
	else
		return x * fact(x-1);
}

int main(void)
{
	int acm, number[6], i, j, total;
	scanf("%d", &acm);
	while(acm != 0)
	{
		i = 1;
		total = 0;
		while(acm > 0)
		{
			number[i] = acm % 10;
			number[i] = number[i] * fact(i);
			i++;
			acm = acm / 10;
		}
		for(j = 1; j < i; j++)
			total = total + number[j];
		printf("%d\n", total);
		scanf("%d", &acm);
	}
	return 0;
}