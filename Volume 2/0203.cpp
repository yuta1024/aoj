#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int X, Y;
  while (cin >> X >> Y) {
    if ((X|Y) == 0)
      break;

    vector<vector<int> > cource(Y+1, vector<int>(X, 0));
    for (int i = 0; i < Y; ++i) {
      for (int j = 0; j < X; ++j)
	cin >> cource[i][j];
    }

    vector<vector<int> > dp(Y+1, vector<int>(X, 0));
    for (int i = 0; i < X; ++i) {
      if (cource[0][i] == 0)
	dp[0][i] = 1;
    }

    for (int i = 0; i < Y-1; ++i) {
      for (int j = 0; j < X; ++j) {
	if (cource[i][j] == 0) {
	  if (cource[i+1][j] != 1)
	    dp[i+1][j] += dp[i][j];
	  if (j-1 >= 0 && cource[i+1][j-1] == 0)
	    dp[i+1][j-1] += dp[i][j];
	  if (j+1 < X && cource[i+1][j+1] == 0)
	    dp[i+1][j+1]+= dp[i][j];
	} else if (cource[i][j] == 2 && cource[i+2][j] != 1) {
	    dp[i+2][j] += dp[i][j];
	}
      }
    }

    int ans = 0;
    for (int i = 0; i < X; ++i) {
	ans += dp[Y-1][i];
	ans += dp[Y][i];
    }
    cout << ans << endl;
  }
  return 0;
}
