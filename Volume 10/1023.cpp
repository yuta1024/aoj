#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
  int AN, BN, R;
  while (~scanf("%d %d %d", &AN, &BN, &R)) {
    if ((AN|BN) == 0)
      break;

    vector<vector<int> > A(10000);
    for (int i = 0; i < AN; ++i) {
      int x, y;
      scanf("%d %d", &x, &y);
      A[y].push_back(x);
    }

    for (unsigned int i = 0; i < A.size(); ++i)
      sort(A[i].begin(), A[i].end());

    int ans = 0;
    for (int i = 0; i < BN; ++i) {
      int x, y;
      scanf("%d %d", &x, &y);
      for (int j = y-4*R; j <= y+4*R; ++j) {
	if (j < 0 || 10000 <= j || A[j].empty())
	  continue;
	int target = (int)sqrt(16.0*R*R - (y-j)*(y-j));
	ans += upper_bound(A[j].begin(), A[j].end(), x+target) - lower_bound(A[j].begin(), A[j].end(), x-target);
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
