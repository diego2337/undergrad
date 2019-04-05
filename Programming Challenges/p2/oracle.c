#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef unsigned long long int ulli;
ulli k_fact(ulli N, ulli K)
{
	if(N <= 1 || N > 100)
		return 1;
	else
		return N * k_fact(N-K, K);
}

int main(void)
{
	ulli T, i, N, K;
	char fact[20];
	scanf("%llu", &T);
	for(i = 0; i < T; i++)
	{
		scanf("%llu%s", &N, fact);
		K = strlen(fact);
		printf("%llu\n", k_fact(N, K));
	}
	return 0;
}