#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int what(int d1, char c, int d2)
{
	if(d1 == d2)
		return d1*d2;
	else if(isupper(c))
		return d2-d1;
	else
		return d1+d2;
}

int main(void)
{
	int n, d1, d2, i;
	char c;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		scanf("%d %c %d", &d1, &c, &d2);
		printf("%d\n", what(d1, c, d2));
	}
	return 0;
}