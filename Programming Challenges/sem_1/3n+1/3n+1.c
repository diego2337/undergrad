/* Autor: Diego Silva Cintra 
   Data: 27/02/2015 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n(int num, int *count)
{
	*count = *count + 1;
	if(num == 1)
	{
		return num;
	}
	else
	{
		if(num % 2 != 0)
		{
			num = n(num*3+1, count);
		}
		else
		{
			num = n(num/2, count);
		}
	}
}

int main(void)
{
	int i, j, n1, n2, i_original, result1;
	while(scanf("%d %d", &i, &j) != EOF)
	{
		i_original = i;
		n1 = 0;
		for(i; i <= j; i++)
		{
			n2 = 0;
			result1 = n(i, &n2);
			if(n1 == 0 || n1 < n2)
			{
				n1 = n2;
			}
		}
		printf("%d %d %d\n", i_original, j, n1);
	}
	return 0;

}