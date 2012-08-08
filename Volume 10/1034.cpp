#include <iostream>
#include <vector>
using namespace std;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int n;

bool solve(int x, int y, int idx, int sum, int all, vector<vector<int> >& visited, const vector<vector<int> >&p, const vector<pair<int, int> >& s)
{

  //printf("%d %d %d %d %d\n", x, y, idx, sum, all);

  if (all == n*n && idx >= s.size())
    return true;

  if (idx >= s.size())
    return false;

  if (-p[s[idx].second][s[idx].first] == sum)
    return solve(s[idx+1].first, s[idx+1].second, idx+1, 0, all, visited, p, s);

  for (int d = 0; d < 4; ++d) {
    int xx = x + dx[d];
    int yy = y + dy[d];
    if (xx < 0 || n <= xx || yy < 0 || n <= yy || visited[yy][xx] ||
	sum+p[yy][xx] > -p[s[idx].second][s[idx].first])
      continue;
    visited[yy][xx] = 1;
    if (solve(xx, yy, idx, sum+p[yy][xx], all+1, visited, p, s))
      return true;
    visited[yy][xx] = 0;
  }

  return false;
}

int main()
{
  while (cin >> n) {
    if (n == 0)
      break;

    vector<vector<int> > p(n, vector<int>(n)), visited(n, vector<int>(n, 0));
    vector<pair<int, int> > s;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
	cin >> p[i][j];
	if (p[i][j] < 0) {
	  s.push_back(make_pair(j, i));
	  visited[i][j] = 1;
	}
      }
    }

    if (solve(s[0].first, s[0].second, 0, 0, (int)s.size(), visited, p, s))
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
