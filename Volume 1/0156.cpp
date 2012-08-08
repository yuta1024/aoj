#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

const int INF = 1 << 30;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

class State
{
public:
  int x, y, cost;
  bool water;

  State(int _x, int _y, int _cost, bool _water)
    :x(_x), y(_y), cost(_cost), water(_water) {}

  bool operator < (const State& st) const
  {
    return this->cost > st.cost;
  }
};

int main()
{
  int n, m;
  while (cin >> n >> m) {
    if ((n|m) == 0)
      break;

    int sx, sy;
    vector<string> castle(m);
    for (int i = 0; i < m; ++i) {
      cin >> castle[i];
      castle[i].insert(castle[i].begin(), '.');
      castle[i].insert(castle[i].end(), '.');

      if (castle[i].find_first_of("&") != string::npos) {
	sx = castle[i].find_first_of("&");
	sy = i;
	castle[sy][sx] = '.';
      }
    }
    castle.insert(castle.begin(), string(n+2, '.'));
    castle.push_back(string(n+2, '.'));
    ++sy;

    priority_queue<State> que;
    que.push(State(sx, sy, 0, false));
    vector<vector<int> > dp(m+2, vector<int>(n+2, INF));
    while (!que.empty()) {
      const State st = que.top();
      que.pop();

      if (st.x == 0 || st.x == n+1 || st.y == 0 || st.y == m+1) {
	cout << st.cost << endl;
	break;
      }

      if (dp[st.y][st.x] < st.cost)
	continue;
      dp[st.y][st.x] = st.cost;

      for (int d = 0; d < 4; ++d) {
	int x = st.x + dx[d];
	int y = st.y + dy[d];
	if (x < 0 || n+2 <= x || y < 0 || m+2 <= y)
	  continue;

	if (st.water) {
	  if (castle[y][x] == '#' && dp[y][x] > st.cost) {
	    dp[y][x] = st.cost;
	    que.push(State(x, y, st.cost, true));
	  }

	  if (castle[y][x] == '.' && dp[y][x] > st.cost+1) {
	    dp[y][x] = st.cost+1;
	    que.push(State(x, y, st.cost+1, false));
	  }
	} else {
	  if (castle[y][x] == '#' && dp[y][x] > st.cost) {
	    dp[y][x] = st.cost;
	    que.push(State(x, y, st.cost, true));
	  }

	  if (castle[y][x] == '.' && dp[y][x] > st.cost) {
	    dp[y][x] == st.cost;
	    que.push(State(x, y, st.cost, false));
	  }
	}
      }
    }
  }
  return 0;
}
