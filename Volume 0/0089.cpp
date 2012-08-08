#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main()
{
  string line;
  vector<vector<int> > d;
  int size = 0;
  while (getline(cin, line)) {
    vector<int> tmp;
    string::size_type b = 0, e = 0;
    do {
      e = line.find_first_of(",", b);
      tmp.push_back(atoi(line.substr(b, e-b).c_str()));
      b = e + 1;
    } while (e != string::npos);
    d.push_back(tmp);
    size = max(size, (int)tmp.size());
  }

  vector<vector<int> > dp(d.size()+1, vector<int>(size, 0));
  dp[0][0] = d[0][0];
  for (int i = 0; i < d.size(); ++i) {
    for (int j = 0; j < d[i].size(); ++j) {
      if (d[i].size() < d[i+1].size()) {
	dp[i+1][j] = max(dp[i+1][j], dp[i][j]+d[i+1][j]);
	dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]+d[i+1][j+1]);
      } else {
	if (j-1 >= 0)
	  dp[i+1][j-1] = max(dp[i+1][j-1], dp[i][j]+d[i+1][j-1]);
	if (j < d[i+1].size())
	  dp[i+1][j] = max(dp[i+1][j], dp[i][j]+d[i+1][j]);
      }
    }
  }

  cout << dp[d.size()-1][0] << endl;
  return 0;
}
