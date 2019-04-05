/* Autor: Diego Silva Cintra 
   Data: 27/02/2015 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int n, runs, alphabet[26], chronos, correct, total_chronos, vector;
	char letter;
	char *judgement;
	judgement = (char*)malloc(10*sizeof(char));
	while(scanf("%d", &n) && n != 0)
	{
		for(vector = 0; vector < 26; vector++)
		{
			alphabet[vector] = 0;
		}
		correct = 0;
		total_chronos = 0;
		for(runs = 0; runs < n; runs++)
		{
			scanf(" %c", &letter);
			scanf(" %d", &chronos);
			scanf(" %s", judgement);
			if(strcmp(judgement, "incorrect") == 0)
				alphabet[letter-65] += 20;	
			else
			{
				correct++;
				total_chronos += chronos + alphabet[letter-65];
			}
		}
		printf("%d %d\n", correct, total_chronos);
	}
	return 0;
}