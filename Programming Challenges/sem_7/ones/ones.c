#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int n, digits, current;
	while(scanf("%d", &n) != EOF)
	{
		digits = 1;
		current = 1;
		while(current % n != 0)
		{
			digits++;
			current = ((current*10) + 1) % n;
		}
		printf("%d\n", digits);
	}
	return 0;
}