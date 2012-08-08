#include <cstdio>
#include <algorithm>
using namespace std;

int p, q, a, n;

int solve(int num, int den, int cnt, int pro, int e)
{
  if (cnt > n || p*den < num*q)
    return 0;
  else if (p*den == num*q)
    return 1;

  int res = 0;
  for (int i = e; i <= a; ++i) {
    if (pro*i > a)
      break;

    int x = num * i + den;
    int y = den * i;
    /*
    int gcd = __gcd(x, y);
    x /= gcd;
    y /= gcd;
    */

    res += solve(x, y, cnt+1, pro*i, i);
  }
  return res;
}

int main()
{
  while (~scanf("%d %d %d %d", &p, &q, &a, &n)) {
    if ((p|q|a|n) == 0)
      break;
    printf("%d\n", solve(0, 1, 0, 1, 1));
  }
  return 0;
}
