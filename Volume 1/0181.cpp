#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int INF = 1 << 30;

int dp[100][20];

int solve(int s, int p, const int m, const vector<int>& books)
{
  if (s >= books.size())
    return 0;

  if (p >= m) {
    int sum = 0;
    for (int i = s; i < books.size(); ++i)
      sum += books[i];
    return sum;
  }

  if (dp[s][p] != -1)
    return dp[s][p];

  int res = INF, sum = 0;
  for (int i = s; i < books.size(); ++i) {
    sum += books[i];
    res = min(res, max(sum, solve(i+1, p+1, m, books)));
  }
  return dp[s][p] = res;
}

int main()
{
  int n, m;
  while (cin >> m >> n) {
    if ((n|m) == 0)
      break;

    vector<int> books(n);
    for (int i = 0; i < n; ++i)
      cin >> books[i];

    memset(dp, -1, sizeof(dp));
    cout << solve(0, 0, m-1, books) << endl;
  }
  return 0;
}
