#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1 << 30;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

class State
{
public:
  int tx, ty, kx, ky, c;
  State(int _tx, int _ty, int _kx, int _ky, int _c = 0)
    :tx(_tx), ty(_ty), kx(_kx), ky(_ky), c(_c) {}
};

int main()
{
  int X, Y;
  while (cin >> X >> Y) {
    if ((X|Y) == 0)
      break;

    int tx, ty, kx, ky;
    cin >> tx >> ty >> kx >> ky;

    vector<vector<int> > depart(Y, vector<int>(X));
    for (int i = 0; i < Y; ++i) {
      for (int j = 0; j < X; ++j)
	cin >> depart[i][j];
    }

    int ans = -1;
    queue<State> que;
    que.push(State(tx-1, ty-1, kx-1, ky-1, 0));
    vector<vector<vector<vector<int> > > > dp(Y, vector<vector<vector<int> > >(X, vector<vector<int> >(Y, vector<int>(X, INF))));
    while (!que.empty()) {
      const State st = que.front();
      que.pop();

      if (st.tx == st.kx && st.ty == st.ky) {
	ans = st.c;
	break;
      }

      if (dp[st.ty][st.tx][st.ky][st.kx] < st.c)
	continue;

      dp[st.ty][st.tx][st.ky][st.kx] = st.c;
      for (int d = 0; d < 4; ++d) {
	tx = st.tx + dx[d];
	ty = st.ty + dy[d];
	kx = st.kx + dx[(d+2)%4];
	ky = st.ky + dy[(d+2)%4];
	if (tx < 0 || X <= tx || ty < 0 || Y <= ty || depart[ty][tx] != 0) {
	  tx = st.tx;
	  ty = st.ty;
	}

	if (kx < 0 || X <= kx || ky < 0 || Y <= ky || depart[ky][kx] != 0) {
	  kx = st.kx;
	  ky = st.ky;
	}

	if (dp[ty][tx][ky][kx] > st.c+1) {
	  dp[ty][tx][ky][kx] = st.c+1;
	  que.push(State(tx, ty, kx, ky, st.c+1));
	}
      }
    }

    if (ans == -1)
      cout << "NA" << endl;
    else
      cout << ans << endl;
  }
  return 0;
}
