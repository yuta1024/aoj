#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1 << 30;

int main()
{
  int n, m, p, a, b;
  for ( ; ; ) {
    scanf("%d %d %d %d %d", &n, &m, &p, &a, &b);
    if (n == 0 && m == 0 && p == 0 && a == 0 && b == 0)
      break;

    vector<int> t(n);
    for (int i = 0; i < n; ++i)
      scanf("%d", &t[i]);

    vector<vector<int> > cost(m, vector<int>(m));
    for (unsigned int i = 0; i < cost.size(); ++i) {
      for (unsigned int j = 0; j < cost[i].size(); ++j) {
	cost[i][j] = INF;
      }
    }

    for (int i = 0; i < p; ++i) {
      int x, y, z;
      scanf("%d %d %d", &x, &y, &z);
      cost[x-1][y-1] = cost[y-1][x-1] = z;
    }

  }
  return 0;
}
