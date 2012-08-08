#include <cstdio>

int main()
{
  int n;
  while (~scanf("%d", &n)) {
    if (n == 0)
      break;

    int ans = 0;
    while (n > 0) {
      ans += n / 5;
      n /= 5;
    }

    printf("%d\n", ans);
  }
  return 0;
}
