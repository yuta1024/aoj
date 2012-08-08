#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX_N = 100;
const int INF = 1 << 29;

int main()
{
  int n, m, s, g1, g2;
  while (scanf("%d %d %d %d %d", &n, &m, &s, &g1, &g2) != EOF) {
    if (n == 0 && m == 0 && s == 0 && g1 == 0 && g2 == 0)
      break;
    --s;
    --g1;
    --g2;

    int cost[MAX_N][MAX_N];
    for (int i = 0; i < MAX_N; ++i) {
      for (int j = 0; j < MAX_N; ++j) {
	if (i == j)
	  cost[i][j] = 0;
	else
	  cost[i][j] = INF;
      }
    }

    for (int i = 0; i < m; ++i) {
      int b1, b2, c;
      scanf("%d %d %d", &b1, &b2, &c);
      --b1;
      --b2;
      cost[b1][b2] = c;
    }

    for (int k = 0; k < n; ++k)
      for (int i = 0; i < n; ++i)
	for (int j = 0; j < n; ++j)
	  cost[i][j] = min(cost[i][j], cost[i][k]+cost[k][j]);

    int ans = INF;
    for (int i = 0; i < n; ++i)
      ans = min(ans, cost[s][i]+cost[i][g1]+cost[i][g2]);

    printf("%d\n", ans);
  }
  return 0;
}
