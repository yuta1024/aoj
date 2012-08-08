#include <iostream>
#include <vector>
using namespace std;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int solve(int x, int y, vector<vector<int> >& ice, const int m, const int n)
{
  int ret = 0;
  ice[y][x] = 0;
  for (int d = 0; d < 4; ++d) {
    int xx = x + dx[d];
    int yy = y + dy[d];
    if (xx < 0 || m <= xx || yy < 0 || n <= yy || ice[yy][xx] == 0)
      continue;
    ret = max(ret, solve(xx, yy, ice, m, n));
  }
  ice[y][x] = 1;
  return ret+1;
}

int main()
{
  int m, n;
  while (cin >> m >> n) {
    if ((m|n) == 0)
      break;

    vector<vector<int> > ice(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j)
        cin >> ice[i][j];
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (ice[i][j] == 1)
          ans = max(ans, solve(j, i, ice, m, n));
      }
    }

    cout << ans << endl;
  }
  return 0;
}
