#include <iostream>
#include <vector>
using namespace std;

const int INF = 1 << 30;

int main()
{
  int n;
  while (cin >> n) {
    if (n == 0)
      break;

    vector<int> p(n);
    for (int i = 0; i < n; ++i)
      cin >> p[i];
    p.push_back(INF); // sentinel

    pair<int, int> prev(make_pair(p[0], p[0]));
    vector<pair<int, int> > ans;
    for (int i = 1; i < n+1; ++i) {
      if (p[i] != prev.second+1) {
	ans.push_back(prev);
	prev.first = prev.second = p[i];
      } else {
	prev.second = p[i];
      }
    }

    for (int i = 0; i < ans.size(); ++i) {
      if (ans[i].first == ans[i].second)
	printf("%d%s", ans[i].first, i != ans.size()-1 ? " ": "\n");
      else
	printf("%d-%d%s", ans[i].first, ans[i].second, i != ans.size()-1 ? " " : "\n");
    }
  }
  return 0;
}
