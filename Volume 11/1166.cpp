#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1 << 30;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, -1, 0, 1};

class Point
{
public:
  int x, y;
  Point(int _x, int _y)
    :x(_x), y(_y) {}
};

class Cell
{
public:
  bool w[4];
  Cell()
  {
    w[0] = w[1] = w[2] = w[3] = true;
  }
};

class State
{
public:
  Point p;
  int cost;
  State(Point _p, int _cost)
    :p(_p), cost(_cost) {}
  bool operator < (const State& st) const
  {
    return this->cost > st.cost;
  }
};

int main()
{
  int w, h;
  while (~scanf("%d %d", &w, &h)) {
    if (w == 0 && h == 0)
      break;

    vector<vector<Cell> > map(h, vector<Cell>(w));
    for (int i = 0; i < 2*h-1; ++i) {
      int in;
      if (i&1) {
	for (int j = 0; j < w; ++j) {
	  scanf("%d", &in);
	  map[i/2][j].w[3] = map[i/2+1][j].w[1] = in;
	}
      } else {
	for (int j = 0; j < w-1; ++j) {
	  scanf("%d", &in);
	  map[i/2][j].w[0] = map[i/2][j+1].w[2] = in;
	}
      }
    }

    int ans = 0;
    priority_queue<State> que;
    que.push(State(Point(0, 0), 1));
    vector<vector<int> > dp(h, vector<int>(w, INF));
    while (!que.empty()) {
      const State st = que.top();
      que.pop();

      if (st.p.x == w-1 && st.p.y == h-1) {
	ans = st.cost;
	break;
      }

      if (dp[st.p.y][st.p.x] < st.cost)
	continue;

      dp[st.p.y][st.p.x] = st.cost;
      for (int i = 0; i < 4; ++i) {
	if (!map[st.p.y][st.p.x].w[i]) {
	  if (dp[st.p.y+dy[i]][st.p.x+dx[i]] > st.cost+1) {
	    dp[st.p.y+dy[i]][st.p.x+dx[i]] = st.cost+1;
	    que.push(State(Point(st.p.x+dx[i], st.p.y+dy[i]), st.cost+1));
	  }
	}
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
