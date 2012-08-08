#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

const int INF = 1 << 28;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, -1, 0, 1};

class Point
{
public:
  int x, y;
  Point(int _x = 0, int _y = 0)
    :x(_x), y(_y) {}
};

int N, cost[20][20][20][20], dist[11][11], dp[1 << 11][11];

int solve(int S, int v)
{
  if (dp[S][v] != -1)
    return dp[S][v];

  if (S == (1 << N)-1) {
    dp[S][v] = 0;
    return 0;
  }

  int ret = INF;
  for (int i = 0; i < N; ++i) {
    if (!(S & (1 << i)))
      ret = min(ret, solve(S | (1 << i), i)+dist[v][i]);
  }
  dp[S][v] = ret;
  return ret;
}

int main()
{
  int w, h;
  while (cin >> w >> h) {
    if ((w | h) == 0)
      break;

    // init
    for (int i = 0; i < 20; ++i) {
      for (int j = 0; j < 20; ++j) {
	for (int k = 0; k < 20; ++k) {
	  for (int l = 0; l < 20; ++l)
	    cost[i][j][k][l] = INF;
	}
      }
    }
    for (int i = 0; i < 11; ++i) {
      for (int j = 0; j < 11; ++j)
	dist[i][j] = 0;
    }
    for (int i = 0; i < (1 << 11); ++i) {
      for (int j = 0; j < 11; ++j)
	dp[i][j] = -1;
    }

    vector<string> floor(h);
    for (int i = 0; i < h; ++i)
      cin >> floor[i];

    Point robot;
    vector<Point> tiles;
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
	if (floor[i][j] == 'x') {
	  continue;
	} else if (floor[i][j] == 'o') {
	  robot.x = j;
	  robot.y = i;
	} else if (floor[i][j] == '*') {
	  tiles.push_back(Point(j, i));
	}
      }
    }

    tiles.insert(tiles.begin(), robot);
    for (unsigned int i = 0; i < tiles.size(); ++i) {
      queue<Point> que;
      que.push(tiles[i]);
      cost[tiles[i].y][tiles[i].x][tiles[i].y][tiles[i].x] = 0;
      while (!que.empty()) {
	const Point p = que.front();
	que.pop();

	for (int d = 0; d < 4; ++d) {
	  Point pp(p.x + dx[d], p.y + dy[d]);
	  if (pp.x < 0 || pp.x >= w || pp.y < 0 || pp.y >= h || floor[pp.y][pp.x] == 'x')
	    continue;
	  if (cost[tiles[i].y][tiles[i].x][pp.y][pp.x] > cost[tiles[i].y][tiles[i].x][p.y][p.x]+1) {
	    cost[tiles[i].y][tiles[i].x][pp.y][pp.x] = cost[tiles[i].y][tiles[i].x][p.y][p.x]+1;
	    que.push(pp);
	  }
	}
      }
    }

    bool valid = true;
    for (unsigned int i = 0; i < tiles.size(); ++i) {
      for (unsigned int j = i+1; j < tiles.size(); ++j) {
	dist[i][j] = dist[j][i] = cost[tiles[i].y][tiles[i].x][tiles[j].y][tiles[j].x];
	if (dist[i][j] >= INF)
	  valid = false;
      }
    }

    if (!valid) {
      cout << "-1" << endl;
    } else {
      N = tiles.size();
      cout << solve(1, 0) << endl;
    }
  }
  return 0;
}
