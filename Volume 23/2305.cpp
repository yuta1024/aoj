#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
using namespace std;

const double INF = 1e30;

int main()
{
  int N;
  while (cin >> N) {
    vector<int> a(N);
    for (int i = 0; i < N; ++i)
      cin >> a[i];

    const int MAX = 200000;
    vector<vector<double> > dp(N, vector<double>(MAX, INF));
    for (int i = 1; i < MAX; ++i)
      dp[0][i] = abs(a[0] - i) / static_cast<double>(a[0]);

    for (int i = 1; i < N; ++i) {
      for (int j = 1; j < MAX; ++j) {
	for (int k = j; k < MAX; k += j) {
	  dp[i][k] = min(dp[i][k],
			   max(dp[i-1][j], abs(a[i] - k) / static_cast<double>(a[i])));
	}
      }
    }

    double ans = INF;
    for (int i = 0; i < MAX; ++i)
      ans = min(ans, dp[N-1][i]);
    printf("%.12f\n", ans);
  }
  return 0;
}
