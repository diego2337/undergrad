#include <iostream>
#include <list>
using namespace std;

int hashing(int element, int M)
{
	return element % M;
}

int main(void)
{
	list<int> hash[100];
	int test_cases, M, C, element, k;
	cin >> test_cases;
	for(k = 0; k < test_cases; k++)
	{
		cin >> M >> C;
		for(int j = 0; j < M; j++)
			hash[j].clear();
		for(int j = 0; j < C; j++)
		{
			cin >> element;
			hash[hashing(element, M)].push_back(element);
		}
		for(int i = 0; i < M; i++)
		{
			cout << i << " -> ";
			for(list<int>::iterator it = hash[i].begin(); it != hash[i].end(); it++)
			{
				cout << *it << " -> ";
			}
			cout << "\\" << endl;
		}
		if(k+1 != test_cases)
			cout << endl;
	}
	return 0;
}