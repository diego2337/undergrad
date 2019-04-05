/* Implementação com Busca em largura + fila, com vetor de maiores caminhos */
#include <stdio.h>
#include <limits.h>
#include <queue>
#include <iostream>

#define MAX 100
#define DEBUG 0

using namespace std;

class pos {
public:
  int v;
  int d;
  pos(int v, int d) : v(v), d(d) {};
};

int longestpath(vector<int> graph[MAX+1], int n, int start, int &end);

int main(void)
{
  int cs = 1, n, start, end, len;
  int i, j;
  vector<int> graph[MAX+1];

  for (i = 0; i <= MAX; i++)
    graph[i].reserve(MAX);
  
  scanf("%d", &n);
  while (n != 0) {

    scanf("%d", &start);
    do {
      scanf("%d%d", &i, &j);
      graph[i].push_back(j);
    } while (i != 0 && j != 0);

    len = longestpath(graph, n, start, end);
    printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n", cs++, start, len, end);

    for (i = 0; i <= MAX; i++)
      graph[i].clear();
    
    scanf("%d", &n);
  }

  return 0;
}

int longestpath(vector<int> graph[MAX+1], int n, int start, int &end)
{
  queue<pos> q;
  int i;
  int max_len[MAX+1] = {0};

  q.push(pos(start, 0));
  while (!q.empty()) {
    pos &p = q.front();

    for (i = 0; i < (int) graph[p.v].size(); ++i)
      if (p.d + 1 > max_len[graph[p.v][i]]) {
        q.push(pos(graph[p.v][i], p.d + 1));
        max_len[graph[p.v][i]] = p.d + 1;
      }
   
    q.pop();
  }

  end = start;
  for (i = 1; i <= n; i++)
    if (max_len[i] > max_len[end])
      end = i;

  return max_len[end];
}
