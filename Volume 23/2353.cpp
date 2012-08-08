#include <iostream>
#include <cstdio>
using namespace std;

long long int extgcd(long long int a, long long int b, long long int& x, long long int& y)
{
  long long int d = a;
  if (b != 0) {
    d = extgcd(b, a%b, y, x);
    y -= (a / b) * x;
  } else {
    x = 1;
    y = 0;
  }
  return d;
}

long long int mod_inverse(long long int a, long long int m)
{
  long long int x, y;
  extgcd(a, m, x, y);
  return (m + x % m) % m;
}							

int main()
{
  const long long int p = 9999991LL;
  const long long int q = 9999973LL;
  
  int N;
  while (cin >> N) {
    long long int Xp = 0, Xq = 0;
    for (int i = 0; i < N; ++i) {
      int o, Y;
      scanf("%d %d", &o, &Y);
      if (o == 1) {
	Xp = (Xp + Y) % p;
	Xq = (Xq + Y) % q;
      } else if (o == 2) {
	Xp = (Xp + p - Y) % p;
	Xq = (Xq + q - Y) % q;
      } else if (o == 3) {
	Xp = (Xp * Y) % p;
	Xq = (Xq * Y) % q;
      } else {
	Xp = (Xp * mod_inverse(Y, p)) % p;
	Xq = (Xq * mod_inverse(Y, q)) % q;
      }
    }

    long long int x, y;
    extgcd(p, q, x, y);
    long long int ans = (Xp * q * y + Xq * p * x) % (p * q);

    if (ans < (1LL << 31))
      ans = ans + p*q;
    if (ans >= (1LL << 31))
      ans = ans - p*q;

    cout << ans << endl;
  }
  return 0;
}
