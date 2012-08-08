#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int n, m;
double dp[101][101];

double solve(int prev, int cnt, const vector<vector<double> >& manure)
{
  if (cnt >= m)
    return 1.0;

  if (dp[prev][cnt] != -1.0)
    return dp[prev][cnt];

  double res = 0.0;
  for (int i = 0; i < n; ++i)
    res = max(res, solve(i, cnt+1, manure) * manure[prev][i]);

  return dp[prev][cnt] = res;
}

int main()
{

  while (cin >> n >> m) {
    if ((n|m) == 0)
      break;

    vector<vector<double> > manure(n+1, vector<double>(n+1, 1.0));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j)
	cin >> manure[i][j];
    }

    for (int i = 0; i < 101; ++i) {
      for (int j = 0; j < 101; ++j)
	dp[i][j] = -1.0;
    }

    printf("%.2f\n", solve(n, 0, manure));
  }
  return 0;
}
