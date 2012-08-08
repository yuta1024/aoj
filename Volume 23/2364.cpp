#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int main()
{
  int W, H;
  while (cin >> W >> H) {
    vector<string> map(H);
    pair<int, int> target;
    for (int i = 0; i < H; ++i) {
      cin >> map[i];
      if (map[i].find_first_of("t") != string::npos) {
	target.first = map[i].find_first_of("t");
	target.second = i;
      }
    }

    vector<vector<int> > valid(H, vector<int>(W, 0));
    queue<pair<int, int> > que;
    que.push(make_pair(0, 0));
    while (!que.empty()) {
      const pair<int, int> p = que.front();
      que.pop();

      if (valid[p.second][p.first])
	continue;

      valid[p.second][p.first] = 1;
      for (int d = 0; d < 4; ++d) {
	pair<int, int> pp = make_pair(p.first+dx[d], p.second+dy[d]);
	if (pp.first < 0 || pp.first >= W ||
	    pp.second < 0 || pp.second >= H ||
	    map[pp.second][pp.first] == '#' ||
	    valid[pp.second][pp.first])
	  continue;
	que.push(pp);
      }
    }

    int N, ans = -1;
    if (valid[target.second][target.first])
      ans = 0;

    cin >> N;
    for (int i = 0; i < N; ++i) {
      int x, y;
      cin >> x >> y;
      if (ans != 0 && map[y][x] == '#') {
	map[y][x] = '.';
	for (int d = 0; d < 4; ++d) {
	  pair<int, int> p = make_pair(x+dx[d], y+dy[d]);
	  if (p.first < 0 || p.first >= W ||
	      p.second < 0 || p.second >= H ||
	      map[p.second][p.first] == '#' ||
	      !valid[p.second][p.first])
	    continue;
	  que.push(p);
	  valid[p.second][p.first] = 0;
	}

	while (!que.empty()) {
	  const pair<int, int> p = que.front();
	  que.pop();
	  
	  if (valid[p.second][p.first])
	    continue;
	  
	  valid[p.second][p.first] = 1;
	  for (int d = 0; d < 4; ++d) {
	    pair<int, int> pp = make_pair(p.first+dx[d], p.second+dy[d]);
	    if (pp.first < 0 || pp.first >= W ||
		pp.second < 0 || pp.second >= H ||
		map[pp.second][pp.first] == '#' ||
		valid[pp.second][pp.first])
	      continue;
	    que.push(pp);
	  }
	}
	
	if (ans == -1 && valid[target.second][target.first])
	  ans = i+1;
      }
    }
    
    cout << ans << endl;
  }
  return 0;
}
