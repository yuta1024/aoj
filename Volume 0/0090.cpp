#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const double EPS = 1e-10;

int main()
{
  int n;
  while (~scanf("%d", &n)) {
    if (n == 0)
      break;

    vector<pair<double, double> > p(n);
    for (int i = 0; i < n; ++i)
      scanf("%lf,%lf", &p[i].first, &p[i].second);

    vector<pair<double, double> > ip;
    for (int i = 0; i < n; ++i) {
      for (int j = i+1; j < n; ++j) {
	double xx = p[i].first - p[j].first;
	double yy = p[i].second - p[j].second;
	if (xx*xx + yy*yy - 4.0 < EPS) {
	  double a = ((p[i].first-p[j].first)*(p[i].first-p[j].first) +
		      (p[i].second-p[i].second)*(p[i].second-p[j].second)) / 2.0;
	  double root = sqrt(3.0*a);


	}
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
