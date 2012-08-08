#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
const int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
const int dd[] = {1, 2, 4, 8, 16, 32, 64, 128};
const char color[] = {'o', '\0', 'x'};


class Point
{
public:
  int x, y, dir, v;
  Point(int xx, int yy, int dd, int vv)
    :x(xx), y(yy), dir(dd), v(vv) {}
};

class Mami
{
public:
  bool operator() (const Point& lhs, const Point& rhs) const
  {
    if (lhs.v == rhs.v) {
      if (lhs.y == rhs.y)
	return lhs.x < rhs.x;
      return lhs.y < rhs.y;
    }
    return lhs.v > rhs.v;
  }
};

class Charlotte
{
public:
  bool operator() (const Point& lhs, const Point& rhs) const
  {
    if (lhs.v == rhs.v) {
      if (lhs.y == rhs.y)
	return lhs.x > rhs.x;
      return lhs.y > rhs.y;
    }
    return lhs.v > rhs.v;
  }
};

int main()
{
  vector<string> board;
  board.push_back("##########");
  for (int i = 0; i < 8; ++i) {
    string s;
    cin >> s;
    s = "#" + s + "#";
    board.push_back(s);
  }
  board.push_back("##########");
  
  int player = -1;
  bool mamitta = false;
  for ( ; ; ) {
    vector<Point> c;
    for (int y = 1; y <= 8; ++y) {
      for (int x = 1; x <= 8; ++x) {
	if (board[y][x] == '.') {
	  int dir = 0, flip = 0;
	  for (int k = 0; k < 8; ++k) {
	    int cnt = 0;
	    int xx = x + dx[k];
	    int yy = y + dy[k];
	    if (board[yy][xx] == color[-player+1]) {
	      while (board[yy][xx] == color[-player+1]) {
		++cnt;
		xx += dx[k];
		yy += dy[k];
	      }
	      if (board[yy][xx] == color[player+1]) {
		flip += cnt;
		dir |= dd[k];
	      }
	    }
	  }
	  
	  if (dir != 0)
	    c.push_back(Point(x, y, dir, flip));
	}
      }
    }

    if (c.empty()) {
      if (mamitta)
	break;
      mamitta = true;
      player = -player;
      continue;
    }

    mamitta = false;
    if (player == -1)
      sort(c.begin(), c.end(), Mami());
    else
      sort(c.begin(), c.end(), Charlotte());

    board[c[0].y][c[0].x] = color[player+1];
    for (int k = 0; k < 8; ++k) {
      if (c[0].dir & dd[k]) {
	int xx = c[0].x + dx[k];
	int yy = c[0].y + dy[k];
	while (board[yy][xx] != color[player+1]) {
	  board[yy][xx] = color[player+1];
	  xx += dx[k];
	  yy += dy[k];
	}
      }
    }
    player = -player;
  }

  board.erase(board.begin());
  board.erase(board.end()-1);
  for (int i = 0; i < 8; ++i) {
    board[i].erase(board[i].begin());
    board[i].erase(board[i].end()-1);
    cout << board[i] << endl;
  }

  return 0;
}
