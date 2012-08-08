#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

double dp[16][9];

double solve(int n, int p, const int t, const int b)
{
  if (n == 0) {
    if (p == t)
      return 1.0;
    return 0.0;
  }

  if (dp[n][p] != -1.0)
    return dp[n][p];

  double res = 0.0;
  // north
  if (p > 2 && p-3 != b)
    res += 0.25 * solve(n-1, p-3, t, b);
  else
    res += 0.25 * solve(n-1, p, t, b);

  // east
  if (p%3 != 2 && p+1 != b)
    res += 0.25 * solve(n-1, p+1, t, b);
  else
    res += 0.25 * solve(n-1, p, t, b);

  // south
  if (p < 6 && p+3 != b)
    res += 0.25 * solve(n-1, p+3, t, b);
  else
    res += 0.25 * solve(n-1, p, t, b);

  // west
  if (p%3 != 0 && p-1 != b)
    res += 0.25 * solve(n-1, p-1, t, b);
  else
    res += 0.25 * solve(n-1, p, t, b);

  return dp[n][p] = res;
}

int main()
{
  int n;
  while (cin >> n) {
    if (n == 0)
      break;

    for (int i = 0; i < 16; ++i) {
      for (int j = 0; j < 9; ++j)
	dp[i][j] = -1.0;
    }

    char s, t, b;
    cin >> s >> t >> b;
    printf("%.8f\n", solve(n, s-'A', t-'A', b-'A'));
  }
  return 0;
}
