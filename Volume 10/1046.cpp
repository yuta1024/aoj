#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

const int INF = 1 << 30;
const int dx[] = {0, 1, 0, -1, 0};
const int dy[] = {0, 0, 1, 0, -1};

class State
{
public:
  int sx, sy, gx, gy, time;
  State(int _sx, int _sy, int _gx, int _gy, int _time)
    :sx(_sx), sy(_sy), gx(_gx), gy(_gy), time(_time) {}
};

int main()
{
  int H, W;
  while (cin >> H >> W) {
    if ((H|W) == 0)
      break;

    vector<string> city(H);
    int sx, sy, gx, gy;
    for (int i = 0; i < H; ++i) {
      cin >> city[i];

      if (city[i].find_first_of("A") != string::npos) {
	sy = i;
	sx = city[i].find_first_of("A");
	city[sy][sx] = '.';
      }
      if (city[i].find_first_of("B") != string::npos) {
	gy = i;
	gx = city[i].find_first_of("B");
	city[gy][gx] = '.';
      }
    }

    string pattern;
    cin >> pattern;
    for (int i = 0; i < pattern.size(); ++i) {
      if (pattern[i] == '5')
	pattern[i] = '0';
      else if (pattern[i] == '8')
	pattern[i] = '4';
      else if (pattern[i] == '6')
	pattern[i] = '1';
      else if (pattern[i] == '4')
	pattern[i] = '3';
      else
	pattern[i] = '2';
    }

    bool found = false;
    queue<State> que;
    que.push(State(sx, sy, gx, gy, 0));
    vector<vector<vector<vector<vector<int> > > > > dp(H, vector<vector<vector<vector<int> > > >(W, vector<vector<vector<int> > >(H, vector<vector<int > >(W, vector<int>(pattern.size(), INF)))));
    while (!que.empty()) {
      const State st = que.front();
      que.pop();

      if(st.sx == st.gx && st.sy == st.gy) {
	cout << st.time << " " << st.sy << " " << st.sx << endl;
	found = true;
	break;
      }

      if (dp[st.sy][st.sx][st.gy][st.gx][st.time%pattern.size()] < st.time)
	continue;
      dp[st.sy][st.sx][st.gy][st.gx][st.time%pattern.size()] = st.time;

      for (int d = 0; d < 5; ++d) {
	sx = st.sx + dx[d];
	sy = st.sy + dy[d];
	gx = st.gx + dx[pattern[st.time%pattern.size()]-'0'];
	gy = st.gy + dy[pattern[st.time%pattern.size()]-'0'];

	if (sx < 0 || W <= sx || sy < 0 || H <= sy || city[sy][sx] == '#')
	  continue;

	if (gx < 0 || W <= gx)
	  gx = st.gx;
	if (gy < 0 || H <= gy)
	  gy = st.gy;

	if (dp[sy][sx][gy][gx][(st.time+1)%pattern.size()] > st.time+1) {
	  dp[sy][sx][gy][gx][(st.time+1)%pattern.size()] = st.time+1;
	  que.push(State(sx, sy, gx, gy, st.time+1));
	}
      }

    }

    if (!found)
      cout << "impossible" << endl;
  }
  return 0;
}
