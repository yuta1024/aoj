#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

int ans;
vector<string> f;

void solve(int x, int y)
{
  if (x < 0 || x >= f[0].size())
    return;
  if (y < 0 || y >= f.size())
    return;
  if (f[y][x] == '#')
    return;
  
  ++ans;
  f[y][x] = '#';

  for (int i = 0; i < 4; ++i)
    solve(x+dx[i], y+dy[i]);
}

int main()
{
  int W, H, x, y;
  for ( ; ; ) {
    cin >> W >> H;
    if (W == 0 && H == 0)
      break;

    f.clear();
    for (int i = 0; i < H; ++i) {
      string tmp;
      cin >> tmp;
      int a = tmp.find_first_of("@", 0);
      if (a != string::npos) {
	x = a;
	y = i;
      }
      f.push_back(tmp);
    }
    ans = 0;
    solve(x, y);
    cout << ans << endl;
  }
  return 0;
}
