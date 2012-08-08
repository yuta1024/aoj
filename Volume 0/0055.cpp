#include <cstdio>

int main()
{
  double a;
  while (~scanf("%lf", &a)) {
    double ans = a;
    for (int i = 2; i <= 10; ++i) {
      if (i&1) {
	a /= 3.0;
      } else {
	a *= 2.0;
      }
      ans += a;
    }
    printf("%.8f\n", ans);
  }
  return 0;
}
