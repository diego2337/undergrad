#include <iostream>
#include <list>
using namespace std;

int blackout(int m, int N)
{
	list<int> regions;
	for(int i = 1; i <= N; i++)
	{
		regions.push_back(i);
	}
	while(regions.size() > 1)
	{
		regions.pop_front();
		for(int i = 1; i < m; i++)
		{
			regions.push_back(regions.front());
			regions.pop_front();
		}
	}
	return regions.front();
}

int main(void)
{
	int N, m, region;
	cin >> N;
	while(N != 0)
	{
		m = 1;
		while(1)
		{
			region = blackout(m, N);
			if(region == 13)
				break;
			m++;
		}
		cout << m << endl;
		cin >> N;
	}
	return 0;	
}