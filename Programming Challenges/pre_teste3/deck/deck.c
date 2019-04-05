#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int deck[200001], deck2[200001], i, j, k, l, n, m, count;
	scanf("%d", &n);
	m = 0;
	while(n != EOF)
	{

		for(i = 0; i < n; i++)
			deck[i] = i+1;
		count = 0;
		l = 0;
		m = 0;
		while(l != 1 && n != 0)
		{
			count++;
			k = 0;
			j = 0;
			switch(m)
			{
				case 0:
					for(i = 0; i < n; i++)
					{
						if(i % 2 == 0)
						{
							deck2[i] = deck[n/2+k];
							k++;
						}
						else if(i % 2 != 0)
						{
							deck2[i] = deck[0+j];
							j++;
						}
					}
					m = 1;
					break;
				case 1:
					for(i = 0; i < n; i++)
					{
						if(i % 2 == 0)
						{
							deck[i] = deck2[n/2+k];
							k++;
						}
						else if(i % 2 != 0)
						{
							deck[i] = deck2[0+j];
							j++;
						}
					}
					m = 0;
					break;
			}
			l = 1;
			for(i = 0; i < n; i++)
			{
				switch(m)
				{
					case 0:
						if(i+1 != deck[i])
							l = 0;
						break;
					case 1:
						if(i+1 != deck2[i])
							l = 0;
						break;
				}
			}
		}
		printf("%d\n", count);
		scanf("%d", &n);
	}
	return 0;
}