#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <stdbool.h>
using namespace std;

int main(void)
{
	vector<unsigned long int> permuts;
	vector<unsigned long int>::iterator it;
	unsigned long int n, i, j, aux;
	bool exists;
	scanf("%lu", &n);
	while(n != 0)
	{
		permuts.clear();
		for(i = 0; i < n; i++)
		{
			exists = false;
			scanf("%lu", &aux);
			for(j = 0; j < permuts.size(); j++)
			{
				if(permuts[j] == aux)
					exists = true;
			}
			if(!exists)
				permuts.push_back(aux);
		}
		sort(permuts.begin(), permuts.end());
		do
		{
			for(i = 0; i < n; i++)
				printf("%lu ", permuts[i]);
			printf("\n");
		}while(next_permutation(permuts.begin(), permuts.end()));
		printf("\n");
		scanf("%lu", &n);
	}
	return 0;
}