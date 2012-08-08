#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

const double PI = 3.1415926535897932384626433832795;

inline double deg2rad(const double deg)
{
  return deg * PI / 180.0;
}

int main()
{
  double x = 0.0, y = 0.0, angle = 0.0;
  int step, deg;
  while (scanf("%d,%d", &step, &deg) != EOF) {
    if (step == 0 && deg == 0)
      break;

    x += step * sin(deg2rad(angle));
    y += step * cos(deg2rad(angle));

    angle += deg;

  }
  cout << static_cast<int>(x) << endl;
  cout << static_cast<int>(y) << endl;

  return 0;
}
