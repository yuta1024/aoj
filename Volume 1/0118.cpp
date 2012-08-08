#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int main()
{
  int H, W;
  while (~scanf("%d %d", &H, &W)) {
    if ((H|W) == 0)
      break;

    vector<string> orc(H);
    for (int i = 0; i < H; ++i)
      cin >> orc[i];

    int ans = 0;
    vector< vector<int> > visited(H, vector<int>(W, 0));
    for (int i = 0; i < H; ++i) {
      for (int j = 0; j < W; ++j) {
	if (visited[i][j])
	  continue;

	++ans;
	char fruit = orc[i][j];
	queue< pair<int, int> > que;
	que.push(pair<int, int>(i, j));
	while (!que.empty()) {
	  const pair<int, int> p = que.front();
	  que.pop();

	  if (visited[p.first][p.second])
	    continue;

	  visited[p.first][p.second] = 1;
	  for (int d = 0; d < 4; ++d) {
	    pair<int, int> pp = p;
	    pp.first += dy[d];
	    pp.second += dx[d];
	    if (pp.first < 0 || H <= pp.first ||
		pp.second < 0 || W <= pp.second ||
		visited[pp.first][pp.second] ||
		orc[pp.first][pp.second] != fruit)
	      continue;
	    que.push(pp);
	  }
	}
      }
    }
    cout << ans << endl;
  }
  return 0;
}
