#include <cstdio>
#include <cmath>

int main()
{
  int x, h;
  while (~scanf("%d %d", &x, &h)) {
    if ((x|h) == 0)
      break;
    printf("%.6f\n", x*x + x*sqrt(static_cast<double>(4*h*h+x*x)));
  }
  return 0;
}
