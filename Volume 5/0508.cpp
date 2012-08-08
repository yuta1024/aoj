#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int> > E(100);
bool visited[100];

int solve(const int v)
{
  int res = 0;
  visited[v] = true;
  for (vector<int>::iterator it = E[v].begin(); it != E[v].end(); ++it) {
    if (!visited[*it]) {
      visited[*it] = true;
      res = max(res, solve(*it)+1);
      visited[*it] = false;
    }
  }
  visited[v] = false;
  return res;
}

int main()
{
  int n;
  while (scanf("%d", &n)) {
    if (n == 0)
      break;

    for (int i = 0; i < 100; ++i)
      E[i].clear();

    for (int i = 0; i < n; ++i) {
      int a, b;
      scanf("%d %d", &a, &b);
      --a;
      --b;
      E[a].push_back(b);
      E[b].push_back(a);
    }

    int ans = 0;
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < 100; ++i)
      ans = max(ans, solve(i));

    printf("%d\n", ans+1);
  }
  return 0;
}
