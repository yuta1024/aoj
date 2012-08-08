#include <cstdio>
#include <vector>
#include <cmath>
#include <complex>
#include <algorithm>
using namespace std;

const double EPS = 1e-9;

typedef struct
{
  double x, y;
}Point;

int main()
{
  int N;
  while (~scanf("%d", &N)) {
    if (N == 0)
      break;

    Point c;
    vector<Point> p(N);
    for (int i = 0; i < N; ++i)
      scanf("%lf %lf", &p[i].x, &p[i].y);

    int ans = 1;
    for (int i = 0; i < N; ++i) {
      for (int j = i+1; j < N; ++j) {
	double H = hypot(p[i].x-p[j].x, p[i].y-p[j].y);
	if (H - 2.0 > EPS)
	  continue;
	double D = sqrt(1.0 - (H*H)/4.0);
	for (int pm = 0; pm < 2; ++pm) {
	  c.x = (p[i].x+p[j].x)/2.0 + (p[j].y-p[i].y)*D/H;
	  c.y = (p[i].y+p[j].y)/2.0 - (p[j].x-p[i].x)*D/H;
	  int cnt = 2;
	  for (int k = 0; k < N; ++k) {
	    if (k == i || k == j)
	      continue;
	    if ((c.x-p[k].x)*(c.x-p[k].x)+(c.y-p[k].y)*(c.y-p[k].y)-1.0 <= EPS)
	      ++cnt;
	  }
	  ans = max(ans, cnt);
	  D *= -1.0;
	}
     }
    }
    printf("%d\n", ans);
  }
  return 0;
}
