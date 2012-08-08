#include <cstdio>
#include <algorithm>

const int INF = 1 << 30;

int gram;
int memo[30][30][30];

int solve(int A, int B, int C)
{
  if (memo[A][B][C] != -1)
    return memo[A][B][C];
  else if (A*200 + B*300 + C*500 > gram)
    return INF;
  else if (A*200 + B*300 + C*500 == gram)
    return A/5*1520 + (A%5)*380 + B/4*1870 + (B%4)*550 + C/3*2244 + (C%3)*850;

  int ret = std::min(solve(A+1, B, C), std::min(solve(A, B+1, C), solve(A, B, C+1)));
  return memo[A][B][C] = ret;
}

int main()
{
  while (~scanf("%d", &gram)) {
    if (gram == 0)
      break;

    for (int i = 0; i < 30; ++i) {
      for (int j = 0; j < 30; ++j) {
	for (int k = 0; k < 30; ++k)
	  memo[i][j][k] = -1;
      }
    }
    printf("%d\n", solve(0, 0, 0));
  }
  return 0;
}
