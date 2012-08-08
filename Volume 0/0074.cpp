#include <cstdio>

int main()
{
  int h, m, s;
  while (scanf("%d %d %d", &h, &m, &s)) {
    if (h == -1 && m == -1 && s == -1)
      break;
    int n_rem = 120 * 60 - (h * 3600 + m * 60 + s);
    printf("%02d:%02d:%02d\n", n_rem/3600, n_rem%3600/60, n_rem%60);
    n_rem *= 3;
    printf("%02d:%02d:%02d\n", n_rem/3600, n_rem%3600/60, n_rem%60);
  }
  return 0;
}
