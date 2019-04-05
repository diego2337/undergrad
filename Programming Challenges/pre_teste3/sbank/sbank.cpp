#include <iostream>
#include <map>
using namespace std;

typedef struct 
{
	int control, bank, owner;
} bank;

int main(void)
{
	int t, n, i, j;
	map<bank, int> *accounts;
	bank aux;
	cin >> t;
	for(i = 0; i < t; i++)
	{
		cin >> n;
		accounts = new map<bank, int>[n];
		for(j = 0; j < n; j++)
		{
			cin >> aux.control;
			cin >> aux.bank;
			cin >> aux.owner;
			accounts[aux] = accounts[aux] + 1;
		}
		cout << endl;
	}
	return 0;
}