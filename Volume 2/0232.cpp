#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  int X, Y, Z;
  while (cin >> X >> Y >> Z) {
    if ((X|Y|Z) == 0)
      break;

    vector<int> V(X);
    for (int i = 0; i < X; ++i)
      cin >> V[i];

    vector<pair<int, int> > E(Y+1, make_pair(0, 0));
    for (int i = 0; i < Z; ++i) {
      int N;
      cin >> N;
      cin >> E[N].first >> E[N].second;
    }

    const int MAX_MONEY = 5000+1;
    vector<vector<double> > dp(Y+1, vector<double>(MAX_MONEY, 0.0));
    dp[0][0] = 1.0;
    for (int i = 0; i < Y; ++i) {
      for (int j = 0; j < MAX_MONEY; ++j) {
	for (int k = 0; k < X; ++k) {
	  int next_pos = min(i+V[k], Y);
	  int next_money = j;
	  if (E[next_pos].first == 1)
	    dp[min(next_pos+E[next_pos].second, Y)][j] += dp[i][j] / X;
	  else if (E[next_pos].first == 2)
	    dp[next_pos][j+E[next_pos].second] += dp[i][j] / X;
	  else if (E[next_pos].first == 3)
	    dp[next_pos][max(j-E[next_pos].second, 0)] += dp[i][j] / X;
	  else
	    dp[next_pos][j] += dp[i][j] / X;
	}
      }
    }

    double ans = 0.0;
    for (int i = 0; i < MAX_MONEY; ++i)
      ans += dp[Y][i] * i;
    cout << static_cast<int>(ans) << endl;
  }
  return 0;
}
