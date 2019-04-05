#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	unsigned long int a, b;
	int aux, aux2, carry, count;
	scanf("%lu %lu", &a, &b);
	while(a != 0 || b != 0)
	{
		carry = count = 0;
		while(a > 0 || b > 0)
		{
			aux = a % 10;
			aux2 = b % 10;
			carry = (aux+aux2+carry)/10;
			if(carry > 0)
				count++;
			a = a / 10;
			b = b / 10;
		}
		if(count == 0)
			printf("No carry operation.");
		else if(count == 1)
			printf("1 carry operation.");
		else
			printf("%d carry operations.", count);
		printf("\n");
		scanf("%lu %lu", &a, &b);
	}
	return 0;
}