#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1 << 30;

pair<int, vector<int> > solve(int v, vector<vector<int> >& visited, const vector<vector<int> >& path)
{
  pair<int, vector<int> > res = make_pair(0, vector<int>(1, v+1));
  for (int i = 0; i < path[v].size(); ++i) {
    if (!visited[min(v, i)][max(v, i)] && path[v][i] != INF) {
      visited[min(v, i)][max(v, i)] = 1;
      pair<int, vector<int> > tmp = solve(i, visited, path);
      tmp.first += path[v][i];
      tmp.second.push_back(v+1);
      if (tmp.first > res.first)
	res = tmp;
      visited[min(v, i)][max(v, i)] = 0;
    }
  }
  return res;
}

int main()
{
  int ns, nl;
  while (cin >> ns >> nl) {
    if ((ns|nl) == 0)
      break;

    vector<vector<int> > path(ns+1, vector<int>(ns+1, INF));
    for (int i = 0; i < nl; ++i) {
      int s1, s2, d;
      cin >> s1 >> s2 >> d;
      path[s1-1][s2-1] = path[s2-1][s1-1] = d;
    }

    for (int i = 0; i < ns; ++i)
      path[ns][i] = 0;

    vector<vector<int> > visited(ns+1, vector<int>(ns+1, 0));
    pair<int, vector<int> > ans = solve(ns, visited, path);
    cout << ans.first << endl;
    reverse(ans.second.begin(), ans.second.end());
    for (int i = 1; i < ans.second.size()-1; ++i)
      cout << ans.second[i] << " ";
    cout << ans.second.back() << endl;
  }
  return 0;
}
