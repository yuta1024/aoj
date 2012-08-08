#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  const int INF = 1 << 28;

  int N, M;
  while (~scanf("%d %d\n", &N, &M)) {
    if (N == 0 && M == 0)
      break;

    vector<vector<int> > land(N, vector<int>(N, INF)), sea(N, vector<int>(N, INF));
    for (int i = 0; i < N; ++i)
      land[i][i] = sea[i][i] = 0;

    for (int i = 0; i < M; ++i) {
      int x, y, t;
      char s;
      scanf("%d %d %d %c\n", &x, &y, &t, &s);
      --x;
      --y;
      if (s == 'L')
	land[x][y] = land[y][x] = min(land[x][y], t);
      else
	sea[x][y] = sea[y][x] = min(sea[x][y], t); 
    }

    for (int k = 0; k < N; ++k) {
      for (int i = 0; i < N; ++i) {
	for (int j = 0; j < N; ++j) {
	  land[i][j] = min(land[i][j], land[i][k]+land[k][j]);
	  sea[i][j] = min(sea[i][j], sea[i][k]+sea[k][j]);
	}
      }
    }
    
    int R, z1, z2;
    scanf("%d\n", &R);
    scanf("%d", &z1);
    --z1;
    vector<vector<int> > dp(R, vector<int>(N, INF));
    dp[0][z1] = 0;
    for (int i = 0; i < R-1; ++i) {
      scanf("%d", &z2);
      --z2;
      for (int j = 0; j < N; ++j) {
	dp[i+1][j] = min(dp[i+1][j], dp[i][j]+land[z1][z2]);
	for (int k = 0; k < N; ++k) {
	  dp[i+1][k] = min(dp[i+1][k], dp[i][j]+land[z1][j]+sea[j][k]+land[k][z2]);
	}
      }
      z1 = z2;
    }

    int ans = INF;
    for (int i = 0; i < N; ++i)
      ans = min(ans, dp[R-1][i]);
    printf("%d\n", ans);
  }
  return 0;
}
