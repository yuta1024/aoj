#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main()
{
  int n;
  while (cin >> n) {
    if (n == 0)
      break;

    set<int> mod;
    for (int i = 1; i < n; ++i)
      mod.insert((i*i)%n);

    vector<int> ans(n, 0);
    for (set<int>::iterator it = mod.begin(); it != mod.end(); ++it) {
      for (set<int>::iterator jt = it; jt != mod.end(); ++jt) {
	if (*it == *jt)
	  continue;
	int diff = *it - *jt;
	if (diff < 0)
	  diff += n;
	if (diff > (n-1)/2)
	  diff = n - diff;
	++ans[diff];
      }
    }

    for (int i = 1; i <= (n-1)/2; ++i)
      cout << ans[i]*2 << endl;
  }
  return 0;
}
