#include <iostream>
#include <iomanip>
#include <map>
#include <string>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main(void)
{
	map<string, float> precos;
	int test_cases, prices, amounts, a2;
	float p2, total;
	string p;
	cin >> test_cases;
	for(int i = 0; i < test_cases; i++)
	{
		cin >> prices;
		total = 0;
		precos.clear();
		for(int j = 0; j < prices; j++)
		{
			cin >> p;
			cin >> p2;
			precos.insert(pair<string, float>(p, p2));
		}
		cin >> amounts;
		for(int j = 0; j < amounts; j++)
		{
			cin >> p;
			cin >> a2;
			total = total + (precos[p] * a2);
		}
		setprecision(2);
		cout << "R$ " << total << endl;
	}
	return 0;
}