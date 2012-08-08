#include <cstdio>
#include <vector>
using namespace std;

int main()
{
  const int MAX_N = 100000;
  const int MAX_DEPTH = 20;

  vector<vector<double> > dp(MAX_N, vector<double>(MAX_DEPTH, 0.0));
  dp[0][1] = 1.0;
  for (int i = 1; i < MAX_N; ++i) {
    dp[i][1] += dp[i-1][0];
    for (int j = 2; j < MAX_DEPTH; ++j) {
      double p = 1.0 / (1 << (j-1));
      dp[i][j] += p * dp[i-1][j-1];
      dp[i][0] += (1.0 - p) * dp[i-1][j-1];
    }
  }

  for (int i = 1; i < MAX_N; ++i) {
    for (int j = MAX_DEPTH-1; j > 1; --j)
      dp[i][j-1] += dp[i][j];
    dp[i][1] += dp[i-1][1];
  }

  int n;
  while (~scanf("%d", &n)) {
    if (n == 0)
      break;
    printf("%.8f\n", dp[n-1][1]);
  }
  return 0;
}
