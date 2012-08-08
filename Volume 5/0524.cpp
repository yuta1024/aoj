#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  int m;
  while (cin >> m) {
    if (m == 0)
      break;

    vector<pair<int, int> > fs(m);
    for (int i = 0; i < m; ++i)
      cin >> fs[i].first >> fs[i].second;

    vector<pair<int, int> > diff;
    for (int i = 1; i < m; ++i)
      diff.push_back(make_pair(fs[i].first-fs[0].first, fs[i].second-fs[0].second));

    int n;
    cin >> n;
    vector<pair<int, int> > s(n);
    for (int i = 0; i < n; ++i)
      cin >> s[i].first >> s[i].second;
    sort(s.begin(), s.end());

    for (int i = 0; i < n; ++i) {
      bool found = true;
      for (int j = 0; j < diff.size(); ++j) {
	if (!binary_search(s.begin(), s.end(), make_pair(s[i].first+diff[j].first, s[i].second+diff[j].second))) {
	  found = false;
	}
      }

      if (found) {
	cout << s[i].first - fs[0].first << " " << s[i].second - fs[0].second << endl;
	break;
      }
    }

  }
  return 0;
}
