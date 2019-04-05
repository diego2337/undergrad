#include <stdio.h>
#include <stdlib.h>
#include <math.h>

unsigned long long int mdc(unsigned long long int A, unsigned long long int B)
{
	if(B == 0)
	{
		return A;
	}
	else
		return mdc(B, (A%B));
}

unsigned long long int mmc(unsigned long long int A, unsigned long long int B)
{
	return A*B/mdc(A, B);
}

unsigned long long int intersect(unsigned long long int N, unsigned long long int A, unsigned long long int B)
{
	return N / mmc(A, B);
}

int main(void)
{
	unsigned long long int N, A, B;
	scanf("%llu %llu %llu", &N, &A, &B);
	while(N != 0 && A != 0 && B != 0)
	{
		printf("%llu\n", (N/A)+(N/B)-intersect(N, A, B));
		scanf("%llu %llu %llu", &N, &A, &B);
	}
	return 0;
}