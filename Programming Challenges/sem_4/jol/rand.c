#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int i, test, days, parties, hart = 7, j;
	srand(time(NULL));
	test = rand() % 100 + 1;
	for( i =0; i < test; i++)
	{
		parties = rand() % 100 + 1;
		printf("%d ", parties);
		for(j = 0; j < parties; j++)
		{
			hart = rand() % 37 + 7;
			printf("%d ", hart);
		}
		printf("\n");
	}
	return 0;
}
