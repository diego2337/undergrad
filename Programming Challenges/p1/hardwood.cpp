#include <iostream>
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

using namespace std;

int main(void)
{
	int N, total_trees;
	char c;
	string tree;
	map<string, int> trees;
	scanf("%d", &N);
	scanf("\n");
	for(int i = 0; i < N; i++)
	{
		c = getchar();
		trees.clear();
		total_trees = 0;
		while(c != '\n' && c != EOF)
		{
			tree.clear();
			while(!isalpha(c))
			{
				c = getchar();
			}
			tree.append(1, c);
			c = getchar();
			while(c != '\n')
			{
				tree.append(1, c);
				c = getchar();
			}
			trees[tree] = trees[tree] + 1;
			total_trees = total_trees + 1;
			c = getchar();
		}
		for(map<string, int>::iterator it = trees.begin(); it != trees.end(); it++)
		{
			double percentage = it->second * 100.0000 / total_trees;
			percentage = percentage * 10000;
			percentage = round(percentage);
			percentage = percentage / 10000;
			cout << it->first << " ";
			printf("%.4f", percentage);
			printf("\n");
		}
		if(i+1 != N)
			printf("\n");
	}
	return 0;
}