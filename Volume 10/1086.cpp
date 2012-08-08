#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int C, D, W, X, E[15+1][30+1], F[15+1][30+1], dp[30+1][50+1][5+1];

int solve(int d, int w, int x)
{
  if (d >= D)
    return 0;

  if (dp[d][w][x] != -1)
    return dp[d][w][x];

  int ret = solve(d+1, w, x);
  for (int i = 0; i < C; ++i) {
    if (E[i][d] != 0 && w+F[i][d] <= W) {
      ret = max(ret, solve(d+1, w+F[i][d], x)+E[i][d]);
      if (x+1 <= X) {
	int now_w = w+F[i][d], now_e = E[i][d];
	for (int j = i-1; j >= 0; --j) {
	  if (E[j][d] == 0 || now_w+F[j][d] > W)
	    break;
	  now_w += F[j][d];
	  now_e += E[j][d];
	  ret = max(ret, solve(d+1, now_w, x+1)+now_e);
	}

	now_w = w+F[i][d], now_e = E[i][d];
	for (int j = i+1; j < C; ++j) {
	  if (E[j][d] == 0 || now_w+F[j][d] > W)
	    break;
	  now_w += F[j][d];
	  now_e += E[j][d];
	  ret = max(ret, solve(d+1, now_w, x+1)+now_e);
	}
      }
    }
  }
  return dp[d][w][x] = ret;
}

int main()
{
  while (cin >> C >> D >> W >> X) {
    if ((C|D|W|X) == 0)
      break;

    for (int i = 0; i < C; ++i) {
      for (int j = 0; j < D; ++j)
	cin >> E[i][j];
    }

    for (int i = 0; i < C; ++i) {
      for (int j = 0; j < D; ++j)
	cin >> F[i][j];
    }

    memset(dp, -1, sizeof(dp));
    cout << solve(0, 0, 0) << endl;
  }
  return 0;
}
