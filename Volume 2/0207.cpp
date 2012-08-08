#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int main()
{
  int w, h;
  while (cin >> w >> h) {
    if ((w|h) == 0)
      break;

    int xs, ys, xg, yg;
    cin >> xs >> ys >> xg >> yg;
    --xs;
    --ys;
    --xg;
    --yg;

    int c;
    cin >> c;
    vector<vector<int> > block(h, vector<int>(w, -1));
    for (int i = 0; i < c; ++i) {
      int c, d, x, y;
      cin >> c >> d >> x >> y;
      --x;
      --y;

      if (d == 0) {
	for (int j = 0; j < 4; ++j)
	  block[y][x+j] = block[y+1][x+j] = c;
      } else {
	for (int j = 0; j < 4; ++j)
	  block[y+j][x] = block[y+j][x+1] = c;
      }
    }

    string ans = "NG";
    queue<pair<int, int> > que;
    que.push(make_pair(xs, ys));
    vector<vector<int> > visited(h, vector<int>(w, 0));
    while (!que.empty()) {
      const pair<int, int> p = que.front();
      que.pop();

      if (p.second == yg && p.first == xg) {
	ans = "OK";
	break;
      }

      if (visited[p.second][p.first])
	continue;
      visited[p.second][p.first] = 1;

      for (int d = 0; d < 4; ++d) {
	int x = p.first + dx[d];
	int y = p.second + dy[d];
	if (x < 0 || w <= x || y < 0 || h <= y ||
	    block[p.second][p.first] != block[y][x] || visited[y][x])
	  continue;
	que.push(make_pair(x, y));
      }
    }

    cout << ans << endl;
  }
  return 0;
}
