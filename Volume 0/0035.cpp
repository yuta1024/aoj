#include <cstdio>

typedef struct
{
  double x, y;
} Point;

bool intersect(const Point& p1, const Point& p2, const Point& p3, const Point& p4)
{
  if (((p1.x-p2.x)*(p3.y-p1.y)+(p1.y-p2.y)*(p1.x-p3.x)) *
      ((p1.x-p2.x)*(p4.y-p1.y)+(p1.y-p2.y)*(p1.x-p4.x)) < 0)
    return true;
  return false;
}

int main()
{
  Point a, b, c, d;
  while (scanf("%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf",
	       &a.x, &a.y, &b.x, &b.y, &c.x, &c.y, &d.x, &d.y) != EOF) {

    if(intersect(a, c, b, d) && intersect(b, d, a, c))
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
