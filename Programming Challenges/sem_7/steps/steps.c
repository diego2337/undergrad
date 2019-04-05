#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void)
{
	int m, n;
	scanf("%d", &m);
	n = sqrt(m);
	if(n*n == m) printf("%d\n", 2*n-1);
	else if(n*n+n >= m) printf("%d\n", 2*n);
	else printf("%d\n", 2*n+1);
	return 0;
}