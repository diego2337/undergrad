#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int N, X[2001] = {0}, i, j;
	scanf("%d", &N);
	for(i = 0; i < N; i++)
	{
		scanf("%d", &j);
		X[j]++;
	}
	for(i = 0; i < 2001; i++)
	{
		if(X[i] != 0)
		{
			printf("%d aparece %d vez(es)\n", i, X[i]);
		}
	}
	return 0;
}