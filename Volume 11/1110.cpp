#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

const int dd[] = {1, 3, 4, 5};

int main()
{
  int N;
  cin >> N;
  while (N--) {
    vector<int> card(20);
    for (int i = 0; i < 20; ++i)
      cin >> card[i];

    int ans = 20;
    queue<vector<int> > que;
    set<vector<int> > visited;
    que.push(card);
    while (!que.empty()) {
      const vector<int> v = que.front();
      que.pop();

      ans = min(ans, (int)v.size());
      if (visited.find(v) != visited.end())
	continue;

      visited.insert(v);
      for (int i = 0; i < v.size(); ++i) {
	for (int d = 0; d < 4; ++d) {
	  if (0 <= i+dd[d] && i+dd[d] < v.size() && v[i] == v[i+dd[d]]) {
	    if (i % 4 == 0 && dd[d] == 3)
	      continue;
	    if (i % 4 == 3 && (dd[d] == 1 || dd[d] == 5))
	      continue;

	    vector<int> tmp;
	    for (int j = 0; j < v.size(); ++j) {
	      if (j == i || j == i+dd[d])
		continue;
	      tmp.push_back(v[j]);
	    }
	    que.push(tmp);
	  }
	}
      }
    }
    cout << ans << endl;
  }
  return 0;
}
