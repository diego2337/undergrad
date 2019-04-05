#include <stdio.h>
#include <limits.h>
#include <queue>
#include <iostream>

#define MAX 100000
#define DEBUG 0

using namespace std;

class pos {
public:
  int v;
  unsigned int d;
  pos(int v, unsigned int d) : v(v), d(d) {};
};

void shortest_path(int start, int *end, vector<vector<pos> > adjacency)
{
	queue<pos> q;
	int i;
	bool visited[MAX+1] = {false};
	q.push(adjacency[start][0]);
	visited[start] = true;
	while(!q.empty())
	{
		pos &p = q.front();
		for(i = 0; i < (int)adjacency[p.v].size(); i++)
		{
			if(!visited[adjacency[p.v][i].v])
			{
				q.push(pos(adjacency[p.v][i].v, (p.d+adjacency[p.v][i].d)));
				visited[adjacency[p.v][i].v] = true;
			}
		}
		if(p.v == *end)
		{
			cout << p.d << " ";
		}
		q.pop();
	}
}

int main(void)
{
	int n, q, a, i, start, end;
	unsigned int l;
	vector<vector<pos> > adjacency;
	scanf("%d", &n);
	while(n != 0)
	{
		adjacency.resize(n);
		for(i = 1; i <= n-1; i++)
		{
			scanf("%d %u", &a, &l);
			adjacency[i].push_back(pos(a, l));
			adjacency[a].push_back(pos(i, l));
		}
		scanf("%d", &q);
		for(i = 0; i < q; i++)
		{
			scanf("%d %d", &start, &end);
			shortest_path(start, &end, adjacency);
		}
		scanf("%d", &n);
	}
	return 0;
}