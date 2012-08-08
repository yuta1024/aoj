#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

const int INF = 1 << 30;

class Edge
{
public:
  int to, cap, rev, idx;
  bool isRev;
  Edge(int _to = 0, int _cap = 0, int _rev = 0, int _idx = 0, bool _isRev = false)
    :to(_to), cap(_cap), rev(_rev), idx(_idx), isRev(_isRev) {} 
};

void add_edge(vector<vector<Edge> >& g, int from, int to, int cap, int idx, bool isRev)
{
  g[from].push_back(Edge(to, cap, g[to].size(), idx, isRev));
  g[to].push_back(Edge(from, 0, g[from].size()-1, idx, isRev));
}

int ff(vector<vector<Edge> >& g, vector<int>& used, int s, int t, int f, set<int>& rev)
{
  if (s == t)
    return f;
  used[s] = 1;
  
  for (unsigned int i = 0; i < g[s].size(); ++i) {
    Edge& e = g[s][i];
    if (!used[e.to] && e.cap > 0) {
      int d = ff(g, used, e.to, t, min(f, e.cap), rev);
      if (d > 0) {
	if (e.isRev)
	  rev.insert(e.idx);
	e.cap -= d;
	g[e.to][e.rev].cap += d;
	return d;
      }
    }
  }
  return 0;
}

int solve(vector<vector<Edge> >& g, int s, int t, set<int>& rev)
{
  int flow = 0;
  for ( ; ; ) {
    vector<int> used(g.size(), 0);
    int f = ff(g, used, s, t, INF, rev);
    if (f == 0)
      return flow;
    flow += f;
  }
}

int main()
{
  int N, M;
  while (~scanf("%d %d", &N, &M)) {
    vector<vector<Edge> > g(N);
    for (int i = 0; i < M; ++i) {
      int X, Y;
      scanf("%d %d", &X, &Y);
      --X;
      --Y;
      add_edge(g, X, Y, 1, i+1, false);
      add_edge(g, Y, X, 1, i+1, true);
    }
    int S, T;
    scanf("%d %d", &S, &T);
    --S;
    --T;

    set<int> rev;
    printf("%d\n", solve(g, S, T, rev));
    printf("%d\n", rev.size());
    for (set<int>::iterator it = rev.begin(); it !=  rev.end(); ++it)
      printf("%d\n", *it);
  }
  return 0;
}
