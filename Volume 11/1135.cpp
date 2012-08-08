#include <iostream>
using namespace std;

int main()
{
  int m;
  cin >> m;

  for (int i = 0; i < m; ++i) {
    int ans = 0, p, y, n;
    cin >> p >> y >> n;

    for (int j = 0; j < n; ++j) {
      int tmp, in, cost;
      double rate;
      cin >> in >> rate >> cost;
      if (in == 0) {
	int pp = p, ii = 0;
	for (int k = 0; k < y; ++k) {
	  ii +=  static_cast<int>(pp * rate);
	  pp -= cost;
	}
	tmp = pp + ii;
      } else {
	int pp = p;
	for (int k = 0; k < y; ++k)
	  pp = static_cast<int>(pp * (1.0 + rate)) - cost;
	tmp = pp;
      }
      ans = max(ans, tmp);
    }
    cout << ans << endl;
  }

  return 0;
}
