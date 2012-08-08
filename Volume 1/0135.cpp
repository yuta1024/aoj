#include <cstdio>

int main()
{
  int n;
  scanf("%d", &n);
  while (n--) {
    int h, m;
    scanf("%d:%d", &h, &m);

    int diff = h * 300 - m * 55;
    if (diff < 0)
      diff *= -1;
    if (diff > 1800)
      diff = 3600 - diff;
    if (0 <= diff && diff < 300)
      puts("alert");
    else if (900 <= diff && diff <= 1800)
      puts("safe");
    else
      puts("warning");
  }
  return 0;
}
