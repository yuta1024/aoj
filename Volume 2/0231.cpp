#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int n;
  while (cin >> n) {
    if (n == 0)
      break;

    vector<int> m(n), a(n), b(n);
    for (int i = 0; i < n; ++i)
      cin >> m[i] >> a[i] >> b[i];

    bool ok = true;
    for (int i = 0; i < n; ++i) {
      int sum = m[i];
      for (int j = 0; j < n; ++j) {
	if (i == j)
	  continue;

	if (a[j] <= a[i] && a[i] < b[j])
	  sum += m[j];
      }

      if (sum > 150)
	ok = false;
    }

    if (ok)
      cout << "OK" << endl;
    else
      cout << "NG" << endl;
  }
  return 0;
}
