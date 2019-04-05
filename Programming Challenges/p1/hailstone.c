#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max;

int hailstone(int h)
{
	if(h > max)
		max = h;
	if(h == 1)
		return 1;
	else if(h % 2 == 0)
		return hailstone(h/2);
	else
		return hailstone(3*h + 1);
}

int main(void)
{
	int h, num;
	scanf("%d", &h);
	while(h != 0)
	{
		max = 0;
		num = hailstone(h);
		printf("%d\n", max);
		scanf("%d", &h);
	}
	return 0;
}