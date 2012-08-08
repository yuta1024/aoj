#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, -1, 0, 1};

int main()
{
  int W, H;
  while (cin >> W >> H) {
    if ((W|H) == 0)
      break;

    vector<string> maze(H);
    for (int i = 0; i < H; ++i) {
      cin >> maze[i];
      for (int j = 0; j < W; ++j) {
	if (maze[i][j] == 'E')
	  maze[i][j] = '0';
	else if (maze[i][j] == 'N')
	  maze[i][j] = '1';
	else if (maze[i][j] == 'W')
	  maze[i][j] = '2';
	else if (maze[i][j] == 'S')
	  maze[i][j] = '3';
      }
    }

    int ans = -1;
    for (int t = 1; t <= 181; ++t) {
      // change dir
      for (int i = 0; i < H; ++i) {
	for (int j = 0; j < W; ++j) {
	  if (maze[i][j] == 'X' || maze[i][j] == '.' || maze[i][j] == '#')
	    continue;

	  bool change = false;
	  int dir = maze[i][j] - '0', next_dir;
	  for (int d = 0; d < 4; ++d) {
	    next_dir = (dir+d+3) % 4;
	    int x = j + dx[next_dir];
	    int y = i + dy[next_dir];
	    if (x < 0 || W <= x || y < 0 || H <= y ||
		maze[y][x] != '.' && maze[y][x] != 'X')
	      continue;
	    change = true;
	    break;
	  }

	  if (change)
	    maze[i][j] = static_cast<char>(next_dir + '0');
	}
      }

      vector<string> cpy = maze;
      // move
      for (int i = 0; i < H; ++i) {
	for (int j = 0; j < W; ++j) {
	  if (maze[i][j] != 'X' && maze[i][j] != '.')
	    continue;

	  for (int d = 0; d < 4; ++d) {
	    int x = j + dx[d];
	    int y = i + dy[d];
	    
	    if (x < 0 || W <= x || y < 0 || H <= y ||
		maze[y][x] == '#' || maze[y][x] == 'X' || maze[y][x] == '.')
	      continue;

	    int dir = maze[y][x] - '0';
	    int xx = x+dx[dir], yy = y+dy[dir];
	    if (j != xx || i != yy)
	      continue;
	    
	    if (maze[i][j] == 'X') {
	      cpy[y][x] = '.';
	      maze[y][x] = '#';
	    } else {
	      cpy[i][j] = maze[y][x];
	      cpy[y][x] = '.';
	      maze[i][j] = maze[y][x] = '#';
	    }
	    ans = t;
	    break;
	  }
	}
      }

      maze = cpy;
    }

    if (ans == 181)
      cout << "NA" << endl;
    else
      cout << ans << endl;
  }
  return 0;
}
