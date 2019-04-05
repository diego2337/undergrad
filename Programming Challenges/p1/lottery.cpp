#include <iostream>
#include <map>
#include <stdio.h>
using namespace std;

int main(void)
{
	int N, C, K, num, min;
	map<int, int> numbers;
	scanf("%d %d %d", &N, &C, &K);
	while(N != 0 && C != 0 && K != 0)
	{
		numbers.clear();
		min = 10000000;
		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < C; j++)
			{
				scanf("%d", &num);
				numbers[num]++;
			}
		}
		for(int i = 1; i <= K; i++)
		{
			if(numbers[i] <= min)
			{
				min = numbers[i];
			}
		}
		for(int i = 1; i <= K; i++)
		{
			if(numbers[i] == min)
			{
				if(i != 1)
					printf(" ");
				printf("%d", i);
			}
		}
		printf("\n");
		scanf("%d %d %d", &N, &C, &K);
		if(N == 0 && C == 0 && K == 0)
			printf("\n");
	}
	return 0;
}