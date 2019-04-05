#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* Check Gray Scale */
char cgs(int A, int B, int C, int D, int E)
{
	char i = '*';
	bool one_answer = false;
	if(A <= 127)
	{
		one_answer = true;
		i = 'A';
	}
	if(B <= 127)
	{
		if(one_answer == true)
			return '*';
		else
		{
			one_answer = true;
			i = 'B';
		}
	}
	if(C <= 127)
	{
		if(one_answer == true)
			return '*';
		else
		{
			one_answer = true;
			i = 'C';
		}
	}
	if(D <= 127)
	{
		if(one_answer == true)
			return '*';
		else
		{
			one_answer = true;
			i = 'D';
		}
	}
	if(E <= 127)
	{
		if(one_answer == true)
			return '*';
		else
		{
			one_answer = true;
			i = 'E';
		}
	}

	return i;
}

int main(void)
{
	int N, A, B, C, D, E, i;
	scanf("%d", &N);
	while(N != 0)
	{
		for(i = 0; i < N; i++)
		{
			scanf("%d %d %d %d %d", &A, &B, &C, &D, &E);
			printf("%c\n", cgs(A, B, C, D, E));
		}
		scanf("%d", &N);
	}
	return 0;
}