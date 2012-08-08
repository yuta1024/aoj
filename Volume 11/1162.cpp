#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 30;

typedef struct Edge
{
  int d, c;
};

class State
{
public:
  int nc, pc, nv;
  double nt;

  State() {}
  State(int a, int b, int c, double d)
    :nc(a), pc(b), nv(c), nt(d) {}

  inline void set(int a, int b, int c, double d)
  {
    nc = a;
    pc = b;
    nv = c;
    nt = d;
  }

  bool operator <(const State& rhs) const
  {
    return this->nt > rhs.nt;
  }

};

int main()
{
  int n, m, s, g;
  Edge cost[MAX][MAX];
  double time[MAX][MAX][MAX+1];
  bool visited[MAX][MAX][MAX+1];

  while (scanf("%d %d", &n, &m) != EOF) {
    if (n == 0 && m == 0)
      break;

    scanf("%d %d", &s, &g);
    --s;
    --g;

    for (int i = 0; i < MAX; ++i) {
      for (int j = 0; j < MAX; ++j)
	cost[i][j].d = cost[i][j].c = -1;
    }

    for (int i = 0; i < m; ++i) {
      int x, y, d, c;
      scanf("%d %d %d %d", &x, &y, &d, &c);
      --x;
      --y;
      cost[x][y].d = cost[y][x].d = d;
      cost[x][y].c = cost[y][x].c = c;
    }

    for (int i = 0; i < MAX; ++i) {
      for (int j = 0; j < MAX; ++j) {
	for (int k = 0; k < MAX+1; ++k) {
	  time[i][j][k] = 999999999.0;
	  visited[i][j][k] = false;
	}
      }
    }
    time[s][s][0] = 0.0;

    
    double ans = -1.0;
    priority_queue<State> que;
    State st(s, s, 0, 0.0), q;
    que.push(st);

    while (!que.empty()) {
      st = que.top();
      que.pop();

      if (st.nc == g && st.nv == 1) {
	ans = st.nt;
	break;
      }

      visited[st.nc][st.pc][st.nv] = true;
      for (int i = 0; i < n; ++i) {
	if (i == st.nc || i == st.pc || cost[st.nc][i].d == -1)
	  continue;
	for (int j = st.nv-1; j < st.nv+2; ++j) {
	  if (j > 0 && cost[st.nc][i].c >= j) {
	    double tmp = st.nt + cost[st.nc][i].d / (double)j;
	    if (time[i][st.nc][j] > tmp) {
	      time[i][st.nc][j] = tmp;
	      q.set(i, st.nc, j, tmp);
	      que.push(q);
	    }
	  }
	}
      }

    }

    if (ans == -1.0)
      printf("unreachable\n");
    else
      printf("%.5f\n", ans);
  }

  return 0;
}




    /*
    for ( ; ; ) {
      int nc = 0, pc = 0, nv = 0;
      double nt = INF_D;

      for (unsigned int i = 0; i < n; ++i) {
	for (unsigned int j = 0; j < n; ++j) {
	  for (unsigned int k = 0; k < MAX+1; ++k) {
	    if (!visited[i][j][k] && time[i][j][k] < nt) {
	      nc = i;
	      pc = j;
	      nv = k;
	      nt = time[i][j][k];
	    }
	  }
	}
      }

      if (nt == INF_D) {
	printf("unreachable\n");
	break;
      } else if (nc == g && nv == 1) {
	printf("%.5f\n", nt);
	break;
      }

      visited[nc][pc][nv] = 1;
      for (int i = 0; i < n; ++i) {
	if (pc == i || cost[nc][i].d == INF_I)
	  continue;
	for (int j = nv-1; j < nv+2; ++j) {
	  if (j > 0 && cost[nc][i].c >= j) {
	    time[i][nc][j] = min(time[i][nc][j], nt+cost[nc][i].d/(double)j);
	  }
	}
      }
    }
    */
