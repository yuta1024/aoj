#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1 << 28;

int main()
{
  int n;
  while (cin >> n) {
    vector<vector<int> > dp(n, vector<int>(n, INF));
    for (int i = 0; i < n; ++i) {
      int r, k;
      cin >> r >> k;
      --r;
      for (int j = 0; j < k; ++j) {
	int t;
	cin >> t;
	--t;
	dp[r][t] = 1;
      }
    }

    for (int k = 0; k < n; ++k) {
      for (int i = 0; i < n; ++i) {
	for (int j = 0; j < n; ++j)
	  dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]);
      }
    }

    int p;
    cin >> p;
    while (p--) {
      int s, d, v;
      cin >> s >> d >> v;
      --s;
      --d;
      if (dp[s][d] < v)
	cout << dp[s][d]+1 << endl;
      else
	cout << "NA" << endl;
    }
  }
  return 0;
}
