#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(void)
{
	int N, M, i, j, k, l, count, rest[5];
	bool repeated;
	while(scanf("%d %d", &N, &M) != EOF)
	{
		count = 0;
		for(i = N; i <= M; i++)
		{
			for(j = 0; j < 5; j++)
				rest[j] = 0;
			j = i;
			repeated = false;
			k = 0;
			while(j > 0)
			{
				for(l = 0; l < k; l++)
				{
					if(j % 10 == rest[l])
					{
						repeated = true;
						j = 0;
						break;
					}
				}
				if(!repeated)
				{
					rest[k] = j % 10;
					k++;
					j = j / 10;
				}
			}
			if(!repeated)
			{
				count = count + 1;
			}
		}
		printf("%d\n", count);
	}
	return 0;
}