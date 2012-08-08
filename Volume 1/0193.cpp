#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1 << 30;
const int dx[2][6] = { {0, -1, -1, -1, 0, 1}, {1, 0, -1, 0, 1, 1} };
const int dy[6] = {-1, -1, 0, 1, 1, 0};

class State
{
public:
  int x, y, c;
  State(int _x = 0, int _y = 0, int _c = 0)
    :x(_x), y(_y), c(_c) {}
};

int main()
{
  int m, n;
  while (cin >> m >> n) {
    if ((m|n) == 0)
      break;

    int s;
    cin >> s;
    vector<vector<int> > cost(n, vector<int>(m, INF));
    for (int i = 0; i < s; ++i) {
      int x, y;
      cin >> x >> y;
      queue<State> que;
      que.push(State(x-1, y-1, 0));
      while (!que.empty()) {
	const State st = que.front();
	que.pop();

	if (cost[st.y][st.x] < st.c)
	  continue;

	cost[st.y][st.x] = st.c;
	for (int d = 0; d < 6; ++d) {
	  x = st.x + dx[st.y%2][d];
	  y = st.y + dy[d];
	  if (x < 0 || m <= x || y < 0 || n <= y || cost[y][x] <= st.c+1)
	    continue;
	  cost[y][x] = st.c+1;
	  que.push(State(x, y, st.c+1));
	}
      }
    }

    int t;
    cin >> t;
    int ans = 0;
    for (int i = 0; i < t; ++i) {
      int x, y, cnt = 0;
      cin >> x >> y;
      queue<State> que;
      que.push(State(x-1, y-1, 0));
      vector<vector<int> > visited(n, vector<int>(m, 0));
      while (!que.empty()) {
	const State st = que.front();
	que.pop();

	if (cost[st.y][st.x] <= st.c || visited[st.y][st.x])
	  continue;

	++cnt;
	visited[st.y][st.x] = 1;
	for (int d = 0; d < 6; ++d) {
	  x = st.x + dx[st.y%2][d];
	  y = st.y + dy[d];
	  if (x < 0 || m <= x || y < 0 || n <= y || cost[y][x] <= st.c+1 || visited[y][x])
	    continue;
	  que.push(State(x, y, st.c+1));
	}
      }
      ans = max(ans, cnt);
    }

    cout << ans << endl;
  }
  return 0;
}
