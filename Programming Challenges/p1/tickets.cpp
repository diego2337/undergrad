#include <iostream>
#include <map>
#include <stdio.h>
using namespace std;

int main(void)
{
	map<int, int> tickets;
	int N, M, num, count;
	scanf("%d %d", &N, &M);
	while(N != 0 && M != 0)
	{
		tickets.clear();
		count = 0;
		for(int i = 0; i < M; i++)
		{
			scanf("%d", &num);
			if(tickets[num] < 1)
				tickets[num]++;
			else if(tickets[num] != 2)
			{
				count++;
				tickets[num] = 2;
			}
		}
		cout << count << endl;
		scanf("%d %d", &N, &M);
	}
	return 0;
}