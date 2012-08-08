#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  const int INF = 1 << 28;

  int n;
  while (~scanf("%d", &n)) {
    int m;
    scanf("%d", &m);

    vector<vector<int> > cost(n, vector<int>(n, INF));
    for (int i = 0; i < m; ++i) {
      int a1, b1, c1, d1;
      scanf("%d,%d,%d,%d", &a1, &b1, &c1, &d1);
      --a1;
      --b1;
      cost[a1][b1] = c1;
      cost[b1][a1] = d1;
    }

    for (int k = 0; k < n; ++k) {
      for (int i = 0; i < n; ++i) {
	for (int j = 0; j < n; ++j)
	  cost[i][j] = min(cost[i][j], cost[i][k]+cost[k][j]);
      }
    }

    int x1, x2, y1, y2;
    scanf("%d,%d,%d,%d", &x1, &x2, &y1, &y2);

    printf("%d\n", y1-y2-cost[x1-1][x2-1]-cost[x2-1][x1-1]);

  }
  return 0;
}
