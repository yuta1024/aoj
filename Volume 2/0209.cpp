#include <iostream>
#include <vector>
using namespace std;

const int INF = 1 << 30;

int main()
{
  int n, m;
  while (cin >> n >> m) {
    if ((n|m) == 0)
      break;

    vector<vector<int> > scene(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j)
	cin >> scene[i][j];
    }

    vector<vector<int> > pic(m, vector<int>(m));
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < m; ++j)
	cin >> pic[i][j];
    }

    int ans_x = INF, ans_y = INF;
    for (int r = 0; r < 4; ++r) {
      for (int i = 0; i <= n-m; ++i) {
	for (int j = 0; j <= n-m; ++j) {
	  
	  bool valid = true;
	  int vx = INF, vy = INF;
	  for (int y = 0; y < m && valid; ++y) {
	    for (int x = 0; x < m && valid; ++x) {
	      if (pic[y][x] != -1) {
		if (vx == INF) {
		  vx = x+j;
		  vy = y+i;
		}
		if (pic[y][x] != scene[i+y][j+x])
		  valid = false;
	      }
	    }
	  }

	  if (valid) {
	    if (ans_y > vy) {
	      ans_y = vy;
	      ans_x = vx;
	    } else if (ans_y == vy && ans_x > vx) {
	      ans_x = vx;
	    }
	  }	  
	}
      }

      vector<vector<int> > tmp = pic;
      for (int i = 0; i < m; ++i) {
	for (int j = 0; j < m; ++j)
	  pic[i][j] = tmp[j][m-i-1];
      }
    }

    if (ans_x != INF)
      cout << ans_x+1 << " " << ans_y+1 << endl;
    else
      cout << "NA" << endl;
  }
  return 0;
}
