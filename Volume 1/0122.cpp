#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Point
{
public:
  int x, y;
  Point(int _x = 0, int _y = 0)
    :x(_x), y(_y) {}
};

class State
{
public:
  Point p;
  int num;
  State(Point _p, int _num)
    :p(_p), num(_num) {}
};

const int pdx[] = {1, 0, -1, -2, -2, -2, -1, 0, 1, 2, 2, 2};
const int pdy[] = {-2, -2, -2, -1, 0, 1, 2, 2, 2, 1, 0, -1};
const int sdx[] = {0, 1, 0, -1, -1, -1, 0, 1, 1};
const int sdy[] = {0, -1, -1, -1, 0, 1, 1, 1, 0};

int main()
{
  int px, py;
  while (cin >> px >> py) {
    if ((px|py) == 0)
      break;

    int n;
    cin >> n;

    vector< vector<Point> > spp(n);
    for (int i = 0; i < n; ++i) {
      int sx, sy;
      cin >> sx >> sy;
      for (int j = 0; j < 9; ++j)
	spp[i].push_back(Point(sx+sdx[j], sy+sdy[j]));
    }

    bool ok = false;
    queue<State> que;
    que.push(State(Point(px, py), -1));
    while (!que.empty()) {
      const State st = que.front();
      que.pop();

      if (st.num == n-1) {
	ok = true;
	break;
      }

      for (int i = 0; i < 12; ++i) {
	Point p(st.p.x+pdx[i], st.p.y+pdy[i]);
	if (p.x < 0 || 9 < p.x || p.y < 0 || 9 < p.y)
	  continue;
	for (int j = 0; j < spp[st.num+1].size(); ++j) {
	  if (p.x == spp[st.num+1][j].x && p.y == spp[st.num+1][j].y)
	    que.push(State(p, st.num+1));
	}
      }
    }

    if (ok)
      cout << "OK" << endl;
    else
      cout << "NA" << endl;
  }
  return 0;
}
