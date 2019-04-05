#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int n, x, i;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		scanf("%d", &x);
		if(x % 2 == 0 || x % 3 == 0 || x % 5 == 0 || x % 7 == 0)
			printf("Not Prime");
		else
			printf("Prime");
		printf("\n");
	}
	return 0;
}