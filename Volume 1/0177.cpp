#include <iostream>
#include <cmath>
using namespace std;

const double PI = 3.14159265358979;

inline double d2r(double d)
{
  return d * PI / 180.0;
}

int main()
{
  const double R = 6378.1;

  double a, b, c, d;
  while (cin >> a >> b >> c >> d) {
    if (a == -1.0 && b == -1.0 && c == -1.0 && d == -1.0)
      break;

    a = d2r(a);
    b = d2r(b);
    c = d2r(c);
    d = d2r(d);

    double thita = acos(cos(a)*cos(c)*cos(b-d) + sin(a)*sin(c));

    cout << static_cast<int>(thita * R + 0.5) << endl;
  }
  return 0;
}
