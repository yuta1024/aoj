#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int ans = 0;
bool dp[1 << 24];

typedef struct
{
  bool used;
  int color, piled;
} Circle;

void solve(vector<Circle>& circle, int bit)
{
  ans = max(ans, __builtin_popcount(bit));
  if (dp[bit])
    return;

  dp[bit] = true;
  for (unsigned int i = 0; i < circle.size(); ++i) {
    if ((circle[i].piled & bit) == circle[i].piled && (~bit & (1 << i))) {

      for (unsigned int j = i+1; j < circle.size(); ++j) {
	if ((circle[j].piled & bit) == circle[j].piled && (~bit & (1 << j)) && circle[i].color == circle[j].color) {
	  solve(circle, bit | (1 << i) | (1 << j));
	}
      }

    }
  }
}

int main()
{
  int n;
  while (~scanf("%d", &n)) {
    if (n == 0)
      break;

    vector<int> x(n), y(n), r(n), c(n);
    for (int i = 0; i < n; ++i)
      scanf("%d %d %d %d", &x[i], &y[i], &r[i], &c[i]);

    vector<Circle> circle(n);
    for (int i = n-1; i >= 0; --i) {
      circle[i].color = c[i];
      circle[i].piled = 0;
      for (int j = i-1; j >= 0; --j) {
	if ((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]) < (r[i]+r[j])*(r[i]+r[j]))
	  circle[i].piled |= (1 << j);
      }
    }

    ans = 0;
    for (int i = 0; i < (1 << 24); ++i)
      dp[i] = false;
    solve(circle, 0);
    printf("%d\n", ans);
  }
  return 0;
}
