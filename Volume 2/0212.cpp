#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1 << 30;

class State
{
public:
  int v, c, f;
  State(int _v, int _c, int _f)
    :v(_v), c(_c), f(_f) {}
  bool operator < (const State& st) const
  {
    return this->f > st.f;
  }
};

int main()
{
  int c, n, m, s, d;
  while (cin >> c >> n >> m >> s >> d) {
    if ((c|n|m|s|d) == 0)
      break;

    --s;
    --d;
    vector<vector<int> > path(n, vector<int>(n, INF));
    for (int i = 0; i < m; ++i) {
      int a, b, f;
      cin >> a >> b >> f;
      --a;
      --b;
      path[a][b] = path[b][a] = f;
    }

    priority_queue<State> que;
    que.push(State(s, c, 0));
    vector<vector<int> > dp(n, vector<int>(c+1, INF));
    while (!que.empty()) {
      const State st = que.top();
      que.pop();

      if (st.v == d) {
	cout << st.f << endl;
	break;
      }

      if (dp[st.v][st.c] < st.f)
	continue;
      dp[st.v][st.c] = st.f;

      for (int i = 0; i < n; ++i) {
	if (path[st.v][i] == INF)
	  continue;

	if (st.c > 0) {
	  if (dp[i][st.c-1] > st.f + path[st.v][i]/2) {
	    dp[i][st.c-1] = st.f + path[st.v][i]/2;
	    que.push(State(i, st.c-1, dp[i][st.c-1]));
	  }
	}

	if (dp[i][st.c] > st.f + path[st.v][i]) {
	  dp[i][st.c] = st.f + path[st.v][i];
	  que.push(State(i, st.c, dp[i][st.c]));
	}
      }
    }

  }
  return 0;
}
