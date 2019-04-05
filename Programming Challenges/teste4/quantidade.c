#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void combination(int m, int n)
{
	int x = m*(m-1);
	int aux = n-2;
	int aux2 = pow(m, aux);
	printf("%d\n", aux2*x);
}

int main(void)
{
	int m, n;
	scanf("%d %d", &m, &n);
	while(m != 0 && n != 0)
	{
		combination(m, n);
		scanf("%d %d", &m, &n);
	}
	return 0;
}