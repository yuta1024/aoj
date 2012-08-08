#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int INF = 1 << 30;

class State
{
public:
  int b, p, j;
  State(int _b, int _p, int _j)
    :b(_b), p(_p), j(_j) {}
};

int main()
{
  int n;
  while (cin >> n) {
    if (n == 0)
      break;

    vector<vector<int> > bill(2, vector<int>(n));
    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < n; ++j)
	cin >> bill[i][j];
    }

    int ans = INF;
    queue<State> que;
    que.push(State(0, 0, 0));
    que.push(State(1, 0, 0));
    vector<vector<int> > dp(2, vector<int>(n, INF));
    while (!que.empty()) {
      State st = que.front();
      que.pop();

      if (st.p == n-1 && bill[st.b][st.p] != 2) {
	ans = min(ans, st.j);
	continue;
      }

      if (dp[st.b][st.p] <= st.j)
	continue;
      dp[st.b][st.p] = st.j;

      if (bill[st.b][st.p] == 0) {
	for (int i = 0; i <= 2; ++i) {
	  if (st.p + i >= n)
	    continue;
	  if (dp[st.b^1][st.p+i] > st.j+1)
	    que.push(State(st.b^1, st.p+i, st.j+1));
	} 
      } else if (bill[st.b][st.p] == 1) {
	while (st.p+1 < n && bill[st.b][st.p+1] == 1)
	  ++st.p;

	if (st.p == n-1) {
	  ans = min(ans, st.j);
	  continue;
	}

	for (int i = 0; i <= 2; ++i) {
	  if (st.p + i >= n)
	    continue;

	  if (dp[st.b^1][st.p+i] > st.j+1)
	    que.push(State(st.b^1, st.p+i, st.j+1));
	} 
      } else {
	while (st.p >= 0 && bill[st.b][st.p] == 2)
	  --st.p;
	if (st.p < 0)
	  continue;
	for (int i = 0; i <= 2; ++i) {
	  if (st.p + i >= n)
	    continue;
	  if (dp[st.b^1][st.p+i] > st.j+1)
	    que.push(State(st.b^1, st.p+i, st.j+1));
	} 
      }
    }

    if (ans == INF)
      cout << "NA" << endl;
    else
      cout << ans << endl;

  }
  return 0;
}
