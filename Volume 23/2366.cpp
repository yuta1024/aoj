#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
  const int INF = 1 << 30;

  int n, m, W;
  while (~scanf("%d %d %d", &n, &m, &W)) {
    vector<int> w, floor(n, 0);
    int top = 0, cnt = 0;
    for (int i = 0; i < n; ++i) {
      int k;
      scanf("%d", &k);
      for (int j = 0; j < k; ++j) {
	int tmp;
	scanf("%d", &tmp);
	w.push_back(tmp);
	floor[i] |= 1 << cnt;
	++cnt;
	top = i;
      }
    }

    if (floor[0] == (1 << cnt)-1) {
      puts("0");
      continue;
    }

    vector<int> sum(1 << cnt, 0);
    for (int S = 0; S < (1 << cnt); ++S) {
      for (int i = 0; i < cnt; ++i) {
	if (S & (1 << i))
	  sum[S] += w[i];
      }
    }

    vector<int> dp(1 << cnt, INF);
    dp[0] = 0;
    for (int S = 0; S < (1 << cnt); ++S) {
      for (int T = S; T != 0; T = (T-1)&S) {
	if (sum[T] <= W)
	  dp[S] = min(dp[S], dp[S^T]+1);
      }
    }

    --m;
    int ans = abs(top - m);
    for (int i = top; i > 0; --i) {
      ans += 2 * dp[floor[i]] - 1;
      floor[i-1] |= floor[i];
    }
    printf("%d\n", ans);
  }
  return 0;
}
