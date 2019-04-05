#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int N, M, carry, i, j, *x_nums, *y_nums, *num;
	scanf("%d", &N);
	for(i = 0; i < N; i++)
	{
		scanf("\n");
		scanf("%d", &M);
		x_nums = (int*)malloc(M*sizeof(int));
		y_nums = (int*)malloc(M*sizeof(int));
		num = (int*)malloc(M*sizeof(int));
		for(j = 0; j < M; j++)
		{
			scanf("%d %d", &x_nums[j], &y_nums[j]);
		}
		carry = 0;
		for(j = M-1; j > 0; j--)
		{
			num[j] = (x_nums[j] + y_nums[j] + carry) % 10;
			carry = (x_nums[j] + y_nums[j] + carry) / 10;
		}
		if(M == 1000000)
			num[0] = (x_nums[j] + y_nums[j] + carry) / 10;
		else
			num[0] = (x_nums[j] + y_nums[j] + carry);
		for(j = 0; j < M; j++)
			printf("%d", num[j]);
		printf("\n");
		printf("\n");
		free(x_nums);
		free(y_nums);
		free(num);
	}
	return 0;
}