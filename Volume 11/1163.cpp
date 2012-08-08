#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX_V = 1000;

int match[MAX_V];
bool used[MAX_V];
vector<int> G[MAX_V];

void add_edge(int u, int v)
{
  G[u].push_back(v);
  G[v].push_back(u);
}

bool dfs(int v)
{
  used[v] = true;
  for (int i = 0; i < G[v].size(); ++i) {
    int u = G[v][i], w = match[u];
    if (w < 0 || !used[w] && dfs(w)) {
      match[v] = u;
      match[u] = v;
      return true;
    }
  }
  return false;
}

int bipartite_matching(int V)
{
  int res = 0;
  memset(match, -1, sizeof(match));
  for (int v = 0; v < V; ++v) {
    if (match[v] < 0) {
      memset(used, 0, sizeof(used));
      if (dfs(v))
	++res;
    }
  }
  return res;
}

int main()
{
  int m, n;
  while (~scanf("%d %d", &m, &n)) {
    if ((m|n) == 0)
      break;

    for (int i = 0; i < MAX_V; ++i)
      G[i].clear();

    vector<int> b(m), r(n);
    for (int i = 0; i < m; ++i)
      scanf("%d", &b[i]);
    for (int i = 0; i < n; ++i)
      scanf("%d", &r[i]);

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
	if (__gcd(b[i], r[j]) != 1)
	  add_edge(i, m+j);
      }
    }

    printf("%d\n", bipartite_matching(n+m));
  }
  return 0;
}
