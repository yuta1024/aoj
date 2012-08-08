#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;

const int INF = 1 << 30;

typedef struct
{
  int x, y;
} Point;

int main()
{
  int x, y;
  while (cin >> x >> y) {
    if ((x|y) == 0)
      break;

    int sx, sy, gx, gy;
    vector<vector<Point> > path(5);
    for (int i = 0; i < y; ++i) {
      string s;
      cin >> s;
      for (int j = 0; j < x; ++j) {
	if (s[j] == 'S') {
	  sx = j;
	  sy = i;
	} else if (s[j] == 'G') {
	  gx = j;
	  gy = i;
	} else if (s[j] != '.') {
	  path[s[j]-'1'].push_back((Point){j, i});
	}
      }
    }
    
    int ans = INF, ansIndex = -1;
    for (int ele = 0; ele < 5; ++ele) {
      vector<vector<int> > dp(5, vector<int>(1000, INF));
      for (int i = 0; i < path[(ele+1)%5].size(); ++i)
	dp[0][i] = abs(sx-path[(ele+1)%5][i].x)+abs(sy-path[(ele+1)%5][i].y);

      for (int i = 0; i < 3; ++i) {
	for (unsigned int j = 0; j < path[(ele+i+1)%5].size(); ++j) {
	  for (unsigned int k = 0; k < path[(ele+i+2)%5].size(); ++k)
	    dp[i+1][k] = min(dp[i+1][k], dp[i][j] + abs(path[(ele+i+1)%5][j].x-path[(ele+i+2)%5][k].x) + abs(path[(ele+i+1)%5][j].y-path[(ele+i+2)%5][k].y));
	}
      }

      for (int i = 0; i < path[(ele+4)%5].size(); ++i)
	dp[4][0] = min(dp[4][0], dp[3][i] + abs(path[(ele+4)%5][i].x-gx) + abs(path[(ele+4)%5][i].y-gy));

      if (dp[4][0] < ans) {
	ans = dp[4][0];
	ansIndex = ele+1;
      }
    }

    if (ans == INF)
      cout << "NA" << endl;
    else
      cout << ansIndex << " " << ans << endl;
  }
  return 0;
}
