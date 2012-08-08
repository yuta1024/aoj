#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
  int cnt = 0, W, N;
  static int v[1000], w[1000], dp[1000+1][1000+1];
  while (~scanf("%d\n", &W)) {
    if (W == 0)
      break;

    for (int i = 0; i < 1001; ++i) {
      for (int j = 0; j < 1001; ++j)
	dp[i][j] = 0;
    }

    scanf("%d\n", &N);
    for (int i = 0; i < N; ++i)
      scanf("%d,%d\n", &v[i], &w[i]);

    int maxV = -1, minW = 1 << 30;
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j <= W; ++j) {
	if (j < w[i])
	  dp[i+1][j] = dp[i][j];
	else
	  dp[i+1][j] = max(dp[i][j], dp[i][j-w[i]]+v[i]);
	if (maxV < dp[i+1][j]) {
	  maxV = dp[i+1][j];
	  minW = j;
	} else if (maxV == dp[i+1][j]) {
	  minW = min(minW, j);
	}
      }
    }

    ++cnt;
    printf("Case %d:\n%d\n%d\n", cnt, maxV, minW);
  }
  return 0;
}
