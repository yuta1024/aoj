#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 1 << 30;
const int MAX_HW = 32;
int h, w, s;
int cost[MAX_HW][MAX_HW][MAX_HW][MAX_HW];
pair<int, int> dp[MAX_HW][MAX_HW][MAX_HW][MAX_HW];

pair<int, int> solve(int x1, int y1, int x2, int y2, const int sum)
{
  if (dp[y1][x1][y2][x2].first != -1)
    return dp[y1][x1][y2][x2];

  pair<int, int> res(1, s-sum+cost[y1][x1][y2][x2]);
  for (int x = x1; x < x2; ++x) {
    if (cost[y1][x1][y2][x] < sum-s || cost[y1][x+1][y2][x2] < sum-s)
      continue;
    pair<int, int> g1 = solve(x1, y1, x, y2, sum);
    pair<int, int> g2 = solve(x+1, y1, x2, y2, sum);
    if (res.first < g1.first+g2.first) {
      res.first = g1.first+g2.first;
      res.second = min(g1.second, g2.second);
    } else if (res.first == g1.first+g2.first) {
      res.second = max(res.second, min(g1.second, g2.second));
    }
  }

  for (int y = y1; y < y2; ++y) {
    if (cost[y1][x1][y][x2] < sum-s || cost[y+1][x1][y2][x2] < sum-s)
      continue;
    pair<int, int> g1 = solve(x1, y1, x2, y, sum);
    pair<int, int> g2 = solve(x1, y+1, x2, y2, sum);
    if (res.first < g1.first+g2.first) {
      res.first = g1.first+g2.first;
      res.second = min(g1.second, g2.second);
    } else if (res.first == g1.first+g2.first) {
      res.second = max(res.second, min(g1.second, g2.second));
    }
  }
  return dp[y1][x1][y2][x2] = res;
}

int main()
{
  while (scanf("%d %d %d", &h, &w, &s)) {
    if ((h|w|s) == 0)
      break;

    int sum = 0;
    vector<vector<int> > u(h, vector<int>(w));
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
	scanf("%d", &u[i][j]);
	sum += u[i][j];
      }
    }

    memset(cost, 0, sizeof(cost));
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
	for (int y = i; y < h; ++y) {
	  for (int x = j; x < w; ++x)
	    cost[i][j][y][x] = u[y][x];
	}
      }
    }
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
	// hor
	for (int y = i; y < h; ++y) {
	  for (int x = j+1; x < w; ++x)
	    cost[i][j][y][x] += cost[i][j][y][x-1];
	}
	// ver
	for (int x = j; x < w; ++x) {
	  for (int y = i+1; y < h; ++y)
	    cost[i][j][y][x] += cost[i][j][y-1][x];
	}
      }
    }

    memset(dp, -1, sizeof(dp));
    pair<int, int> ans = solve(0, 0, w-1, h-1, sum);
    printf("%d %d\n", ans.first, ans.second);
  }
  return 0;
}
