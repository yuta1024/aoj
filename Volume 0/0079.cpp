#include <cmath>
#include <vector>
#include <algorithm>
#include <cstdio>
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
      return (x*p.y - y*p.x);
    }
    
    // 直交
    /*
      AOJ0058: EPS -> 0.0 
    */
    inline bool orthogonal(const Point& p) const
    {
      if (dot(p) < EPS)
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
    
    bool operator <(const Point& p) const
    {
      if (std::abs(x-p.x) < EPS)
	return y < p.y;
      return x < p.x;
    }
  };

  /*
    凸多角形の面積（要反時計回り or 時計回り）
    凹多角形にも適用可能であるが，自己交差などを含む場合は除く
    Verifyed:
  */
  double convex_area(const vector<Point>& ps)
  {
    double area = 0.0;
    for (unsigned int i = 0; i < ps.size(); ++i)
      area += ps[i].cross(ps[(i+1)%ps.size()]);
    return std::abs(area/2.0);
  }

  /*
    凸包:graham scan(p.234), O(nlogn)
    Verified:AOJ0068
  */
  vector<Point> convex_hull_gs(vector<Point>& ps)
  {
    sort(ps.begin(), ps.end());
    int k = 0, n = static_cast<int>(ps.size());
    vector<Point> qs(n * 2);
    for (int i = 0; i < n; ++i) {
      while (k > 1 && (qs[k-1] - qs[k-2]).cross(ps[i] - qs[k-1]) < EPS)
	--k;
      qs[k++] = ps[i];
    }

    for (int i = n-2, t = k; i >= 0; --i) {
      while (k > t && (qs[k-1] - qs[k-2]).cross(ps[i] - qs[k-1]) < EPS)
	--k;
      qs[k++] = ps[i];
    }

    qs.resize(k-1);
    return qs;
  }
}

int main()
{
  double x, y;
  vector<geo::Point> ps;
  while (~scanf("%lf,%lf", &x, &y))
    ps.push_back(geo::Point(x, y));  
  printf("%.6f\n", geo::convex_area(ps));
  return 0;
}
