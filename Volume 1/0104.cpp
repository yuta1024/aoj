#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
  int W, H;
  while (cin >> H >> W) {
    if ((W | H) == 0)
      break;

    vector<string> tile(H);
    for (int i = 0; i < H; ++i)
      cin >> tile[i];

    int x = 0, y = 0;
    bool loop = false;
    vector<vector<int> > visited(H, vector<int>(W, 0));
    while (tile[y][x] != '.') {
      if (visited[y][x]) {
	loop = true;
	break;
      }

      visited[y][x] = 1;
      if (tile[y][x] == '>')
	++x;
      else if (tile[y][x] == '<')
	--x;
      else if (tile[y][x] == 'v')
	++y;
      else if (tile[y][x] == '^')
	--y;
    }

    if (loop)
      cout << "LOOP" << endl;
    else
      cout << x << " " << y << endl;
  }
  return 0;
}
