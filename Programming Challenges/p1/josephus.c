#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int josephus(int n, int k)
{
	if(n == 1)
		return 1;
	else
		return ((josephus(n-1, k) + k-1) % n+1);
}

int main(void)
{
	int NC, n, k, i;
	scanf("%d", &NC);
	for(i = 0; i < NC; i++)
	{
		scanf("%d %d", &n, &k);
		printf("Case %d: %d\n", i+1, josephus(n, k));
	}
	return 0;
}