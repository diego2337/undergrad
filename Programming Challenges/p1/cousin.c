#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int josephus(int n, int k[3502], int index)
{
	if(n == 1)
		return 1;
	else
		return (josephus(n-1, k, index+1) + k[index]-1) % n+1;
}

int main(void)
{
	int primes[3502], people, pos[3502], prime, i, rnd, count, death_count;
	scanf("%d", &people);
	while(people != 0)
	{
		death_count = 0;
		primes[0] = 2;
		primes[1] = 3;
		primes[2] = 5;
		primes[3] = 7;
		prime = 11;
		pos[0] = 0;
		pos[1] = 0;
		pos[2] = 0;
		pos[3] = 0;
		for(i = 4; i < people; i++)
		{
			while(prime % 2 == 0 || prime % 3 == 0 || prime % 5 == 0 || prime % 7 == 0)
				prime++;
			primes[i] = prime;
			pos[i] = 0;
			prime++;
		}
		/*i = 0;
		rnd = 0;
		while(death_count < people-1)
		{
			count = 1;
			while(count != primes[i])
			{
				rnd = (rnd+1) % (people);
				if(pos[rnd] == 0)
				{
					count++;
				}
			}
			pos[rnd] = 1;
			rnd = (rnd+1) % (people);
			while(pos[rnd] == 1)
			{
				rnd = (rnd+1) % (people);
			}
			i++;
			death_count++;
		}
		for(i = 0; i < people; i++)
		{
			if(pos[i] == 0)
			{
				printf("%d", i+1);
				printf("\n");
				break;
			}
		}*/
		printf("%d", josephus(people, primes, 0));
		printf("\n");
		scanf("%d", &people);
	}
	return 0;
}