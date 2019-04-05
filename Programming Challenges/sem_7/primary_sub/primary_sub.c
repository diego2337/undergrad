#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void)
{
	unsigned long int a, b, tmp;
	int aux, aux2, count;
	scanf("%lu %lu", &a, &b);
	while(a != 0 || b != 0)
	{
		count = 0;
		while(a > 0 || b > 0)
		{
			aux = a % 10;
			aux2 = b % 10;
			a = a / 10;
			b = b / 10;
			if(aux < aux2)
			{
				tmp = a;
				while(tmp%10 == 0)
				{
					count++;
					tmp = tmp / 10;
				}
				a = a - 1;
				count++;
			}
		}
		if(count == 0)
			printf("Nenhum empresta-um");
		else if(count == 1)
			printf("1 empresta-um");
		else
			printf("%d empresta-uns", count);
		printf("\n");
		scanf("%lu %lu", &a, &b);
	}
	return 0;
}