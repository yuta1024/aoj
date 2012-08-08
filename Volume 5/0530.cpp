#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>
using namespace std;

const int INF = 1 << 30;

class State
{
public:
  int p, y, j, d;
  State(int _p, int _y, int _j, int _d)
    :p(_p), y(_y), j(_j), d(_d) {}
  bool operator < (const State& st) const
  {
    return this->d > st.d;
  }
};

int main()
{
  int n, m;
  while (cin >> n >> m) {
    if ((n|m) == 0)
      break;

    vector<vector<pair<int, int> > > s(n);
    for (int i = 0; i < n; ++i) {
      int k;
      cin >> k;
      for (int j = 0; j < k; ++j) {
	int x, d;
	cin >> x >> d;
	s[i].push_back(make_pair(x, d));
      }
    }

    priority_queue<State> que;
    for (int i = 0; i < s[0].size(); ++i)
      que.push(State(i, 0, 0, 0));
    if (m > 0) {
      for (int i = 0; i < s[1].size(); ++i)
	que.push(State(i, 1, 1, 0));
    }

    vector<vector<vector<int> > > dp(n, vector<vector<int> >(10, vector<int>(m+1, INF)));
    while (!que.empty()) {
      const State st = que.top();
      que.pop();

      if ((st.y == n-2 && st.j < m) || st.y == n-1) {
	cout << st.d << endl;
	break;
      }

      if (dp[st.y][st.p][st.j] < st.d)
	continue;
      dp[st.y][st.p][st.j] = st.d;

      for (int i = 0; i < s[st.y+1].size(); ++i) {
	int danger = st.d + (s[st.y][st.p].second + s[st.y+1][i].second) * abs(s[st.y][st.p].first - s[st.y+1][i].first);
	if (dp[st.y+1][i][st.j] > danger) {
	  dp[st.y+1][i][st.j] = danger;
	  que.push(State(i, st.y+1, st.j, danger));
	}
      }

      if (st.j < m && st.y+2 < n) {
	for (int i = 0; i < s[st.y+2].size(); ++i) {
	  int danger = st.d + (s[st.y][st.p].second + s[st.y+2][i].second) * abs(s[st.y][st.p].first - s[st.y+2][i].first);
	  if (dp[st.y+2][i][st.j+1] > danger) {
	    dp[st.y+2][i][st.j+1] = danger;
	    que.push(State(i, st.y+2, st.j+1, danger));
	  }
	}   
      }
    }
  }
  return 0;
}
