#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>



int main(void)
{
	int num;
	unsigned long int result;
	int k, n, i;
	while(scanf("%d", &k) != EOF)
	{
		scanf("%d", &n);
		result = 0;
		for(i = 0; i < n; i++)
		{
			scanf("%d", &num);
			result = result + pow(num, k);
		}
		printf("%lu\n", result);
	}
	return 0;
}