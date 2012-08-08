#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
  int N, M;
  while (cin >> N >> M) {
    if (N == 0 && M == 0)
      break;

    vector<int> C(M);
    for (int i = 0; i < M; ++i)
      scanf("%d", &C[i]);

    vector<int> X(N);
    for (int i = 0; i < N; ++i)
      scanf("%d", &X[i]);

    const int INF = 1 << 30;
    static int dp[20000+1][256];
    for (int i = 0; i < 20000+1; ++i) {
      for (int j = 0; j < 256; ++j)
	dp[i][j] = INF;
    }
    dp[0][128] = 0;

    for (unsigned int i = 0; i < X.size(); ++i) {
      for (int j = 0; j < 256; ++j) {
	for (unsigned int k = 0; k < C.size(); ++k) {
	  int XX = j+C[k];
	  if (XX < 0)
	    XX = 0;
	  if (XX > 255)
	    XX = 255;
	  dp[i+1][XX] = min(dp[i+1][XX], dp[i][j] + (X[i]-XX)*(X[i]-XX));
	}
      }
    }

    int ans = INF;
    for (int i = 0; i < 256; ++i)
      ans = min(ans, dp[N][i]);

    cout << ans << endl;
  }
  return 0;
}
