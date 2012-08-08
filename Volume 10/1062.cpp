#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstdio>
#include <numeric>
#include <bitset>
#include <stack>
using namespace std;

int main()
{
  string name[] = {"lunch", "dinner", "midnight"};

  int n;
  while (cin >> n) {
    if (n == 0)
      break;

    vector<pair<int, int> > ans(3, pair<int, int>(0, 0));
    for (int i = 0; i < n; ++i) {
      int h, m, M;
      scanf("%d:%d %d", &h, &m, &M);
      
      int min_s = h*60 + m;
      int min_t = h*60 + m;
      if (m > M)
	min_t += (60+M-m);
      else
	min_t += (M-m);
      
      if (11*60 <= min_s && min_s < 15*60) {
	if (min_t - min_s <= 8) {
	  ++ans[0].first;
	  ++ans[0].second;
	} else {
	  ++ans[0].second;
	}
      }
      
      if (18*60 <= min_s && min_s < 21*60) {
	if (min_t - min_s <= 8) {
	  ++ans[1].first;
	  ++ans[1].second;
	} else {
	  ++ans[1].second;
	}
      }
      
      if (0 <= min_s && min_s < 2*60 || 21*60 <= min_s && min_s <= 24*60) {
	if (min_t - min_s <= 8) {
	  ++ans[2].first;
	  ++ans[2].second;
	} else {
	  ++ans[2].second;
	}
      }      
    }

    for (unsigned int i = 0; i < ans.size(); ++i) {
      cout << name[i] << " ";
      if (ans[i].second == 0) {
	cout << "no guest" << endl;
      } else {
	cout << ans[i].first*100/ans[i].second << endl;
      }
    }
  }

  return 0;
}
