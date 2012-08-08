#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1 << 30;

typedef struct
{
  int h, r;
} Doll;

int solve(int prev, vector<int>& used, const vector<Doll>& doll, vector<int>& dp)
{
  if (dp[prev] != -1)
    return dp[prev];

  int ret = 0;
  for (int i = 0; i < doll.size(); ++i) {
    if (!used[i] && doll[prev].h > doll[i].h && doll[prev].r > doll[i].r) {
      used[i] = 1;
      ret = max(ret, solve(i, used, doll, dp)+1);
      used[i] = 0;
    }
  }
  return dp[prev] = ret;
}

int main()
{
  int n;
  while (cin >> n) {
    if (n == 0)
      break;

    vector<Doll> doll;
    for (int i = 0; i < n; ++i) {
      int h, r;
      cin >> h >> r;
      doll.push_back((Doll){h, r});
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
      int h, r;
      cin >> h >> r;
      doll.push_back((Doll){h, r});
    }

    doll.push_back((Doll){INF, INF});
    vector<int> used(n+m+1, 0);
    vector<int> dp(n+m+1, -1);
    cout << solve(n+m, used, doll, dp) << endl;
  }
  return 0;
}
