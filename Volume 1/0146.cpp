#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

#include <cstdio>
using namespace std;

typedef struct
{
  int idx, dist, num;
} Store;

const double INF = 1e20;

int n, dist[16][16], weight[1 << 15];
pair<double, int> dp[1 << 15][16];

pair<double, int> solve(int S, int p)
{
  if (S == (1 << n)-1)
    return make_pair(0.0, -1);

  if (dp[S][p].first != INF)
    return dp[S][p];

  pair<double, int> res(INF, -1);
  for (int i = 0; i < n; ++i) {
    if (!(S & (1 << i))) {
      pair<double, int> tmp = solve(S | (1 << i), i);
      tmp.first += dist[p][i] / (2000.0 / (70.0+weight[S]));
      if (tmp.first < res.first) {
	res.first = tmp.first;
	res.second = i;
      }
    }
  }
  return dp[S][p] = res;
}

int main()
{
  while (cin >> n) {
    vector<Store> store(n);
    for (int i = 0; i < n; ++i)
      cin >> store[i].idx >> store[i].dist >> store[i].num;

    for (int i = 0; i < n; ++i) {
      for (int j = i+1; j < n; ++j)
	dist[i][j] = dist[j][i] = 60 * abs(store[i].dist-store[j].dist);
      dist[n][i] = 0;
    }

    for (int S = 0; S < (1 << n); ++S) {
      weight[S] = 0;
      for (int i = 0; i < n; ++i) {
	if (S & (1 << i))
	  weight[S] += store[i].num;
      }
      weight[S] *= 20;
    }

    for (int S = 0; S < (1 << n); ++S) {
      for (int i = 0; i <= n; ++i)
	dp[S][i].first = INF;
    }

    solve(0, n);

    int S = 0, p = n;
    vector<int> ans;
    while (S != (1 << n)-1) {
      int next = dp[S][p].second;
      S |= (1 << next);
      p = next;
      ans.push_back(store[next].idx);
    }

    for (int i = 0; i < ans.size()-1; ++i)
      cout << ans[i] << " ";
    cout << ans.back() << endl;
  }
  return 0;
}
