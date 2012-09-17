#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstdio>
#include <numeric>
#include <bitset>
#include <stack>
#include <cstring>
using namespace std;

const int INF = 1 << 30;
const double EPS = 1e-10;

int main()
{
  int n, m;
  while (cin >> n >> m) {
    vector<int> x(n), y(n);
    set<int> sx, sy;
    for (int i = 0; i < n; ++i) {
      cin >> x[i] >> y[i];
      sx.insert(x[i]);
      sy.insert(y[i]);
    }

    vector<int> ix(1, -INF), iy(1, -INF);
    for (set<int>::iterator it = sx.begin(); it != sx.end(); ++it)
      ix.push_back(*it);
    for (set<int>::iterator it = sy.begin(); it != sy.end(); ++it)
      iy.push_back(*it);

    vector<vector<int> > dp(iy.size(), vector<int>(ix.size(), 0));
    for (int i = 0; i < n; ++i)
      ++dp[lower_bound(iy.begin(), iy.end(), y[i])-iy.begin()][lower_bound(ix.begin(), ix.end(), x[i])-ix.begin()];

    for (unsigned int i = 0; i < dp.size(); ++i) {
      for (unsigned int j = 1; j < dp[i].size(); ++j)
        dp[i][j] += dp[i][j-1];
    }

    for (unsigned int i = 0; i < dp[0].size(); ++i) {
      for (unsigned int j = 1; j < dp.size(); ++j)
        dp[j][i] += dp[j-1][i];
    }

    while (m--) {
      int x1, y1, x2, y2;
      cin >> x1 >> y1 >> x2 >> y2;

      int ix1 = upper_bound(ix.begin(), ix.end(), x2)-1-ix.begin();
      int iy1 = upper_bound(iy.begin(), iy.end(), y2)-1-iy.begin();

      int ix2 = upper_bound(ix.begin(), ix.end(), x1-1)-1-ix.begin();
      int iy2 = upper_bound(iy.begin(), iy.end(), y1-1)-1-iy.begin();

      int ix3 = upper_bound(ix.begin(), ix.end(), x1-1)-1-ix.begin();
      int iy3 = upper_bound(iy.begin(), iy.end(), y2)-1-iy.begin();

      int ix4 = upper_bound(ix.begin(), ix.end(), x2)-1-ix.begin();
      int iy4 = upper_bound(iy.begin(), iy.end(), y1-1)-1-iy.begin();

      cout << dp[max(0, iy1)][max(0, ix1)] + dp[max(0, iy2)][max(0, ix2)] - dp[max(0, iy3)][max(0, ix3)] - dp[max(0, iy4)][max(0, ix4)] << endl;
    }
  }
  return 0;
}
