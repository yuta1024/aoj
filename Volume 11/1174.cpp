#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX_SIZE = 8;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

typedef struct
{
  int x, y;
} Point;

typedef struct
{
  Point p;
  int color;
} Log;

bool visited[MAX_SIZE][MAX_SIZE];
int h, w, c, panel[MAX_SIZE][MAX_SIZE], log_index[5];
Log log[5][MAX_SIZE*MAX_SIZE];

void init()
{
  for (int i = 0; i < MAX_SIZE; ++i) {
    for (int j = 0; j < MAX_SIZE; ++j)
      visited[i][j] = false;
  }
}

void init(int change)
{
  for (int i = 0; i < MAX_SIZE; ++i) {
    for (int j = 0; j < MAX_SIZE; ++j)
      visited[i][j] = false;
  }
  log_index[change] = 0;
}

int solve(const int change)
{
  if (change == 4) {
    int org_color = panel[0][0];
    Point p;
    p.x = p.y = 0;
    queue<Point> que;
    que.push(p);
    init(change);
    
    while (!que.empty()) {
      p = que.front();
      que.pop();
      
      if (visited[p.y][p.x])
	continue;
      
      log[change][log_index[change]].p.x = p.x;
      log[change][log_index[change]].p.y = p.y;
      log[change][log_index[change]].color = panel[p.y][p.x];
      ++log_index[change];

      panel[p.y][p.x] = c;
      visited[p.y][p.x] = true;
      for (int d = 0; d < 4; ++d) {
	Point pp = p;
	pp.x += dx[d];
	pp.y += dy[d];
	
	if (pp.x < 0 || pp.x >= w || pp.y < 0 || pp.y >= h ||
	    visited[pp.y][pp.x] || panel[pp.y][pp.x] != org_color)
	  continue;
	que.push(pp);
      }
    }

    int cnt = 0;
    p.x = p.y = 0;
    que.push(p);
    init();
    while (!que.empty()) {
      p = que.front();
      que.pop();
      
      if (visited[p.y][p.x])
	continue;

      ++cnt;
      visited[p.y][p.x] = true;
      for (int d = 0; d < 4; ++d) {
	Point pp = p;
	pp.x += dx[d];
	pp.y += dy[d];
	
	if (pp.x < 0 || pp.x >= w || pp.y < 0 || pp.y >= h ||
	    visited[pp.y][pp.x] || panel[pp.y][pp.x] != c)
	  continue;
	que.push(pp);
      }
    }

    for (int i = 0; i < log_index[change]; ++i)
      panel[log[change][i].p.y][log[change][i].p.x] = log[change][i].color;

    return cnt;
  }

  int ret = 0;
  for (int i = 1; i <= 6; ++i) {
    int org_color = panel[0][0];
    Point p;
    p.x = p.y = 0;
    queue<Point> que;
    que.push(p);
    init(change);

    while (!que.empty()) {
      p = que.front();
      que.pop();
    
      if (visited[p.y][p.x])
	continue;
    
      log[change][log_index[change]].p.x = p.x;
      log[change][log_index[change]].p.y = p.y;
      log[change][log_index[change]].color = panel[p.y][p.x];
      ++log_index[change];

      panel[p.y][p.x] = i;
      visited[p.y][p.x] = true;
      for (int d = 0; d < 4; ++d) {
	Point pp = p;
	pp.x += dx[d];
	pp.y += dy[d];
	
	if (pp.x < 0 || pp.x >= w || pp.y < 0 || pp.y >= h ||
	    visited[pp.y][pp.x] || panel[pp.y][pp.x] != org_color)
	  continue;
	que.push(pp);
      }
    }
    ret = max(ret, solve(change+1));

    for (int j = 0; j < log_index[change]; ++j)
      panel[log[change][j].p.y][log[change][j].p.x] = log[change][j].color;
  }
  return ret;
}

int main()
{
  while (~scanf("%d %d %d", &h, &w, &c)) {
    if (h == 0 && w == 0 && c == 0)
      break;

    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j)
	scanf("%d", &panel[i][j]);
    }
    printf("%d\n", solve(0));
  }
  return 0;
}
