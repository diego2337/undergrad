#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int n, students[101], i, j, num, max;
	scanf("%d", &n);
	while(n != 0)
	{
		for(i = 0; i < n; i++)
			students[i] = 0;
		max = 0;
		for(i = 0; i < n; i++)
		{
			for(j = 0; j < n; j++)
			{
				scanf("%d", &num);
				if(num == 1)
				{
					students[j] = students[j] + 1;
					if(students[j] > max)
						max = students[j];
				}
			}
		}
		printf("%d\n", max);
		scanf("%d", &n);
	}
	return 0;
}