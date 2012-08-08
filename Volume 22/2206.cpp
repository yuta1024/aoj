#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int main()
{
  int T;
  while (cin >> T) {
    for (int t = 0; t < T; ++t) {
      vector<string> puyo(12);
      for (int i = 0; i < 12; ++i)
	cin >> puyo[i];

      int ans = 0;
      for ( ; ; ) {
	bool update = false;
	vector<vector<int> > visited(puyo.size(), vector<int>(puyo[0].size(), 0));
	for (unsigned int i = 0; i < puyo.size(); ++i) {
	  for (unsigned int j = 0; j < puyo[0].size(); ++j) {
	    if (puyo[i][j] != '.' && puyo[i][j] != 'O' && !visited[i][j]) {
	      int cnt = 0;
	      queue<pair<int, int> > que;
	      que.push(pair<int, int>(i, j));
	      while (!que.empty()) {
		const pair<int, int> p = que.front();
		que.pop();

		++cnt;
		visited[p.first][p.second] = 1;
		for (int d = 0; d < 4; ++d) {
		  int ii = p.first + dy[d];
		  int jj = p.second + dx[d];
		  if (ii < 0 || ii >= puyo.size() || jj < 0 || jj >= puyo[0].size() || puyo[ii][jj] != puyo[i][j] || visited[ii][jj])
		      continue;
		  que.push(pair<int, int>(ii, jj));
		}
	      }
	      if (cnt >= 4) {
		update = true;
		char color = puyo[i][j];
		que.push(pair<int, int>(i, j));
		vector<vector<int> > deleted(puyo.size(), vector<int>(puyo[0].size(), 0));
		while (!que.empty()) {
		  const pair<int, int> p = que.front();
		  que.pop();

		  puyo[p.first][p.second] = '.';
		  deleted[p.first][p.second] = 1;
		  for (int d = 0; d < 4; ++d) {
		    int ii = p.first + dy[d];
		    int jj = p.second + dx[d];
		    if (ii < 0 || ii >= puyo.size() || jj < 0 || jj >= puyo[0].size() || deleted[ii][jj])
		      continue;
		    
		    if (puyo[ii][jj] == color) {
		      que.push(pair<int, int>(ii, jj));
		    } else if (puyo[ii][jj] == 'O')
		      puyo[ii][jj] = '.';
		  }
		}
	      }
	    }
	  }
	}

	if (!update)
	  break;

	++ans;
	for (int i = puyo.size()-1; i >= 0; --i) {
	  for (unsigned int j = 0; j < puyo[0].size(); ++j) {
	    if (puyo[i][j] != '.') {
	      int ii = i + 1;
	      while (ii < puyo.size() && puyo[ii][j] == '.')
		++ii;
	      swap(puyo[i][j], puyo[ii-1][j]);
	    }
	  }
	}
      }
      cout << ans << endl;
    }
  }
  return 0;
}
