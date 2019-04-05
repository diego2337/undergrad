#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned long long int goloumb(unsigned long long int x)
{
	if(x == 1) return 1;
	else
	{
		return 1 + goloumb((x-1)+1 - goloumb(goloumb(x-1)));
	}
}

int main(void)
{
	unsigned long long int x;
	scanf("%llu", &x);
	while(x != 0)
	{
		printf("%llu\n", goloumb(x));
		scanf("%llu", &x);
	}
	return 0;
}