#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

const int INF = 1 << 30;

int main()
{
  int n;
  while (cin >> n) {
    if (n == 0)
      break;

    vector<int> b(n), x(n), y(n);
    for (int i = 0; i < n; ++i)
      cin >> b[i] >> x[i] >> y[i];

    vector<vector<pair<int, double> > > cost(1001);
    for (int i = 0; i < n; ++i) {
      for (int j = i+1; j < n; ++j) {
	int dist = (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]);
	if (dist <= 50*50) {
	  cost[b[i]].push_back(make_pair(b[j], sqrt(dist)));
	  cost[b[j]].push_back(make_pair(b[i], sqrt(dist)));
	}
      }
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
      int s, g;
      cin >> s >> g;

      bool valid = false;
      priority_queue<pair<double, int>, vector<pair<double, int> >, greater<pair<double, int> > > que;
      que.push(make_pair(0, s));
      vector<double> dp(1001, 1e10);
      vector<int> path(1001, -1);
      while (!que.empty()) {
	const pair<double, int> v = que.top();
	que.pop();

	if (v.second == g) {
	  valid = true;
	  break;
	}

	if (dp[v.second] < v.first)
	  continue;

	dp[v.second] = v.first;
	for (unsigned int j = 0; j < cost[v.second].size(); ++j) {
	  double next = v.first + cost[v.second][j].second;
	  if (dp[cost[v.second][j].first] > next) {
	    dp[cost[v.second][j].first] = next;
	    que.push(make_pair(next, cost[v.second][j].first));
	    path[cost[v.second][j].first] = v.second;
	  }
	}
      }

      if (valid) {
	vector<int> ans;
	for (int j = g; j != -1; j = path[j])
	  ans.push_back(j);
	reverse(ans.begin(), ans.end());
	for (int j = 0; j < ans.size()-1; ++j)
	  cout << ans[j] << " ";
	cout << ans.back() << endl;
      } else {
	cout << "NA" << endl;
      }
    }

  }
  return 0;
}
