#include <stdio.h>
int main(void)
{
	int i = 0, j = 0;
	printf("32\n65536\n256\n4\n");
	for(j = 0; j < 1; j++)
	{
		for(i = 0; i < 100; i++)
		{
			printf("%d R %d\n", j, i);
		}
	}
	for(j = 0; j < 1; j++)
	{
		for(i = 256; i < 356; i++)
		{
			printf("%d W %d 0\n", j, i);
		}
	}
	return 0;
}