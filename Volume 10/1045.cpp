#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

const int INF = 1 << 30;

int main()
{
  int n;
  while (cin >> n) {
    if (n == 0)
      break;

    vector<int> a(n);
    for (int i = 0; i < n; ++i)
      cin >> a[i];

    int ans = INF;
    for (int i = 0; i < (1 << n); ++i) {
      int p = 0, b = 0;
      for (int j = 0; j < n; ++j) {
	if (i & (1 << j))
	  p += a[j];
	else
	  b += a[j];
      }
      ans = min(ans, abs(p-b));
    }

    cout << ans << endl;
  }
  return 0;
}
