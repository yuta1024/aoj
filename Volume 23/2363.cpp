#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const double EPS  = 0.0000001;

int main()
{
  int t;
  while (cin >> t) {
    double E1 = 0.0;
    for (int i = 0; i < t; ++i) {
      int n, m;
      cin >> n >> m;

      double tmp = 0.0, valid = 0.0;
      for (int j = 0; j < m; ++j) {
	int v;
	double r;
	cin >> v >> r;
	tmp += v * r;
	valid += r;
      }
      E1 = max(E1, tmp / valid);
    }

    double E2 = 0.0, valid = 0.0;
    int p, q;
    cin >> p >> q;
    for (int i = 0; i < q; ++i) {
      int v;
      double r;
      cin >> v >> r;
      E2 += v * r;
      valid += r;
    }

    if (E1 - (E2/valid) > EPS)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
