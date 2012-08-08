#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  string s, t;
  while (cin >> s >> t) {
    short int ans = 0;
    vector<vector<short int> > dp(s.size()+1, vector<short int>(t.size()+1, 0));
    for (unsigned int i = 0; i < s.size(); ++i) {
      for (unsigned int j = 0; j < t.size(); ++j) {
	if (s[i] == t[j]) {
	  dp[i+1][j+1] = dp[i][j]+1;
	  ans = max(ans, dp[i+1][j+1]);
	}
      }
    }
    cout << ans << endl;
  }
  return 0;
}
