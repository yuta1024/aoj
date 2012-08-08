#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main()
{
  int n;
  while (cin >> n) {
    if (n == 0)
      break;

    vector<set<int> > res(n);
    vector<vector<int> > dat(30);
    for (int i = 0; i < n; ++i) {
      int f;
      cin >> f;
      for (int j = 0; j < f; ++j) {
	int t;
	cin >> t;
	dat[t-1].push_back(i);
      }
      res[i].insert(i);
    }

    int ans = -2;
    for (unsigned int i = 0; i < dat.size(); ++i) {
      set<int> tmp;
      for (unsigned int j = 0; j < dat[i].size(); ++j) {
	for (set<int>::iterator it = res[dat[i][j]].begin(); it != res[dat[i][j]].end(); ++it)
	  tmp.insert(*it);
      }
      for (unsigned int j = 0; j < dat[i].size(); ++j)
	res[dat[i][j]] = tmp;
      if (tmp.size() == n) {
	ans = i;
	break;
      }
    }
    cout << ans+1 << endl;
  }
  return 0;
}
