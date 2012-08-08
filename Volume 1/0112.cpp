#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main()
{
  int n;
  while (cin >> n) {
    if (n == 0)
      break;

    vector<int> w(n);
    for (int i = 0; i < n; ++i)
      cin >> w[i];
    sort(w.begin(), w.end());

    vector<long long int> dp(n, 0);
    for (int i = 1; i < n; ++i)
      dp[i] = dp[i-1] + w[i-1];

    cout << accumulate(dp.begin(), dp.end(), 0LL) << endl;
  }
  return 0;
}
