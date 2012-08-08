#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct
{
  int x, y;
} Point;

int solve(vector<vector<int> >& board, int idx, const vector<Point>& rp)
{
  if (idx >= 8) {
    bool valid = true;
    for (int i = 0; i < 4 && valid; ++i) {
      for (int j = 0; j < 4 && valid; ++j) {
	if (board[i][j] == -1)
	  valid = false;
      }
    }
    if (valid)
      return 1;
    return 0;
  }

  int res = 0, x = 0, y = 0;
  for (y = 0; y < 4; ++y) {
    bool valid = false;
    for (x = 0; x < 4; ++x) {
      if (board[y][x] == -1) {
	valid = true;
	break;
      }
    }
    if (valid)
      break;
  }

  for (unsigned int i = 0; i < rp.size(); ++i) {
    int xx = x + rp[i].x;
    int yy = y + rp[i].y;
    if (xx < 0 || 4 <= xx || yy < 0 || 4 <= yy || board[yy][xx] != -1)
      continue;
    board[y][x] = board[yy][xx] = idx;
    res += solve(board, idx+1, rp);
    board[y][x] = board[yy][xx] = -1;
  }
  return res;
}

int main()
{
  vector<Point> rp(4);
  while (cin >> rp[0].x >> rp[0].y >> rp[1].x >> rp[1].y
	 >> rp[2].x >> rp[2].y >> rp[3].x >> rp[3].y) {
    if (rp[0].x >= 4)
      break;

    vector<vector<int> > board(4, vector<int>(4, -1));
    cout << solve(board, 0, rp) << endl;
  }
  return 0;
}
