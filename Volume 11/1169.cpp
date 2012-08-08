#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
  const int MAX_SIZE = 400;

  int n, a, s, g;
  while (cin >> n >> a >> s >> g) {
    if ((n|a|s|g) == 0)
      break;

    vector<vector<pair<int, string> > > label(n);
    for (int i = 0; i < a; ++i) {
      int x, y;
      string lab;
      cin >> x >> y >> lab;
      label[x].push_back(make_pair(y, lab));
    }

    string ans = "NO";
    priority_queue<pair<string, int>, vector<pair<string, int> >, greater<pair<string, int> > > que;
    vector<vector<string> > dp(n, vector<string>(MAX_SIZE, ""));
    que.push(make_pair("", s));
    while (!que.empty()) {
      const pair<string, int> p = que.top();
      que.pop();

      if (p.second == g) {
	ans = p.first;
	break;
      }

      if (dp[p.second][p.first.size()] != "" &&
	  dp[p.second][p.first.size()] < p.first ||
	  p.first.size() >= MAX_SIZE)
      	continue;

      dp[p.second][p.first.size()] = p.first;
      for (unsigned int i = 0; i < label[p.second].size(); ++i) {
	int v = label[p.second][i].first;
	string spell = p.first + label[p.second][i].second;
	if (spell.size() >= MAX_SIZE)
	  continue;
	if (dp[v][spell.size()] == "" || spell < dp[v][spell.size()]) {
	  dp[v][spell.size()] = spell;
	  que.push(make_pair(spell, v));
	}
      }
    }

    if (ans.size() >= MAX_SIZE-100)
      ans = "NO";
    cout << ans << endl;
  }
  return 0;
}
