#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int INF = 1 << 30;

int dijkstra(const int s, const int t, const vector<vector<int> >& cost)
{
  priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > que;
  que.push(make_pair(0, s));
  vector<int> dp(cost.size(), INF);
  while (!que.empty()) {
    const pair<int, int> p = que.top();
    que.pop();

    if (p.second == t)
      return p.first;

    if (dp[p.second] < p.first)
      continue;
    dp[p.second] = p.first;

    for (int i = 0; i < cost.size(); ++i) {
      if (p.first+cost[p.second][i] < dp[i]) {
	dp[i] = p.first+cost[p.second][i];
	que.push(make_pair(dp[i], i));
      }
    }
  }
  return -1;
}

int main()
{
  int n, k;
  while (~scanf("%d %d", &n, &k)) {
    if ((n|k) == 0)
      break;

    vector<vector<int> > cost(n, vector<int>(n, INF));
    for (int i = 0; i < k; ++i) {
      int op;
      scanf("%d", &op);
      if (op == 0) {
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d\n", dijkstra(a-1, b-1, cost));
      } else {
	int c, d, e;
	scanf("%d %d %d", &c, &d, &e);
	cost[c-1][d-1] = min(cost[c-1][d-1], e);
	cost[d-1][c-1] = min(cost[d-1][c-1], e);
      }
    }
  }
  return 0;
}
