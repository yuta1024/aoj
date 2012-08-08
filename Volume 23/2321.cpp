#include <iostream>
#include <cstring>
using namespace std;

int N, L[100], SE[100], dp[100][1 << 16];

int solve(int i, int bit)
{
  if (i >= N)
    return 0;

  if (dp[i][bit] != -1)
    return dp[i][bit];

  int ret = 0;
  if ((SE[i] & bit) == 0)
    ret = max(ret, solve(i+1, bit | SE[i]) + L[i]);
  ret = max(ret, solve(i+1, bit));
  return dp[i][bit] = ret;
}

int main()
{
  while (cin >> N) {
    if (N == 0)
      break;

    for (int i = 0; i < N; ++i) {
      int M;
      cin >> M >> L[i];

      SE[i] = 0;
      for (int j = 0; j < M; ++j) {
	int S, E;
	cin >> S >> E;
	for (int k = S-6; k < E-6; ++k)
	  SE[i] |= 1 << k;
      }
    }

    memset(dp, -1, sizeof(dp));
    cout << solve(0, 0) << endl;
  }
  return 0;
}
