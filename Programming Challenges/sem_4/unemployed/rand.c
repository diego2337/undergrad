#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int n, k, m, i, j;
	srand(time(NULL));
	j = rand() % 99;
	for(i = 0; i < j; i++)
	{
		n = (rand() % 20) + 1;
		k = rand() + 1;
		m = rand() + 1;
		printf("%d %d %d\n", n, k, m);
	}
	printf("0 0 0");
	return 0;
}