#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
  int dp[10+1][330+1];
  for (int i = 0; i < 10+1; ++i) {
    for (int j = 0; j < 330+1; ++j)
      dp[i][j] = 0;
  }

  int fac[10+1];
  fac[0] = fac[1] = 1;
  for (int i = 2; i < 10+1; ++i)
    fac[i] = i * fac[i-1];

  vector<int> num;
  for (int i = 0; i < 10; ++i)
    num.push_back(i);
  do {
    int sum = 0;
    for (int i = 0; i < 10; ++i) {
      sum += ((i+1) * num[i]);
      ++dp[i+1][sum];
    }
  } while (next_permutation(num.begin(), num.end()));

  int n, s;
  while (cin >> n >> s)
    if (n < 0 || 10 < n || s < 0 || 330 < s)
      cout << "0" << endl;
    else
      cout << dp[n][s] / fac[10-n] << endl;
  return 0;
}
