#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

typedef struct
{
  int h, p;
} Rect;

int main()
{
  int m;
  cin >> m;
  while (m--) {
    vector<vector<int> > map(5, vector<int>(6, 0));
    for (int i = 0; i < 5; ++i) {
      for (int j = 0; j < 5; ++j)
	cin >> map[i][j];
    }

    for (int i = 0; i < 5; ++i) {
      for (int j = 1; j < 5; ++j) {
	if (map[j][i] != 0)
	  map[j][i] += map[j-1][i];
      }
    }

    int ans = 0;
    for (int i = 0; i < map.size(); ++i) {
      stack<Rect> stack;
      for (int j = 0; j < map[i].size(); ++j) {
	if (stack.empty()) {
	  stack.push((Rect){map[i][j], j});
	} else if (stack.top().h < map[i][j]) {
	    stack.push((Rect){map[i][j], j});
	} else if (stack.top().h > map[i][j]) {
	  int left = j;
	  while (!stack.empty() && stack.top().h >= map[i][j]) {
	    const Rect rect = stack.top();
	    stack.pop();
	    ans = max(ans, rect.h * (j - rect.p));
	    left = rect.p;
	  }
	  stack.push((Rect){map[i][j], left});
	}
      }
    }

    cout << ans << endl;
  }
  return 0;
}
