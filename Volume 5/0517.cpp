#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  int n, k;
  while (scanf("%d %d", &n, &k)) {
    if ((n|k) == 0)
      break;

    bool blank = false;
    vector<int> num(n+2, 0);
    for (int i = 0; i < k; ++i) {
      int m;
      scanf("%d", &m);
      if (m == 0)
	blank = true;
      else
	++num[m];
    }

    int ans = 0;
    if (blank) {
      int cnt = 0, prev = 0;
      for (int i = 0; i <= n+1; ++i) {
	if (num[i]) {
	  ++cnt;
	} else {
	  ans = max(ans, cnt);
	  cnt = i - prev;
	  prev = i;
	}
      }
    } else {
      int cnt = 0;
      for (int i = 0; i <= n+1; ++i) {
	if (num[i]) {
	  ++cnt;
	} else {
	  ans = max(ans, cnt);
	  cnt = 0;
	}
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
