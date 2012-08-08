#include <cstdio>
#include <cmath>

int main()
{
  int q;
  while (~scanf("%d", &q)) {
    if (q == -1)
      break;

    double x = q / 2.0;
    while (std::abs(x*x*x-q) >= 0.00001*q)
      x = x - ((x*x*x-q) / (3*x*x));
    printf("%f\n", x);
  }
  return 0;
}
