#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

class Matatabi
{
public:
  int x1, y1, x2, y2;
  Matatabi(int _x1 = 0, int _y1 = 0, int _x2 = 0, int _y2 = 0)
    :x1(_x1), y1(_y1), x2(_x2), y2(_y2) {}
};

bool isMatatabi(const vector<Matatabi>& m, int x1, int y1, int x2, int y2)
{
  for (unsigned int i = 0; i < m.size(); ++i) {
    if ((m[i].x1 == x1 && m[i].y1 == y1 && m[i].x2 == x2 && m[i].y2 == y2) ||
	(m[i].x1 == x2 && m[i].y1 == y2 && m[i].x2 == x1 && m[i].y2 == y1))
      return true;
  }
  return false;
}

int main()
{
  int T;
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    int gx, gy;
    scanf("%d %d", &gx, &gy);
    int p;
    scanf("%d", &p);
    vector<Matatabi> m;
    for (int i = 0; i < p; ++i) {
      int x1, y1, x2, y2;
      scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
      m.push_back(Matatabi(x1, y1, x2, y2));
    }

    vector<vector<int> > dp(gy+1, vector<int>(gx+1, 0));
    dp[0][0] = 1;
    for (int i = 0; i <= gy; ++i) {
      for (int j = 0; j <= gx; ++j) {
	if (i == 0 && j == 0)
	  continue;
	if (i != 0) {
	  if (!isMatatabi(m, j, i-1, j, i))
	      dp[i][j] += dp[i-1][j];
	}
	if (j != 0) {
	  if (!isMatatabi(m, j-1, i, j, i))
	    dp[i][j] += dp[i][j-1];
	}
      }
    }

    if (dp[gy][gx] == 0)
      printf("Miserable Hokusai!\n");
    else
      printf("%d\n", dp[gy][gx]);
  }
  return 0;
}
