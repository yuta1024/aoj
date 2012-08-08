#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int dx[4][3] = { {1, 2, 3}, {0, 0, 0}, {-1, -2, -3}, {0, 0, 0} };
int dy[4][3] = { {0, 0, 0}, {1, 2, 3}, {0, 0, 0}, {-1, -2, -3} };

int main()
{
  int n;
  cin >> n;
  for (int t = 1; t <= n; ++t) {
    int x, y;
    vector<string> field(8);
    for (int i = 0; i < 8; ++i)
      cin >> field[i];
    cin >> x >> y;
    --x;
    --y;

    queue<pair<int, int> > que;
    que.push(pair<int, int>(x, y));
    while (!que.empty()) {
      const pair<int, int> p = que.front();
      que.pop();
      field[p.second][p.first] = '0';

      for (int d = 0; d < 4; ++d) {
	for (int k = 0; k < 3; ++k) {
	  pair<int, int> pp(pair<int, int>(p.first+dx[d][k], p.second+dy[d][k]));
	  if (pp.first < 0 || 8 <= pp.first ||
	      pp.second < 0 || 8 <= pp.second|| 
	      field[pp.second][pp.first] == '0')
	    continue;
	  que.push(pp);
	}
      }
    }

    cout << "Data " << t << ":" << endl;
    for (int i = 0; i < 8; ++i)
      cout << field[i] << endl;
  }
  return 0;
}
