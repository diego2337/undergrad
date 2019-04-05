#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int dinostratus[3][3];

/*int dino(int num, int n, int m)
{
	printf("%d\n", num);
	int divisor = 2;
	if(n == 0 && m == 0)
		return 1;
	else
	{
		while(num % divisor != 0 && divisor < 10)
			divisor++;
		if(num % divisor == 0)
		{
			if(n-1 > 0)
				return dino(num/divisor, n-1, m);
		}
		while(num % divisor != 0 && divisor < 10)
			divisor++;
		if(num % divisor == 0)
		{
			if(m-1 > 0)
				return dino(num/divisor, n, m-1);
		}
		else
			return 0;
	}
}*/

int main(void)
{
	int n, tests = 1;
	while(scanf("%d", &n) != EOF)
	{
		printf("Instancia %d\n", tests);
		if((n < 18) || (n % 2 != 0 && n % 3 != 0 && n % 5 != 0 && n % 7 != 0))
		{
			printf("nao\n");
		}
		else if(dino(n, 2, 2))
		{
			printf("sim\n");
		}
		else
			printf("nao\n");
		printf("\n");
	}
	return 0;
}