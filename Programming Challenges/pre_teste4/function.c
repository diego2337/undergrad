#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int rafael(int x, int y)
{
	return pow((3*x), 2) + pow(y, 2);
}

int beto(int x, int y)
{
	return 2*(pow(x, 2)) + pow(5*y, 2);
}

int carlos(int x, int y)
{
	return -100*x + pow(y, 3);
}

int max(int x, int y)
{
	int a, b, c;
	a = rafael(x, y);
	b = beto(x, y);
	c = carlos(x, y);
	if(a > b && a > c)
		return 1;
	else if(b > c && b > a)
		return 2;
	else
		return 3;
}

int best(int x, int y)
{
	int result;
	result = max(x, y);
	return result;
}

int main(void)
{
	int i, test_cases, x, y, result;
	scanf("%d", &test_cases);
	for(i = 0; i < test_cases; i++)
	{
		scanf("%d %d", &x, &y);
		result = best(x, y);
		if(result == 1)
			printf("Rafael ganhou");
		else if(result == 2)
			printf("Beto ganhou");
		else
			printf("Carlos ganhou");
		printf("\n");
	}
	return 0;
}