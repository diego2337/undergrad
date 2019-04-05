#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char check(int x, int y, int n, int m)
{
	if(x == n || x == m || y == n || y == m)
		return 'd';
	else
	{
		if(x < n && y > m)
			return '1';
		else if(x > n && y > m)
			return '2';
		else if(x < n && y < m)
			return '3';
		else if(x > n && y < m)
			return '4';
	}
}

int main(void)
{
	int k, n, m, i, x, y;
	char result;
	scanf("%d", &k);
	while(k != 0)
	{
		scanf("%d %d", &n, &m);
		for(i = 0; i < k; i++)
		{
			scanf("%d %d", &x, &y);
			result = check(x, y, n, m);	
			if(result == 'd')
				printf("divisa");
			else if(result == '1')
				printf("NO");
			else if(result == '2')
				printf("NE");
			else if(result == '3')
				printf("SO");
			else if(result == '4')
				printf("SE");
			printf("\n");
		}
		scanf("%d", &k);
	}
}