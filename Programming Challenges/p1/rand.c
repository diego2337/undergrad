#include <stdio.h>
#include <time.h>

int main(void)
{
	int n, i;
	srand(time(NULL));
	for(i = 0; i < 1024; i++)
	{
		n = rand() % 1000 + 1;
		printf("%d\n", n);
	}
	return 0;
}