#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

const int INF = 1 << 30;

int main()
{
  int N;
  while (cin >> N) {
    vector<vector<int> > c(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j)
	cin >> c[i][j];
    }

    vector<int> p;
    for (int i = 0; i < N; ++i)
      p.push_back(i);
    priority_queue<pair<int, vector<int> >, vector<pair<int, vector<int> > >, greater<pair<int, vector<int> > > > que;
    que.push(make_pair(0, p));
    map<vector<int>, int> dp;
    dp[p] = 0;

    while (!que.empty()) {
      pair<int, vector<int> > v = que.top();
      que.pop();

      if (dp[v.second] < v.first)
	continue;
      dp[v.second] = v.first;

      for (int i = 0; i < N; ++i) {
	for (int j = i+1; j < N; ++j) {
	  swap(v.second[i], v.second[j]);
	  if (dp.find(v.second) == dp.end() ||
	      v.first+c[v.second[i]][v.second[j]] < dp[v.second]) {
	    dp[v.second] = v.first+c[v.second[i]][v.second[j]];
	    v.first += c[v.second[i]][v.second[j]];
	    que.push(v);
	    v.first -= c[v.second[i]][v.second[j]];
	  }
	  swap(v.second[j], v.second[i]);
	}
      }
    }

    int ans = 0;
    for (map<vector<int>, int>::iterator it = dp.begin(); it != dp.end(); ++it)
      ans = max(ans, it->second);
    cout << ans << endl;
  }

  return 0;
}
