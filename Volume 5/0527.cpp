#include <cstdio>
#include <vector>
#include <stack>
using namespace std;

const int INF = 1 << 30;

typedef struct
{
  int l, r;
} Range;

int main()
{
  int n;
  while (~scanf("%d", &n)) {
    if (n == 0)
      break;

    vector<vector<Range> > s(2);
    for (int i = 1; i <= n; ++i) {
      int c;
      scanf("%d", &c);
      if (i%2 == 0) {
	if (!s[c].empty() && s[c].back().r+1 == i) {
	  s[c].back().r = i;
	} else {
	  if (s[c].empty())
	    s[c].push_back(s[c^1].back());
	  s[c^1].pop_back();
	  s[c].back().r = i;
	}
      } else {
	if (s[c].empty() || s[c].back().r+1 != i)
	  s[c].push_back((Range){i, i});
	else
	  s[c].back().r = i;
      }
    }

    int ans = 0;
    for (unsigned int i = 0; i < s[0].size(); ++i)
      ans += s[0][i].r - s[0][i].l + 1;
    printf("%d\n", ans);
  }
  return 0;
}
