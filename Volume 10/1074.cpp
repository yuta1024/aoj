#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct
{
  string name;
  int point;
} Character;

class LessPoint
{
public:
  bool operator() (const Character& lhs, const Character& rhs) const
  {
    if (lhs.point == rhs.point)
      return lhs.name < rhs.name;
    return lhs.point < rhs.point;
  }
};

int main()
{
  int n;
  while (cin >> n) {
    if (n == 0)
      break;

    vector<Character> ans(n);
    vector<vector<int> > freq(n, vector<int>(31, 0));
    for (int i = 0; i < n; ++i) {
      int m;
      cin >> ans[i].name >> m;
      ans[i].point = 0;
      for (int j = 0; j < m; ++j) {
	int d;
	cin >> d;
	freq[i][d] = 1;
      }
    }

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < 31; ++j) {
	if (!freq[i][j])
	  continue;
	int tmp = n;
	for (int k = 0; k < n; ++k) {
	  if (i == k)
	    continue;
	  if (freq[k][j])
	    --tmp;
	}
	ans[i].point += tmp;
      }
    }
    sort(ans.begin(), ans.end(), LessPoint());
    cout << ans[0].point << " " << ans[0].name << endl;
  }
  return 0;
}
