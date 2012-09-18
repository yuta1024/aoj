#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstdio>
#include <numeric>
#include <bitset>
#include <stack>
#include <cstring>
using namespace std;

const int INF = 1 << 30;
const double EPS = 1e-10;
const int dx[7] = {0, 1, 1, 0, -1, -1, 0};
const int dy[2][7] = { {1, 0, -1, -1, -1, 0, 0}, {1, 1, 0, -1, 0, 1, 0} };
const int REV = 100;

class State
{
public:
  int x, y, t, c;
  State(int _x, int _y, int _t, int _c)
    :x(_x), y(_y), t(_t), c(_c) {}
  bool operator < (const State& st) const
  {
    return this->c > st.c;
  }
};

int main()
{
  int sx, sy, gx, gy;
  while (cin >> sx >> sy >> gx >> gy) {
    int n;
    cin >> n;
    deque<deque<bool> > h(200+1, deque<bool>(200+1, false));
    for (int i = 0; i < n; ++i) {
      int x, y;
      cin >> x >> y;
      h[y+REV][x+REV] = true;
    }

    int lx, ly;
    cin >> lx >> ly;

    int ans = -1;
    priority_queue<State> que;
    que.push(State(sx, sy, 0, 0));
    vector<vector<vector<int> > > dp(6, vector<vector<int> >(200+1, vector<int>(200+1, INF)));
    while (!que.empty()) {
      const State st = que.top();
      que.pop();

      if (st.x == gx && st.y == gy) {
        ans = st.c;
        break;
      }

      if (dp[st.t][st.y+REV][st.x+REV] < st.c)
        continue;
      dp[st.t][st.y+REV][st.x+REV] = st.c;

      int ind = abs(st.x*st.y*st.t) % 6;
      for (int d = 0; d < 7; ++d) {
        int x = st.x + dx[d];
        int y = st.y + dy[abs(st.x)%2][d];
        int c = st.c;
        if (ind != d)
          ++c;

        if (abs(x) > lx || abs(y) > ly ||
            h[y+REV][x+REV] || dp[(st.t+1)%6][y+REV][x+REV] <= c)
          continue;
        que.push(State(x, y, (st.t+1)%6, c));
      }

    }
    cout << ans << endl;
  }
  return 0;
}
