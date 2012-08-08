#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

class State
{
public:
  int x, y, dir, cost;
  State(int xx = 0, int yy = 0, int d = 0, int c = 0)
    :x(xx), y(yy), dir(d), cost(c) {}
  bool operator < (const State& st) const
  {
    return this->cost > st.cost;
  }
};

int main()
{
  const int INF = 1 << 30;

  int w, h;
  while (scanf("%d %d", &w, &h) != EOF) {
    if (w == 0 && h == 0)
      break;

    vector<vector<int> > field(h, vector<int>(w));
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j)
	scanf("%d", &field[i][j]);
    }

    vector<int> c(4);
    for (int i = 0; i < 4; ++i)
      scanf("%d", &c[i]);

    State next;
    priority_queue<State> que;
    que.push(State(0, 0, 0, 0));
    vector<vector<vector<int> > > cost(h, vector<vector<int> >(w, vector<int>(4, INF)));
    vector<vector<vector<int> > > visited(h, vector<vector<int> >(w, vector<int>(4, 0)));
    while (!que.empty()) {
      State st = que.top();
      que.pop();

      if (st.x == w-1 && st.y == h-1) {
	printf("%d\n", st.cost);
	break;
      }

      if (visited[st.y][st.x][st.dir] || cost[st.y][st.x][st.dir] < st.cost)
	continue;

      visited[st.y][st.x][st.dir] = 1;
      for (int i = 0; i < 4; ++i) {
	next.dir = (st.dir+i) % 4;
	next.cost = st.cost;
	if (field[st.y][st.x] != i)
	  next.cost += c[i];
	next.x = st.x + dx[next.dir];
	next.y = st.y + dy[next.dir];

	if (next.x < 0 || next.x >= w || next.y < 0 || next.y >= h)
	    continue;

	if (cost[next.y][next.x][next.dir] > next.cost) {
	  cost[next.y][next.x][next.dir] = next.cost;
	  que.push(next);
	}
      }
    }

  }
  return 0;
}
