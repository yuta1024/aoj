#include <cstdio>

int main()
{
  int num;
  double weight, height;
  while (~scanf("%d,%lf,%lf", &num, &weight, &height)) {
    if (weight / (height*height) >= 25.0)
      printf("%d\n", num);
  }
  return 0;
}
