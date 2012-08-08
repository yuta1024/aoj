#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1 << 30;

typedef struct
{
  int c, r;
} Subject;

int n, U;
Subject sub[20];
int memo[1 << 20];

int solve(int bit, int cnt)
{
  if (memo[bit] != -1)
    return memo[bit];

  if (cnt >= U) {
    memo[bit] = __builtin_popcount(bit);
    return memo[bit];
  }

  int ret = INF;
  for (int i = 0; i < n; ++i) {
    if (!(bit & (1 << i)) && (sub[i].r & bit) == sub[i].r)
      ret = min(ret, solve(bit | (1 << i), cnt+sub[i].c));
  }
  memo[bit] = ret;
  return ret;
}

int main()
{
  while (~scanf("%d %d", &n, &U)) {
    if (n == 0 && U == 0)
      break;

    for (int i = 0; i < (1 << 20); ++i)
      memo[i] = -1;

    for (int i = 0; i < n; ++i) {
      sub[i].r = 0;
      int k, r = 0;
      scanf("%d %d", &sub[i].c, &k);
      for (int j = 0; j < k; ++j) {
	int r;
	scanf("%d", &r);
	sub[i].r |= (1 << r);
      }
    }
    printf("%d\n", solve(0, 0));
  }
  return 0;
}
