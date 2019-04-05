#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int P, S, T1, T2, T3, N, D1, D2, i, miss[11], pos[11];
	scanf("%d %d", &P, &S);
	while(P != 0 && S != 0)
	{
		for(i = 0; i < 11; i++)
		{
			miss[i] = 0;
			pos[i] = 0;
		}
		scanf("%d %d %d", &T1, &T2, &T3);
		scanf("%d", &N);
		for(i = 0; i < N; i++)
		{
			scanf("%d %d", &D1, &D2);
			if(miss[i%P] == 0)
			{
				pos[i%P] = pos[i%P] + D1 + D2;
				printf("After: %d\n", pos[i%P]);
				if(pos[i%P] > S)
				{
					printf("%d\n", (i)%P);
					i = N + 10;
				}
				else if(pos[i%P] == T1 || pos[i%P] == T2 || pos[i%P] == T3)
				{
					miss[i%P] = 1;
				}
			}
			else
			{
				miss[i%P] = 0;
				pos[(i+1)%P] = pos[(i+1)%P] + D1 + D2;
				printf("After: %d\n", pos[(i+1)%P]);
				if(pos[(i+1)%P] > S)
				{
					printf("%d\n", (i+1)%P);
					i = N + 10;
				}
				else if(pos[(i+1)%P] == T1 || pos[(i+1)%P] == T2 || pos[(i+1)%P] == T3)
				{
					miss[(i+1)%P] = 1;
				}
			}
		}
		scanf("%d %d", &P, &S);
	}
	return 0;
}