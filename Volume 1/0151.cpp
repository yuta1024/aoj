#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
  int n;
  while (cin >> n) {
    if (n == 0)
      break;

    vector<string> mass(n);
    for (int i = 0; i < n; ++i)
      cin >> mass[i];

    int ans = 0;
    for (int i = 0; i < n; ++i) {
      vector<int> sum(6, 0);
      // hor, ver
      for (int j = 0; j < n; ++j) {
	if (mass[i][j] == '1') {
	  ++sum[0];
	  ans = max(ans, sum[0]);
	} else {
	  sum[0] = 0;
	}

	if (mass[j][i] == '1') {
	  ++sum[1];
	  ans = max(ans, sum[1]);
	} else {
	  sum[1] = 0;
	}
      }
 
      // diag
      for (int j = 0; i+j < n; ++j) {
	if (mass[i+j][j] == '1') {
	  ++sum[2];
	  ans = max(ans, sum[2]);
	} else {
	  sum[2] = 0;
	}

	if (mass[n-1-i-j][j] == '1') {
	  ++sum[3];
	  ans = max(ans, sum[3]);
	} else {
	  sum[3] = 0;
	}

	if (mass[n-1-i-j][n-1-j] == '1') {
	  ++sum[4];
	  ans = max(ans, sum[4]);
	} else {
	  sum[4] = 0;
	}

	if (mass[i+j][n-1-j] == '1') {
	  ++sum[5];
	  ans = max(ans, sum[5]);
	} else {
	  sum[5] = 0;
	}
      }
    }

    cout << ans << endl;
  }
  return 0;
}
