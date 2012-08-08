#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <complex>
using namespace std;

const double EPS = 1e-10;
const double PI = 3.14159265358979;

int main()
{
  int n;
  while (cin >> n) {
    if (n == 0)
      break;

    vector<complex<int> > cp(n);
    for (int i = 0; i < n; ++i)
      cin >> cp[i].real() >> cp[i].imag();

    double ans = 0.0;
    vector<int> visited(n, 0);
    complex<int> p(0, 0), dv(0, 1);
    for ( ; ; ) {
      int minIndex = -1;
      double minAngle = 1e10, minDistance = 1e10;
      for (int i = 0; i < n; ++i) {
	if (visited[i])
	  continue;

	complex<int> v = cp[i] - p;
	double angle = atan2(v.real()*dv.imag()-v.imag()*dv.real(), v.real()*dv.real()+v.imag()*dv.imag());
	if (angle+EPS < minAngle) {
	  minIndex = i;
	  minAngle = angle;
	  minDistance = hypot(cp[i].real()-p.real(), cp[i].imag()-p.imag());
	} else if (abs(angle-minAngle) < EPS) {
	  double dist = hypot(cp[i].real()-p.real(), cp[i].imag()-p.imag());
	  if (dist < minDistance) {
	    minIndex = i;
	    minDistance = dist;
	  }
	}
      }

      if (minIndex == -1)
	break;

      ans += minDistance;
      dv = cp[minIndex] - p;
      p = cp[minIndex];
      visited[minIndex] = 1;
    }
    printf("%.1f\n", ans);
  }
  return 0;
}
