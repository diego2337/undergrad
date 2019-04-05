#include <stdio.h>

int main(void)
{
	int mask = 6, my_id = 3;
	if((my_id & mask) == 0)
		printf("eh zero\n");
	else
		printf("eh um\n");
	return 0;
}