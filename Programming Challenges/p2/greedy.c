#include <stdio.h>
#include <stdlib.h>
typedef unsigned long long int ulli;

int main(void)
{
	ulli T, N, K, S, i, j, current_max, count, *array;
	scanf("%llu", &T);
	for(j = 0; j < T; j++)
	{
		count = 0;
		current_max = 0;
		scanf("%llu %llu %llu", &N, &K, &S);
		array = (ulli*)malloc(N*sizeof(ulli));
		array[0] = current_max = S;
		for (i = 1; i < N; ++i)
		{
    		array[i] = (1LL*array[i-1]*1103515245 + 12345) % (2147483648LL);
    		if(i % K != 0)
    		{
    			if(array[i] > current_max)
    			{
    				current_max = array[i];
    			}
    		}
    		else
    		{
    			count = count + current_max;
    			current_max = array[i];
    		}
    	}
    	free(array);
    	printf("%llu\n", count);
	}
	return 0;
}