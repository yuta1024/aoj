#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, -1, 0, 1};

int main()
{
  const int BLACK = 1 << 0;
  const int WHITE = 1 << 1;

  int w, h;
  while (cin >> w >> h) {
    if ((w|h) == 0)
      break;

    vector<string> area(h);
    for (int i = 0; i < h; ++i)
      cin >> area[i];

    vector<vector<int> > color(h, vector<int>(w, 0));
    for (int y = 0; y < h; ++y) {
      for (int x = 0; x < w; ++x) {
	if (area[y][x] != '.') {
	  int base = 0;
	  if (area[y][x] == 'B')
	    base = BLACK;
	  else
	    base = WHITE;
	  queue<pair<int, int> > que;
	  for (int d = 0; d < 4; ++d) {
	    int xx = x + dx[d];
	    int yy = y + dy[d];
	    if (0 <= xx && xx < w && 0 <= yy && yy < h && area[yy][xx] == '.')
	      que.push(make_pair(yy, xx));
	  }
	  while (!que.empty()) {
	    pair<int, int> p = que.front();
	    que.pop();

	    if (color[p.first][p.second] & base)
	      continue;

	    color[p.first][p.second] |= base;
	    for (int d = 0; d < 4; ++d) {
	      int xx = p.second + dx[d];
	      int yy = p.first + dy[d];
	      if (0 <= xx && xx < w && 0 <= yy && yy < h && area[yy][xx] == '.')
		que.push(make_pair(yy, xx));
	    }
	  }
	}
      }
    }

    int black = 0, white = 0;
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
	if (color[i][j] == BLACK)
	  ++black;
	else if (color[i][j] == WHITE)
	  ++white;
      }
    }
    cout << black << " " << white << endl;
  }
  return 0;
}
