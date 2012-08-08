#include <cstdio>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

int main()
{
  const int INF = 1 << 30;

  int n, m;
  while (~scanf("%d", &n)) {
    if (n == 0)
      break;

    scanf("%d", &m);
    vector<vector<int> > edge(n, vector<int>(n, INF));
    for (int i = 0; i < m; ++i) {
      int a, b, d;
      scanf("%d,%d,%d", &a, &b, &d);
      d /= 100;
      edge[a][b] = edge[b][a] = d;
    }

    int ans = 0;
    vector<int> visited(n, 0);
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > que;
    que.push(pair<int, int>(1, 0));
    while (!que.empty()) {
      const pair<int, int> p = que.top();
      que.pop();

      if (visited[p.second])
	continue;

      visited[p.second] = 1;
      ans += p.first - 1;
      for (int i = 0; i < n; ++i) {
	if (visited[i] || edge[p.second][i] == INF)
	  continue;
	que.push(pair<int, int>(edge[p.second][i], i));
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
