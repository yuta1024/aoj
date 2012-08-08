#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
  long long int n, m;
  while (cin >> n >> m) {
    if ((n|m) == 0)
      break;

    vector<long long int> p(m);
    for (int i = 0; i < m; ++i)
      cin >> p[i];

    long long int sum = (n+1) * n / 2, cnt = n;
    for (int i = 1; i < (1 << m); ++i) {
      long long int lcm = 1LL;
      for (int j = 0; j < m; ++j) {
	if (i & (1 << j))
	  lcm = lcm / __gcd(lcm, p[j]) * p[j];
      }
      if (__builtin_popcount(i) & 1) {
	sum -= lcm * ((n/lcm+1) * n/lcm / 2);
	cnt -= n / lcm;
      } else {
	sum += lcm * ((n/lcm+1) * n/lcm / 2);
	cnt += n / lcm;
      }
    }

    if (cnt == 0)
      printf("%.10f\n", 0.0);
    else
      printf("%.10f\n", sum / (cnt * 1.0));
  }
  return 0;
}
