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

    vector<vector<int> > c(2, vector<int>(n));
    for (int i = 0; i < n; ++i)
      cin >> c[0][i];
    sort(c[0].begin(), c[0].end());

    for (int i = 1, j = 0; i <= 2*n; ++i) {
      if (!binary_search(c[0].begin(), c[0].end(), i))
	c[1][j++] = i;
    }

    int t = 0;
    while (!c[0].empty() && !c[1].empty()) {
      int num = 0;
      for ( ; ;++t) {
	vector<int>::iterator it = upper_bound(c[t&1].begin(), c[t&1].end(), num);
	if (it == c[t&1].end())
	  break;
	num = *it;
	c[t&1].erase(it);
	if (c[t&1].empty())
	  break;
      }
      ++t;
    }

    cout << c[1].size() << endl << c[0].size() << endl;
  }
  return 0;
}
