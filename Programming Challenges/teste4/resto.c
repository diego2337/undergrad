#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void divide(char x[1001], int q)
{
	int desce = 0, i = 0, j;
	char c;
	j = 0;
	while(desce < q)
	{
		c = x[i];
		desce = desce * pow(10, j) + atoi(&c);
		i++;
		j++;
	}
	desce = desce % q;
	while(i < strlen(x)-1)
	{
		j = 1;
		while(desce < q)
		{
			c = x[i];
			desce = desce * pow(10, j) + atoi(&c);
			i++;
			j++;
		}
		desce = desce % q;
	}
	printf("%d\n", desce);
}

int main(void)
{
	char x[1001];
	int q, i, test_cases;
	scanf("%d", &test_cases);
	for(i = 0; i < test_cases; i++)
	{
		scanf("%s %d", x, &q);
		divide(x, q);
	}
	return 0;
}