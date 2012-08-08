#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

inline bool in(const int x, const int y, const int w, const int h)
{
  if (0 <= x && x < w && 0 <= y && y < h)
    return true;
  return false;
}

int main()
{
  int d;
  cin >> d;
  while (d--) {
    int n;
    cin >> n;
    vector<string> p(n, string(n, '#'));

    bool update = true;
    int x = 1, y = n-1, dir = 3, cnt = 0;
    while (update) {
      update = false;
      for (int i = 0; i < 4 && !update; ++i) {
	int xx = x + dx[dir], yy = y + dy[dir];
	if (in(xx, yy, n, n) && p[yy][xx] == '#' &&
	    in(xx+dx[dir], yy+dy[dir], n, n) && p[yy+dy[dir]][xx+dx[dir]] == '#') {
	  p[y][x] = ' ';
	  x += dx[dir];
	  y += dy[dir];
	  update = true;
	} else {
	  dir = (dir+1) % 4;
	}
      }
    }

    p[y][x] = ' ';
    for (int i = 0; i < n; ++i)
      cout << p[i] << endl;

    if (d != 0)
      cout << endl;
  }
  return 0;
}
