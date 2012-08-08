#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1 << 30;
const int C[] = {1, 5, 10, 50, 100, 500};

int main()
{
  vector<int> dp(666000+1, 0);
  for (int i = 0; i < dp.size(); ++i) {
    int pay = i;
    for (int j = 5; j >= 0; --j) {
      int k = pay / C[j];
      pay -= k * C[j];
      dp[i] += k;
    }
  }

  int P;
  while (cin >> P) {
    if (P == 0)
      break;

    int sum = 0;
    vector<int> N(6);
    for (int i = 0; i < 6; ++i) {
      cin >> N[i];
      sum += C[i] * N[i];
    }

    int ans = INF;
    for (int i = P; i <= sum; ++i) {
      int pay = i, num = 0;
      for (int j = 5; j >= 0; --j) {
	int k = min(pay / C[j], N[j]);
	pay -= k * C[j];
	num += k;
      }

      if (pay != 0)
	continue;

      ans = min(ans, num+dp[i-P]);
    }
    cout << ans << endl;
  }
  return 0;
}
