#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
	int N, max = 0, max_index = 0, i, alphabet[26] = {0};
	char c;
	scanf("%d", &N);
	scanf("\n");
	c = getchar();
	for(i = 0; i < N; i++)
	{
		while(c != '\n')
		{
			if(isalpha(c))
			{
				alphabet[tolower(c)-97] = alphabet[tolower(c)-97] + 1;
				if(alphabet[tolower(c)-97] > max)
				{
					max_index = tolower(c)-97;
					max = alphabet[tolower(c)-97];
				}
			}
			c = getchar();
		}
		c = getchar();
	}
	while(max != 0)
	{
		printf("%c %d\n", max_index+65, alphabet[max_index]);
		alphabet[max_index] = -1;
		max = 0;
		max_index = 0;
		for(i = 0; i < 26; i++)
		{
			if(alphabet[i] > max)
			{
				max_index = i;
				max = alphabet[i];
			}
		}
	}
	return 0;
}