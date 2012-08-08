#include <cstdio>

int main()
{
  double w;
  while (~scanf("%lf", &w)) {
    if (w <= 48.0)
      puts("light fly");
    else if (w <= 51.0)
      puts("fly");
    else if (w <= 54.0)
      puts("bantam");
    else if (w <= 57.0)
      puts("feather");
    else if (w <= 60.0)
      puts("light");
    else if (w <= 64.0)
      puts("light welter");
    else if (w <= 69.0)
      puts("welter");
    else if (w <= 75.0)
      puts("light middle");
    else if (w <= 81.0)
      puts("middle");
    else if (w <= 91.0)
      puts("light heavy");
    else
      puts("heavy");
  }
  return 0;
}
