#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  int n, a, b;
  while (cin >> n >> a >> b) {
    if ((n|a|b) == 0)
      break;

    vector<int> dp(n+1, 0);
    for (int i = 0; i <= n; i += a) {
      if (!dp[i]) {
	for (int j = i; j <= n; j += b)
	  dp[j] = 1;
      }
    }

    cout << count(dp.begin(), dp.end(), 0) << endl;
  }
  return 0;
}
