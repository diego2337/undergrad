#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(void)
{
	int N, B, i, j, numbers[91], num, count;
	bool valid[91];
	scanf("%d %d", &N, &B);
	while(N != 0 && B != 0)
	{
		count = 0;
		for(i = 0; i < N; i++)
			valid[i] = true;
		for(i = 0; i < B; i++)
			scanf("%d", &numbers[i]);
		for(i = 0; i < B; i++)
		{
			num = numbers[i];
			for(j = i+1; j < B; j++)
			{
				if(abs(num-numbers[j]) >= 0 && abs(num-numbers[j]) <= N && valid[abs(num-numbers[j])-1])
				{
					count++;
					valid[abs(num-numbers[j])-1] = false;
				}
			}
		}
		if(count == N)
			printf("Y");
		else
			printf("N");
		printf("\n");
		scanf("%d %d", &N, &B);
	}
	return 0;
}