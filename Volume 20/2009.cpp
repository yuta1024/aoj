#include <cmath>
#include <vector>
#include <complex>
#include <iostream>
using namespace std;

const double EPS = 1e-9;

double cross(const complex<double>& p1, const complex<double>& p2)
{
  return p1.real() * p2.imag() - p1.imag() * p2.real();
}

bool intersected(const complex<double>& a1, const complex<double>& a2,
		 const complex<double>& b1, const complex<double>& b2)
{
  return ( cross(a2-a1, b1-a1) * cross(a2-a1, b2-a1) < EPS ) &&
         ( cross(b2-b1, a1-b1) * cross(b2-b1, a2-b1) < EPS );
}

complex<double> intersection_p(const complex<double>& a1, const complex<double>& a2,
			       const complex<double>& b1, const complex<double>& b2)
{
  complex<double> b = b2-b1;
  double d1 = abs(cross(b, a1-b1));
  double d2 = abs(cross(b, a2-b1));
  double t = d1 / (d1 + d2);
  return a1 + (a2-a1) * t;
}

int main()
{
  int n;
  while (cin >> n) {
    if (n == 0)
      break;

    vector<pair<complex<double>, complex<double> > > p(n);
    for (int i = 0; i < n; ++i)
      cin >> p[i].first.real() >> p[i].first.imag()
	  >> p[i].second.real() >> p[i].second.imag();

    int ans = 1;
    for (int i = 0; i < n; ++i) {
      vector<complex<double> > ip;
      for (int j = 0; j < i; ++j) {
	if (p[i].first == p[j].first || p[i].first == p[j].second ||
	    p[i].second == p[j].first || p[i].second == p[j].second ||
	    !intersected(p[i].first, p[i].second, p[j].first, p[j].second))
	  continue;
	
	bool dup = false;
	complex<double> cip = intersection_p(p[i].first, p[i].second, p[j].first, p[j].second);
	for (unsigned int i = 0; i < ip.size() && !dup; ++i) {
	  if (abs(cip.real()-ip[i].real()) < EPS && abs(cip.imag()-ip[i].imag()) < EPS)
	    dup = true;
	}
	
	if (!dup) {
	  ++ans;
	  ip.push_back(cip);
	}
      }
      ++ans;
    }
    cout << ans << endl;
  }
  return 0;
}
