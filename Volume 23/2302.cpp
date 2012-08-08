#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <queue>
using namespace std;

enum { PER, ON, OFF };
const int INF = 1 << 30;
const int dc[] = {1, 0, -1, 0};
const int dr[] = {0, 1, 0, -1};

typedef struct
{
  int p[3];
} Light;

class RC
{
public:
  int r, c;
  RC(int _r = 0, int _c = 0)
    :r(_r), c(_c) {}
};

int main()
{
  int R, C, M;
  while (~scanf("%d %d %d", &R, &C, &M)) {
    vector<string> office(R);
    for (int r = 0; r < R; ++r)
      cin >> office[r];

    vector<vector<Light> > cost(R, vector<Light>(C));
    for (int i = 0; i < 3; ++i) {
      for (int r = 0; r < R; ++r) {
	for (int c = 0; c < C; ++c)
	  scanf("%d", &cost[r][c].p[i]);
      }
    }
  
    vector<RC> task(M);
    for (int i = 0; i < M; ++i)
      scanf("%d %d", &task[i].r, &task[i].c);


    vector<vector<vector<vector<int> > > > path(R, vector<vector<vector<int> > >(C, vector<vector<int> >(R, vector<int>(C, INF))));
    for (int r = 0; r < R; ++r) {
      for (int c = 0; c < C; ++c) {
	if (office[r][c] == '#')
	  continue;

	path[r][c][r][c] = 0;
	queue<RC> que;
	vector<vector<int> > visited(R, vector<int>(C, 0));
	que.push(RC(r, c));
	while (!que.empty()) {
	  RC rc = que.front();
	  que.pop();
	  visited[rc.r][rc.c] = 1;
	  for (int d = 0; d < 4; ++d) {
	    int rr = rc.r + dr[d];
	    int cc = rc.c + dc[d];
	    if (rr < 0 || rr >= R || cc < 0 || cc >= C || office[rr][cc] == '#' || visited[rr][cc])
		continue;
	    path[r][c][rr][cc] = path[r][c][rc.r][rc.c]+1;
	    que.push(RC(rr, cc));
	  }
	}
      }
    }


    int time = 0;
    vector<vector<vector<int> > > pass(R, vector<vector<int> >(C));
    for (int i = 0; i < M-1; ++i) {
      RC s = task[i], t = task[i+1];
      while (s.r != t.r || s.c != t.c) {
	pass[s.r][s.c].push_back(time++);
	for (int d = 0; d < 4; ++d) {
	  int rr = s.r + dr[d];
	  int cc = s.c + dc[d];
	  if (rr < 0 || rr >= R || cc < 0 || cc >= C)
	    continue;
	  if (path[rr][cc][t.r][t.c]+1 == path[s.r][s.c][t.r][t.c]) {
	    s.r = rr;
	    s.c = cc;
	    break;
	  }
	}
      }
    }
    // fix
    pass[task[M-1].r][task[M-1].c].push_back(time);

    int ans = 0;
    for (int r = 0; r < R; ++r) {
      for (int c = 0; c < C; ++c) {
	if (pass[r][c].empty())
	  continue;

	const int on_off = cost[r][c].p[ON] + cost[r][c].p[OFF];
	ans += on_off * pass[r][c].size();

	for (unsigned int i = 0; i < pass[r][c].size()-1; ++i) {
	  const int per = (pass[r][c][i+1] - pass[r][c][i]) * cost[r][c].p[PER];
	  if (per < on_off)
	    ans -= (on_off - per);
	}
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
