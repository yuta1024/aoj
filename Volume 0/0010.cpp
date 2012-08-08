#include <cstdio>
#include <cmath>

typedef struct
{
  double x, y;
} Point;

int main()
{
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    Point A, B, C;
    scanf("%lf %lf %lf %lf %lf %lf", &A.x, &A.y, &B.x, &B.y, &C.x, &C.y);

    double a = sqrt((B.x-C.x)*(B.x-C.x) + (B.y-C.y)*(B.y-C.y));
    double b = sqrt((C.x-A.x)*(C.x-A.x) + (C.y-A.y)*(C.y-A.y));
    double c = sqrt((A.x-B.x)*(A.x-B.x) + (A.y-B.y)*(A.y-B.y));

    double angleA = acos((b*b+c*c-a*a) / (2*b*c));
    double angleB = acos((c*c+a*a-b*b) / (2*c*a));
    double angleC = acos((a*a+b*b-c*c) / (2*a*b));

    double sin2A = sin(2 * angleA);
    double sin2B = sin(2 * angleB);
    double sin2C = sin(2 * angleC);

    double x = (A.x*sin2A + B.x*sin2B + C.x*sin2C) / (sin2A+sin2B+sin2C);
    double y = (A.y*sin2A + B.y*sin2B + C.y*sin2C) / (sin2A+sin2B+sin2C);
    double r = (a / (2 * sin(angleA)));

    printf("%.3f %.3f %.3f\n", round(x*1000.0)/1000.0, round(y*1000.0)/1000.0, round(r*1000.0)/1000.0);
  }
  return 0;
}
