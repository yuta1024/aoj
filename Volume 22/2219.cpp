#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef struct
{
  int C, VDL[3];
} Bydol;

int main()
{
  int N, M;
  while (cin >> N >> M) {
    string tmp;
    getline(cin, tmp);

    vector<Bydol> bydol(N);
    for (int i = 0; i < N; ++i) {
      getline(cin, tmp);
      cin >> bydol[i].C >> bydol[i].VDL[0] >> bydol[i].VDL[1] >> bydol[i].VDL[2];
      getline(cin, tmp);
    }

    int ans = 0;
    for (int i = 0; i < 3; ++i) {
      vector<vector<int> > dp(N+1, vector<int>(M+1, 0));
      for (int j = 0; j < N; ++j) {
	for (int k = 0; k < M+1; ++k) {
	  if (k < bydol[j].C)
	    dp[j+1][k] = dp[j][k];
	  else
	    dp[j+1][k] = max(dp[j][k], dp[j+1][k-bydol[j].C]+bydol[j].VDL[i]);
	}
      }
      ans = max(ans, dp[N][M]);
    }
    cout << ans << endl;
  }
  return 0;
}
