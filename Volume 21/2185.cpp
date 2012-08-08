#include <cstdio>

int main()
{
  int T;
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    int X, Y, W, H, N, ans = 0;
    scanf("%d %d %d %d %d", &X, &Y, &W, &H, &N);
    for (int i = 0; i < N; ++i) {
      int x, y;
      scanf("%d %d", &x, &y);
      if (X <= x && x <= X+W && Y <= y && y <= Y+H)
	++ans;
    }
    printf("%d\n", ans);
  }
  return 0;
}
