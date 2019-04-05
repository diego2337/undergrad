#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

int main(void)
{
	int n, m, i, j, k, v, count, elements[1000000], printed;
	vector<list<int> > indexes;
	vector<int>::iterator it;
	while(scanf("%d", &n) != EOF)
	{
		scanf("%d", &m);
		for(i = 0; i < n; i++)
		{
			scanf("%d", &elements[i]);
			it = find(indexes.begin(), indexes.end(), elements[i]);
			if(it == indexes.end())
			{
				indexes.push_back(elements[i]);
				indexes[elements[i]].push_back(i+1);
			}
			else
			{
				int pos = it - indexes.begin();
				indexes[pos].push_back(i+1);
			}
		}
		for(i = 0; i < m; i++)
		{
			scanf("%d %d", &k, &v);
			count = 1;
			printed = 0;
			for(j = 0; j < n; j++)
			{
				if(elements[j] == v)
				{
					if(count == k)
					{
						printf("%d\n", j+1);
						printed = 1;
						j = n + 10;
					}
					else
						count++;
				}
			}
			if(printed == 0)
				printf("0\n");
		}
	}
	return 0;
}