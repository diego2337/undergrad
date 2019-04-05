#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 100

long binomial_coefficients(int n, int k)
{
	int i, j;
	long bc[MAX][MAX];
	for(i = 0; i <= n; i++)
	{
		bc[i][0] = 1;
	}
	for(j = 0; j <= n; j++)
	{
		bc[j][j] = 1;
	}
	for(i = 1; i <= n; i++)
	{
		for(j = 1; j <= i; j++)
		{
			bc[i][j] = bc[i-1][j-1] + bc[i-1][j];
		}
	}
	return bc[n][k];
}

int main(void)
{
	int n, k;
	scanf("%d %d", &n, &k);
	while(n != 0 && k != 0)
	{
		printf("%ld\n", binomial_coefficients(n, k));
		scanf("%d %d", &n, &k);
	}
	return 0;
}