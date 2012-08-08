#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;

class Rect
{
public:
  int pos, height;
  Rect(int _pos, int _height)
    :pos(_pos), height(_height) {}
};

int main()
{
  int H, W;
  while (cin >> H >> W) {
    if ((H|W) == 0)
      break;

    vector<string> rec(H);
    for (int i = 0; i < H; ++i)
      cin >> rec[i];

    vector<vector<int> > dp(H, vector<int>(W+1, 0));
    for (int i = 0; i < H; ++i) {
      for (int j = 0; j < W; ++j) {
	if (rec[i][j] == '*')
	  continue;
	if (i == 0)
	  dp[i][j] = 1;
	else
	  dp[i][j] = dp[i-1][j]+1;
      }
    }

    int ans = 0;
    for (int i = 0; i < H; ++i) {
      stack<Rect> stk;
      for (int j = 0; j <= W; ++j) {
	if (stk.empty()) {
	  stk.push(Rect(j, dp[i][j]));
	} else {
	  if (stk.top().height < dp[i][j]) {
	    stk.push(Rect(j, dp[i][j]));
	  } else if (stk.top().height > dp[i][j]) {
	    int pos = j;
	    while (!stk.empty() && stk.top().height > dp[i][j]) {
	      const Rect rec = stk.top();
	      stk.pop();
	      ans = max(ans, rec.height * (j-rec.pos));
	      pos = rec.pos;
	    }
	    stk.push(Rect(pos, dp[i][j]));
	  }
	}
      }
    }

    cout << ans << endl;
  }
  return 0;
}
