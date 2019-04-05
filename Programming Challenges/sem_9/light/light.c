#include <stdio.h>
#include <math.h>

int main(void)
{
	double x, result;
	scanf("%lf", &x);
	while(x != 0.000000000)
	{
		result = sqrt(x);
		if(ceil(result) == result)
			printf("sim\n");
		else
			printf("nao\n");
		scanf("%lf", &x);
	}
	return 0;
}