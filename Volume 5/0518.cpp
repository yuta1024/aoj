#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

bool p[5000+1][5000+1];
int x[3000], y[3000];

int main()
{
  int n;
  while (~scanf("%d", &n)) {
    if (n == 0)
      break;

    memset(p, false, sizeof(p));
    for (int i = 0; i < n; ++i) {
      scanf("%d %d", &x[i], &y[i]);
      p[y[i]][x[i]] = true;
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = i+1; j < n; ++j) {
	int dx = x[j] - x[i];
	int dy = y[j] - y[i];

	int x1 = x[i] + dy, y1 = y[i] - dx;
	int x2 = x[j] + dy, y2 = y[j] - dx;
	if (x1 < 0 || 5000 < x1 || y1 < 0 || 5000 < y1 ||
	    x2 < 0 || 5000 < x2 || y2 < 0 || 5000 < y2)
	  continue;

	if (p[y1][x1] && p[y2][x2])
	  ans = std::max(ans, dx*dx+dy*dy);
      }
    }

    printf("%d\n", ans);
  }
  return 0;
}
