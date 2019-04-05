#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int N;
	scanf("%d", &N);
	while(N != EOF)
	{
		if((N % 6) == 0)
			printf("Y");
		else
			printf("N");
		printf("\n");
		scanf("%d", &N);
		if(N == 0)
			exit(0);
		printf("n: %d\n", N);
	}
	return 0;
}