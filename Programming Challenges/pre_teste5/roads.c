#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int R, N, lines = 0, cases = 1, results;
	scanf("%d %d", &R, &N);
	while(R != 0 && N != 0 && lines < 10003)
	{
		if(R % N == 0)
			results = (R / N) - 1;
		else
			results = (R / N);
		printf("Case %d: ", cases);
		if(results > 26)
			printf("impossible");
		else
			printf("%d", results);
		printf("\n");
		cases++;
		scanf("%d %d", &R, &N);
	}
	return 0;
}