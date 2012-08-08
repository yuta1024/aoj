#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1 << 30;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

class Dice
{
private:
  /*
    pip[0] = top, pip[1] = south, pip[2] = east
    pip[3] = bottom, pip[4] = north, pip[5] = west
  */
  int pip[6];
public:
  enum { TOP, SOUTH, EAST, BOTTOM, NORTH, WEST };

  Dice(int top = 1, int south = 2, int east = 3)
  {
    pip[TOP] = top;
    pip[SOUTH] = south;
    pip[EAST] = east;
    pip[BOTTOM] = 7 - top;
    pip[NORTH] = 7 - south;
    pip[WEST] = 7 - east;
  }

  // east:+, west:-
  void rotateX(int r)
  {
    if (r < 0)
      r += 4 * (-(r/4) + 1);
    r %= 4;
    for (int i = 0; i < r; ++i) {
      int tmp = pip[TOP];
      pip[TOP] = pip[WEST];
      pip[WEST] = pip[BOTTOM];
      pip[BOTTOM] = pip[EAST];
      pip[EAST] = tmp;
    }
  }

  // south:+, north:-
  void rotateY(int r)
  {
    if (r < 0)
      r += 4 * (-(r/4) + 1);
    r %= 4;
    for (int i = 0; i < r; ++i) {
      int tmp = pip[TOP];
      pip[TOP] = pip[NORTH];
      pip[NORTH] = pip[BOTTOM];
      pip[BOTTOM] = pip[SOUTH];
      pip[SOUTH] = tmp;
    }
  }
 
  inline int get(int p) const
  {
    return pip[p];
  } 
};

class State
{
public:
  int x, y, cost;
  Dice dice;
  State(int _x = 0, int _y = 0, int _cost = 0)
    :x(_x), y(_y), cost(_cost) {}

  bool operator < (const State& st) const
  {
    return this->cost > st.cost;
  }
};

int main()
{
  int h, w;
  while (cin >> h >> w) {
    if ((h|w) == 0)
      break;

    vector<vector<int> > mass(h, vector<int>(w));
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j)
	cin >> mass[i][j];
    }

    int sx, sy, gx, gy;
    cin >> sy >> sx >> gy >> gx;

    priority_queue<State> que;
    que.push(State(sx, sy, 0));
    int dp[10][10][6][6][6]; // dp[y][x][top][south][east]
    for (int y = 0; y < 10; ++y)
      for (int x = 0; x < 10; ++x)
	for (int t = 0; t < 6; ++t)
	  for (int s = 0; s < 6; ++s)
	    for (int e = 0; e < 6; ++e)
	      dp[y][x][t][s][e] = INF;

    while (!que.empty()) {
      const State st = que.top();
      que.pop();

      if (st.x == gx && st.y == gy) {
	cout << st.cost << endl;
	break;
      }

      if (dp[st.y][st.x][st.dice.get(Dice::TOP)-1][st.dice.get(Dice::SOUTH)-1][st.dice.get(Dice::EAST)-1] < st.cost)
	continue;

      dp[st.y][st.x][st.dice.get(Dice::TOP)-1][st.dice.get(Dice::SOUTH)-1][st.dice.get(Dice::EAST)-1] = st.cost;
      for (int d = 0; d < 4; ++d) {
	int x = st.x + dx[d];
	int y = st.y + dy[d];
	if (x < 0 || w <= x || y < 0 || h <= y)
	  continue;

	Dice dice = st.dice;
	if (dx[d] != 0)
	  dice.rotateX(dx[d]);
	else
	  dice.rotateY(dy[d]);

	int cost = st.cost + mass[y][x] * dice.get(Dice::BOTTOM);
	if (dp[y][x][dice.get(Dice::TOP)-1][dice.get(Dice::SOUTH)-1][dice.get(Dice::EAST)-1] > cost) {
	  dp[y][x][dice.get(Dice::TOP)-1][dice.get(Dice::SOUTH)-1][dice.get(Dice::EAST)-1] = cost;
	  State tmp(x, y, cost);
	  tmp.dice = dice;
	  que.push(tmp);
	}
      }
    }
  }
  return 0;
}
