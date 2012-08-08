#include <iostream>
#include <cmath>
using namespace std;

int K;
double P, E, T;

double solve(int night, double L, double R)
{
  double Td = (L + R) / 2.0;
  if (night == K) {
    if (abs(T-Td) < E)
      return 1.0;
    else
      return 0.0;
  }

  if (T - L <= E && R - T <= E)
    return 1.0;
  if (T + E < L || T - E > R)
    return 0.0;

  if (Td <= T)
    return (1.0-P)*solve(night+1, Td, R) + P*solve(night+1, L, Td);
  else
    return (1.0-P)*solve(night+1, L, Td) + P*solve(night+1, Td, R);
}

int main()
{
  int R, L;
  while (cin >> K >> R >> L) {
    cin >> P >> E >> T;
    printf("%.6f\n", solve(0, R, L));
  }
  return 0;
}
