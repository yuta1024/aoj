#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const string dd = "ESWN";
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

class State
{
public:
  int x, y, d;
  State(int _x = 0, int _y = 0, int _d = 0)
    :x(_x), y(_y), d(_d) {}
};

int main()
{
  int H, W;
  long long int L;
  while (cin >> H >> W >> L) {
    if ((H|W|L) == 0)
      break;

    State s;
    vector<string> c(H);
    for (int i = 0; i < H; ++i) {
      cin >> c[i];
      if (c[i].find_first_of(dd) != string::npos) {
	s.y = i;
	s.x = c[i].find_first_of(dd);
	s.d = dd.find_first_of(c[s.y][s.x]);
	c[s.y][s.x] = '.';
      }
    }

    vector<vector<vector<long long int> > > visited(H, vector<vector<long long int> >(W, vector<long long int>(4, -1)));
    for (long long int i = 0; i < L; ++i) {
      if (visited[s.y][s.x][s.d] == -1) {
	visited[s.y][s.x][s.d] = i;
      } else {
	long long int diff = i - visited[s.y][s.x][s.d];
	i = L - ((L - i) % diff);
	if (i == L)
	  break;
      }
      
      while (s.x+dx[s.d] < 0 || W <= s.x+dx[s.d] ||
	     s.y+dy[s.d] < 0 || H <= s.y+dy[s.d] ||
	     c[s.y+dy[s.d]][s.x+dx[s.d]] == '#')
	s.d = (s.d+1) % 4;

      s.x += dx[s.d];
      s.y += dy[s.d];
    }

    cout << s.y+1 << " " << s.x+1 << " " << dd[s.d] << endl;
  }
  return 0;
}
