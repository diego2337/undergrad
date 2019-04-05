#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int days(double x)
{
	if(x < 0.0000000000000)
		return 1;
	else
		return 1 + days(x/2);
}

int main(void)
{
	int n, i;
	double x;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		scanf("%ld", &x);
		printf("%d dias\n", days(x));
	}
	return 0;
}