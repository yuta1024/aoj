#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <cstdio>
using namespace std;

const int INF = 1 << 30;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

typedef struct
{
  int xl, xr, cnt;
  vector<pair<int, int> > block;
  double g;
} Piece;

int main()
{
  int w, h;
  while (cin >> w >> h) {
    if ((w|h) == 0)
      break;

    vector<string> p(h);
    for (int i = 0; i < h; ++i)
      cin >> p[i];
    
    vector<Piece> pieces;
    for (int y = 0; y < h; ++y) {
      for (int x = 0; x < w; ++x) {
	if (p[y][x] != '.') {
	  char s = p[y][x];
	  Piece piece;
	  queue<pair<int, int> > que;
	  que.push(make_pair(x, y));
	  while (!que.empty()) {
	    const pair<int ,int> q = que.front();
	    que.pop();
	    
	    if (p[q.second][q.first] != s)
	      continue;
	    
	    piece.block.push_back(q);
	    p[q.second][q.first] = '.';
	    for (int d = 0; d < 4; ++d) {
	      int xx = q.first + dx[d];
	      int yy = q.second + dy[d];
	      if (xx < 0 || w <= xx || yy < 0 || h <= yy || p[yy][xx] != s)
		continue;
	      que.push(make_pair(xx, yy));
	    }
	  }
	  piece.cnt = piece.block.size();
	  piece.g = 0.0;
	  for (unsigned int i = 0; i < piece.block.size(); ++i)
	    piece.g += piece.block[i].first + 0.5;
	  pieces.push_back(piece);
	}
      }
    }
    
    vector<vector<int> > path(pieces.size(), vector<int>(pieces.size(), 0));
    for (unsigned int i = 0; i < pieces.size(); ++i) {
      pieces[i].xl = INF;
      pieces[i].xr = -INF;
      for (unsigned int j = 0; j < pieces[i].block.size(); ++j) {
	for (unsigned int k = 0; k < pieces.size(); ++k) {
	  if (i == k)
	    continue;
	  for (unsigned int l = 0; l < pieces[k].block.size(); ++l) {
	    if (pieces[i].block[j].first == pieces[k].block[l].first &&
		pieces[i].block[j].second+1 == pieces[k].block[l].second) {
	      path[i][k] = 1;
	      pieces[i].xl = min(pieces[i].xl, pieces[i].block[j].first);
	      pieces[i].xr = max(pieces[i].xr, pieces[i].block[j].first+1);
	    }
	  }
	}
      }

      if (pieces[i].xl == INF && pieces[i].xr == -INF) {
	for (unsigned int j = 0; j < pieces[i].block.size(); ++j) {
	  if (pieces[i].block[j].second == h-1) {
	    pieces[i].xl = min(pieces[i].xl, pieces[i].block[j].first);
	    pieces[i].xr = max(pieces[i].xr, pieces[i].block[j].first+1);
	  }
	}
      }
    }
    
    /*
    for (int i = 0; i < pieces.size(); ++i) {
      printf("xl = %d, xr = %d, g = %.1f\n", pieces[i].xl, pieces[i].xr, pieces[i].g);
      for (int j = 0; j < pieces[i].block.size(); ++j)
	printf(" -> (%d, %d)\n", pieces[i].block[j].first, pieces[i].block[j].second);
    }
    */
    
    queue<unsigned int> que;
    for (unsigned int i = 0; i < pieces.size(); ++i) {
      int valid = true;
      for (unsigned int j = 0; j < pieces.size(); ++j) {
	if (path[j][i])
	  valid = false;
      }
      if (valid)
	que.push(i);
    }


    bool stable = true;
    vector<int> used(pieces.size(), 0);
    while (!que.empty() && stable) {
      int v = que.front();
      que.pop();

      if (used[v])
	continue;

      used[v] = 1;
      if (pieces[v].xl < pieces[v].g / pieces[v].cnt &&
	  pieces[v].g / pieces[v].cnt < pieces[v].xr) {

	for (unsigned int i = 0; i < pieces.size(); ++i) {
	  if (path[v][i]) {
	    path[v][i] = 0;
	    pieces[i].g += pieces[v].g;
	    pieces[i].cnt += pieces[v].cnt;
	  }
	}

	for (unsigned int i = 0; i < pieces.size(); ++i) {
	  if (used[i])
	    continue;
	  int valid = true;
	  for (unsigned int j = 0; j < pieces.size(); ++j) {
	    if (path[j][i])
	      valid = false;
	  }
	  if (valid)
	    que.push(i);
	}

      } else {
	stable = false;
      }
    }

    if (stable)
      puts("STABLE");
    else
      puts("UNSTABLE");
  }
  return 0;
}
