#include <cstdio>

int main()
{
  double t5, t10;
  while (~scanf("%lf %lf", &t5, &t10)) {
    if (t5 < 35.50 && t10 < 71.00)
      puts("AAA");
    else if (t5 < 37.50 && t10 < 77.00)
      puts("AA");
    else if (t5 < 40.00 && t10 < 83.00)
      puts("A");
    else if (t5 < 43.00 && t10 < 89.00)
      puts("B");
    else if (t5 < 50.00 && t10 < 105.00)
      puts("C");
    else if (t5 < 55.00 && t10 < 116.00)
      puts("D");
    else if (t5 < 70.00 && t10 < 148.00)
      puts("E");
    else
      puts("NA");
  }
  return 0;
}
