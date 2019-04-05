#include <stdio.h>

int main(void)
{
	char hand1[20], hand2[20];
	int i, j;
	for(i = 0; i < 5; i++)
	{
		for(j = 0; j < 20; j++)
		{
			scanf("%c %c", &hand1[j], &hand1[j+1]);
			scanf("%c %c", &hand2[j], &hand2[j+1]);
		}
	}
	for(j = 0; j < 20; j++)
	{
		printf("%c %c ", hand1[j], hand1[j+1]);
		printf("%c %c", hand2[j], hand2[j+1]);
	}
	return 0;
}