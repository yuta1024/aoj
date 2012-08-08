#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
  int n;
  while (cin >> n) {
    if (n == 0)
      break;

    vector<string> field(n);
    for (int i = 0; i < n; ++i)
      cin >> field[i];

    vector<vector<int> > dp(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
      if (field[i][0] == '.')
	dp[i][0] = 1;
      else
	dp[i][0] = 0;
      if (field[0][i] == '.')
	dp[0][i] = 1;
      else
	dp[0][i] = 0;
    }

    int ans = 0;
    for (int i = 1; i < n; ++i) {
      for (int j = 1; j < n; ++j) {
	if (field[i][j] == '*')
	  continue;
	dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]))+1;
	ans = max(ans, dp[i][j]);
      }
    }
    cout << ans << endl;
  }
  return 0;
}
