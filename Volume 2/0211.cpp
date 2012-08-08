#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  int n;
  while (cin >> n) {
    if (n == 0)
      break;

    vector<long long int> d(n), v(n);
    for (int i = 0; i < n; ++i) {
      cin >> d[i] >> v[i];
      long long int gcd = __gcd(d[i], v[i]);
      d[i] /= gcd;
      v[i] /= gcd;
    }

    long long int lcm = d[0], gcd = v[0];
    for (int i = 1; i < n; ++i) {
      lcm = lcm / __gcd(lcm, d[i]) * d[i];
      gcd = __gcd(gcd, v[i]);
    }

    for (int i = 0; i < n; ++i)
      cout << lcm / d[i] * v[i] / gcd << endl;
  }
  return 0;
}
