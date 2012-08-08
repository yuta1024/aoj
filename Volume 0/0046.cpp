#include <cstdio>

int main()
{
  double max, min, input;
  scanf("%lf", &input);
  min = max = input;

  while (~scanf("%lf", &input)) {
    if (max < input)
      max = input;
    if (min > input)
      min = input;
  }
  printf("%.1f\n", max-min);
  return 0;
}
