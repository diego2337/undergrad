#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool fit(int a, int b)
{
	if(a < b)
		return false;
	else
	{
		while(b > 0)
		{
			if(a % 10 != b % 10)
				return false;
			else
			{
				a = a / 10;
				b = b / 10;
			}
		}
		return true;
	}
}

int main(void)
{
	int test_cases, a, b, i;
	scanf("%d", &test_cases);
	for(i = 0; i < test_cases; i++)
	{
		scanf("%d %d", &a, &b);
		if(fit(a, b))
			printf("encaixa");
		else
			printf("nao encaixa");
		printf("\n");
	}
	return 0;
}