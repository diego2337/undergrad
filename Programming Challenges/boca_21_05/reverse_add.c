#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int palindrome(unsigned long int num)
{
	unsigned long int the_mun = 0, aux = num;
	int i = 0;
	while(num > 0)
	{
		the_mun = the_mun * 10 + (num % 10);
		num = num / 10;
		i++;
	}
	if(the_mun==aux)
		return 1;
	else
		return 0;	
}

unsigned long int reverse(unsigned long int num)
{
	unsigned long int the_mun = 0;
	int i = 0;
	while(num > 0)
	{
		the_mun = the_mun * 10 + (num % 10);
		num = num / 10;
		i++;
	}
	return the_mun;
}

int main(void)
{
	int test_cases, i, count;
	unsigned long int num, mun;
	scanf("%d", &test_cases);
	for(i = 0; i < test_cases; i++)
	{
		count = 1;
		scanf("%lu", &num);
		mun = reverse(num);
		num = num+mun;
		while(!palindrome(num))
		{
			count++;
			mun = reverse(num);
			num = num+mun;
		}
		printf("%d %lu", count, num);
		if(i != test_cases-1);
			printf("\n");
	}
	return 0;
}