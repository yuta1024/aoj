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

    vector<int> a(n);
    for (int i = 0; i < n; ++i)
      cin >> a[i];

    int ans = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n-i-1; ++j) {
	if (a[j] > a[j+1]) {
	  ++ans;
	  swap(a[j], a[j+1]);
	}
      }
    }

    cout << ans << endl;
  }
  return 0;
}
