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

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

map<int, vector<vector<string> > > memo;

class State
{
public:
  int x, y, f, s, c;
  State(int _x, int _y, int _f, int _s, int _c)
    :x(_x), y(_y), f(_f), s(_s), c(_c) {}

  bool operator < (const State& st) const
  {
    return this->c > st.c;
  }
};

void generate(int idx, int bit, vector<vector<string> > M, const vector<vector<pair<int, int> > >& s, const int S)
{
  memo[bit] = M;
  if (idx >= S)
    return;

  generate(idx+1, bit, M, s, S);
  for (unsigned int i = 0; i < s[idx].size(); ++i)
    swap(M[0][s[idx][i].second][s[idx][i].first], M[1][s[idx][i].second][s[idx][i].first]);
  generate(idx+1, bit | (1 << idx), M, s, S);
}

int main()
{
  int W, H;
  while (cin >> W >> H) {
    vector<string> Mi(H);
    for (int i = 0; i < H; ++i)
      cin >> Mi[i];

    int sx, sy;
    vector<vector<string> > M(2, vector<string>(H, string(W, ' ')));
    for (int i = 0; i < H; ++i) {
      for (int j = 0; j < W; ++j) {
        if (Mi[i][j] == '_') {
          M[0][i][j] = '.';
          M[1][i][j] = '#';
        } else if (Mi[i][j] == '^') {
          M[1][i][j] = '.';
          M[0][i][j] = '#'; 
        } else if (Mi[i][j] == '%') {
          M[0][i][j] = '.';
          M[1][i][j] = '#';
          sx = j;
          sy = i;
        } else if (Mi[i][j] == '&') {
          M[0][i][j] = '&';
          M[1][i][j] = '#';
        } else if (isalpha(Mi[i][j])) {
          if (islower(Mi[i][j])) {
            M[0][i][j] = Mi[i][j];
            M[1][i][j] = '#';
          } else {
            M[1][i][j] = tolower(Mi[i][j]);
            M[0][i][j] = '#';
          }
        } else {
          M[0][i][j] = M[1][i][j] = Mi[i][j];
        }
      }
    }


    int S;
    cin >> S;
    vector<vector<pair<int, int> > > s(S);
    for (int i = 0; i < S; ++i) {
      for (int j = 0; j < H; ++j) {
        string MS;
        cin >> MS;
        for (int k = 0; k < W; ++k) {
          if (MS[k] == '*')
            s[i].push_back(make_pair(k, j));
        }
      }
    }

    memo.clear();
    generate(0, 0, M, s, S);

    int ans = -1;
    priority_queue<State> que;
    que.push(State(sx, sy, 0, 0, 0));
    vector<vector<vector<vector<int> > > > dp(1 << S, vector<vector<vector<int> > >(2, vector<vector<int> >(H, vector<int>(W, INF))));
    while (!que.empty()) {
      State st = que.top();
      que.pop();

      if (memo[st.s][st.f][st.y][st.x] == '&') {
        ans = st.c;
        break;
      }

      if (dp[st.s][st.f][st.y][st.x] < st.c)
        continue;
      dp[st.s][st.f][st.y][st.x] = st.c;

      for (int d = 0; d < 4; ++d) {
        int x = st.x + dx[d];
        int y = st.y + dy[d];
        if (x < 0 || W <= x || y < 0 || H <= y || memo[st.s][st.f][y][x] == '#')
          continue;
        if (dp[st.s][st.f][y][x] > st.c+1) {
          dp[st.s][st.f][y][x] = st.c+1;
          que.push(State(x, y, st.f, st.s, st.c+1));
        }
      }

      if (memo[st.s][st.f][st.y][st.x] == '|') {
        st.f ^= 1;
        if (dp[st.s][st.f][st.y][st.x] > st.c+1) {
          dp[st.s][st.f][st.y][st.x] = st.c+1;
          que.push(State(st.x, st.y, st.f, st.s, st.c+1));
        }
      } else if (isalpha(memo[st.s][st.f][st.y][st.x])) {
        int sw = memo[st.s][st.f][st.y][st.x] - 'a';
        for (unsigned int i = 0; i < s[sw].size(); ++i) {
          if (st.x == s[sw][i].first && st.y == s[sw][i].second) {
            st.f ^= 1;
            break;
          }
        }
        st.s ^= (1 << sw);
        if (dp[st.s][st.f][st.y][st.x] > st.c+1) {
          dp[st.s][st.f][st.y][st.x] = st.c+1;
          que.push(State(st.x, st.y, st.f, st.s, st.c+1));
        }
      }
    }

    cout << ans << endl;
  }
  return 0;
}
