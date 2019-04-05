#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int test, days, parties, hart = 7, j;
	srand(time(NULL));
	test = rand() % 100 + 1;
	printf("%d\n", test);
	for(int i =0; i < test; i++)
	{
		hart = 7;
		days = rand() % 3650 + 7;
		printf("%d\n", days);
		parties = rand() % 100 + 1;
		printf("%d\n", parties);
		for(j = 0; j < parties; j++)
		{
			while(hart == 7)
				hart = rand() % 37 + 7;
			printf("%d\n", hart);
		}
	}
	return 0;
}
