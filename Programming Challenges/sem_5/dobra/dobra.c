#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int dobra(int N)
{
	if(N == 0)
		return 0;
	else
		return 2*dobra(N-1)+1;
}

int main(void)
{
	int N, P, V, B, i = 1;
	scanf("%d", &N);
	while(N != -1)
	{
		P = dobra(N);
		V = P + 1;
		B = V + 1;
		printf("Teste %d\n%d\n\n", i, B*B);
		i++;
		scanf("%d", &N);
	}
	return 0;
}