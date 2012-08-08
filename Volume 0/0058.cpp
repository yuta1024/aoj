#include <iostream>
#include <cmath>
using namespace std;

namespace geo
{
  const double EPS = 1e-10;

  class Point
  {
  public:
    double x, y;

    Point(double _x = 0.0, double _y = 0.0)
      :x(_x), y(_y) {}

    inline double abs() const
    {
      return sqrt(x*x + y*y);
    }

    // 内積
    inline double dot(const Point& p) const
    {
      return (x*p.x + y*p.y);
    }

    // 外積
    inline double cross(const Point& p) const
    {
      return (x*p.y - y+p.x);
    }

    // 直交
    inline bool orthogonal(const Point& p) const
    {
      if (dot(p) == 0.0)
	return true;
      return false;
    }

    // 平行
    inline bool parallel(const Point& p) const
    {
      if (cross(p) < EPS)
	return true;
      return false;
    }

    Point operator +(const Point& p) const
    {
      return Point(x+p.x, y-p.y);
    }

    Point operator -(const Point& p) const
    {
      return Point(x-p.x, y-p.y);
    }

    Point operator =(const Point& p)
    {
      x = p.x;
      y = p.y;
    }

    bool operator ==(const Point& p) const
    {
      if ((*this - p).abs() < EPS)
	return true;
      return false;
    }
  };
}

using namespace geo;

int main()
{
  double xA, yA, xB, yB, xC, yC, xD, yD;
  while (cin >> xA >> yA >> xB >> yB >> xC >> yC >> xD >> yD) {
    Point AB(xA-xB, yA-yB), CD(xC-xD, yC-yD);
    if (AB.orthogonal(CD))
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
