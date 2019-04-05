#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int highest_number_with_digits_of(int X)
{
	char c[5], b[5];
	int i, j, max, max_index, new_X = 0;
	for(i = 0; i < 4; i++)
	{
		if(X%10 == 0)
			c[i] = '0';
		else
			c[i] = (X % 10)+48;
		X = X / 10;
	}
	for(i = 0; i < 4; i++)
	{
		max = max_index = 0;
		for(j = 0; j < 4; j++)
		{
			if((c[j] - '0') > max)
			{
				max = (c[j] - '0');
				max_index = j;
			}
		}
		b[i] = c[max_index];
		c[max_index] = 0;
	}
	for(i = 0; i < 4; i++)
	{
		if((b[i]-'0') == -48)
		{
			new_X = 10*new_X;
		}
		else	
		{
			new_X = 10*new_X + (b[i]-'0');
		}
	}
	return new_X;
}

int lowest_number_with_digits_of(int X)
{
	char c[5], b[5];
	int i, j, max, max_index, new_X = 0;
	for(i = 0; i < 4; i++)
	{
		if(X%10 == 0)
			c[i] = '0';
		else
			c[i] = (X % 10)+48;
		X = X / 10;
	}
	for(i = 0; i < 4; i++)
	{
		max = max_index = 128;
		for(j = 0; j < 4; j++)
		{
			if((c[j] - '0') < max)
			{
				max = (c[j] - '0');
				max_index = j;
			}
		}
		b[i] = c[max_index];
		c[max_index] = '}';
	}
	for(i = 0; i < 4; i++)
	{
		if((b[i]-'0') == -48)
		{
			new_X = 10*new_X;
		}
		else	
		{
			new_X = 10*new_X + (b[i]-'0');
		}
	}
	return new_X;
}

int kaprekar(int X)
{
    int cnt = 0, hi, lo;
	while (X != 6174 && cnt < 10001) 
	{
	    hi = highest_number_with_digits_of(X);
        lo = lowest_number_with_digits_of(X);
	    X = hi - lo;
	    cnt = cnt + 1;
	}
	if(cnt == 10001)
		cnt = -1;
	return cnt;
}

int main(void)
{
	int x, n, i;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		scanf("%d", &x);
		printf("Caso #%d: ", i+1);
		printf("%d\n", kaprekar(x));
	}
	return 0;
}