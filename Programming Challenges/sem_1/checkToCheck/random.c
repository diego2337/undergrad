#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

int main(void)
{
	srand(time(NULL));
	char table[8][8] = {'.'};
	int p = 0, P = 0, n = 0, N = 0, b = 0, B = 0, r = 0, R = 0, q = 0, Q = 0, k = 0, K = 0, random0, random, random2;
	for(int cases = 0; cases < 1000; cases++)
	{
		p = 0;
		P = 0;
		n = 0;
		N = 0;
		b = 0;
		B = 0; 
		r = 0;
		R = 0;
		q = 0;
		Q = 0;
		k = 0;
		K = 0;
		for(int i = 0; i < 8; i++)
		{
			for(int j = 0; j < 8; j++)
			{	
				random0 = rand();
				random0 = random0 % 2;
				random = rand();
				random = random % 5;
				random2 = rand();
				random2 = random2 % 2;
				if(random0 == 1)
				{
					switch(random)
					{
						case 0:
							if(random2 == 0 && p < 8)
							{
								printf("p");
								p++;
							}
							else if(random2 == 1 && P < 8)
							{
								printf("P");
								P++;
							}
							else
							{
								printf(".");
							}
							break;
						case 1:
							if(random2 == 0 && n < 2)
							{
								printf("n");
								n++;
							}
							else if(random2 == 1 && N < 2)
							{
								printf("N");
								N++;
							}
							else
							{
								printf(".");
							}
							break;
						case 2:
							if(random2 == 0 && b < 2)
							{
								printf("b");
								b++;
							}
							else if(random2 == 1 && B < 2)
							{
								printf("B");
								B++;
							}
							else
							{
								printf(".");
							}
							break;
						case 3:
							if(random2 == 0 && q < 1)
							{
								printf("q");
								q++;
							}
							else if(random2 == 1 && Q < 1)
							{
								printf("Q");
								Q++;
							}
							else
							{
								printf(".");
							}
							break;
						case 4:
							if(random2 == 0 && k < 1)
							{
								printf("k");
								k++;
							}
							else if(random2 == 1 && K < 1)
							{
								printf("K");
								K++;
							}
							else
							{
								printf(".");
							}
							break;

					}
				}
				else
					printf(".");
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}