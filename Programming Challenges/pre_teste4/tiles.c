#include <stdio.h>
#include <stdlib.h>

int sequence(int x)
{
	if(x == 1) return 1;
	else if(x == 2)	return 2;
	else
	{
		return sequence(x-1) + sequence(x-2);
	}
}

int main(void)
{
	int n;
	scanf("%d", &n);
	while(n != 0)
	{
		printf("%d\n", sequence(n));
		scanf("%d", &n);
	}
	return 0;
}