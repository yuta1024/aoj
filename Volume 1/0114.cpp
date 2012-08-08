#include <iostream>
using namespace std;

long long int gcd(long long int a, long long int b)
{
  if (b == 0)
    return a;
  return gcd(b, a%b);
}

int main()
{
  int a1, m1, a2, m2, a3, m3;
  while (cin >> a1 >> m1 >> a2 >> m2 >> a3 >> m3) {
    if ((a1|m1|a2|m2|a3|m3) == 0)
      break;

    int x = 1, y = 1, z = 1;
    long long cntX = 0, cntY = 0, cntZ = 0;

    do {
      ++cntX;
      x = (a1 * x) % m1;
    } while (x != 1);

    do {
      ++cntY;
      y = (a2 * y) % m2;
    } while (y != 1);

    do {
      ++cntZ;
      z = (a3 * z) % m3;
    } while (z != 1);

    long long int ans = cntX / gcd(cntX, cntY) * cntY;
    ans = ans / gcd(ans, cntZ) * cntZ;
    cout << ans << endl;
  }
  return 0;
}
