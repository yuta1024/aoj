#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

typedef struct
{
  int x, y;
} Point;

class State
{
public:
  Point L, R;
  State(Point l, Point r)
    :L(l), R(r) {}
};

int main()
{
  int W, H;
  while (cin >> W >> H) {
    if (W == 0 && H == 0)
      break;

    Point L, R;
    vector<string> roomL(H), roomR(H);
    for (int i = 0; i < H; ++i) {
      cin >> roomL[i];
      if (roomL[i].find_first_of("L") != string::npos) {
	L.x = roomL[i].find_first_of("L");
	L.y = i;
	roomL[L.y][L.x] = '.';
      }
      cin >> roomR[i];
      if (roomR[i].find_first_of("R") != string::npos) {
	R.x = roomR[i].find_first_of("R");
	R.y = i;
	roomR[R.y][R.x] = '.';
      }
    }

    static bool visited[50][50][50][50];
    for (int i = 0; i < 50; ++i) {
      for (int j = 0; j < 50; ++j) {
	for (int k = 0; k < 50; ++k) {
	  for (int l = 0; l < 50; ++l)
	    visited[i][j][k][l] = false;
	}
      }
    }

    bool reached = false;
    queue<State> que;
    que.push(State(L, R));
    while (!que.empty()) {
      const State st = que.front();
      que.pop();

      if (roomL[st.L.y][st.L.x] == '%' && roomR[st.R.y][st.R.x] == '%') {
	reached = true;
	break;
      }

      if (visited[st.L.y][st.L.x][st.R.y][st.R.x] || roomL[st.L.y][st.L.x] == '%' || roomR[st.R.y][st.R.x] == '%')
	continue;

      visited[st.L.y][st.L.x][st.R.y][st.R.x] = true;
      for (int d = 0; d < 4; ++d) {
	L.x = st.L.x + dx[d];
	L.y = st.L.y + dy[d];
	if (L.x < 0 || L.x >= W || L.y < 0 || L.y >= H || roomL[L.y][L.x] == '#')
	  L = st.L;

	R.x = st.R.x - dx[d];
	R.y = st.R.y + dy[d];
	if (R.x < 0 || R.x >= W || R.y < 0 || R.y >= H || roomR[R.y][R.x] == '#')
	  R = st.R;

	if (visited[L.y][L.x][R.y][R.x])
	  continue;
	que.push(State(L, R));
      }
    }

    if (reached)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
  return 0;
}
