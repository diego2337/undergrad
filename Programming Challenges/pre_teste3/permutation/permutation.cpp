#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;

int main(void)
{
	vector<char> permuts;
	int n, i, j, k;
	char c;
	scanf("%d", &n);
	c = getchar();
	for(i = 0; i < n; i++)
	{
		permuts.clear();
		j = 0;
		c = getchar();
		while(c != '\n' && c != EOF)
		{
			permuts.push_back(c);
			j++;
			c = getchar();
		}
		sort(permuts.begin(), permuts.end());
		do
		{
			for(k = 0; k < j; k++)
				printf("%c", permuts[k]);
			printf("\n");
		}while(next_permutation(permuts.begin(), permuts.end()));
		printf("\n");
	}
	return 0;
}