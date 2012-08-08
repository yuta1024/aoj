#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int dx[7][3] = { {1, 0, 1}, {0, 0, 0}, {1, 2, 3}, {0, -1, -1}, {1, 1, 2}, {0, 1, 1}, {1, 0, -1} };
const int dy[7][3] = { {0, 1, 1}, {1, 2, 3}, {0, 0, 0}, {1,  1,  2}, {0, 1, 1}, {1, 1, 2}, {0, 1,  1} };

bool inrange(int x, int y)
{

      return false;
      return true;
}

int main()
{
  for ( ; ; ) {
    vector<string> f(8);
    for (int i = 0; i < 8; ++i)
      getline(cin, f[i]);

    int sx = -1, sy = -1;
    for (int y = 0; y < 8; ++y) {
      for (int x = 0; x < 8; ++x) {
	if (f[y][x] != '0' && sx == -1 && sy == -1) {
	  sx = x;
	  sy = y;
	}
      }
    }

    for (int i = 0; i < 7; ++i) {
      int cnt = 0;
      for (int j = 0; j < 3; ++j) {
	int xx = sx + dx[i][j];
	int yy = sy + dy[i][j];
	if (xx < 0 || xx >= 8 || yy < 0 || yy >= 8)
	    continue;
	if (f[yy][xx] == '1')
	  ++cnt;
      }
	if (cnt == 3) {
	  cout << static_cast<char>('A'+i) << endl;
	  break;
	}
    }

    // blank
    if (!getline(cin, f[0]))
	break;
  }
  return 0;
}
