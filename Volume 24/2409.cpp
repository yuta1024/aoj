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
#include <cstring>
using namespace std;

const int INF = 1 << 30;
const double EPS = 1e-10;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int main()
{
  int N, M;
  while (cin >> N >> M) {
    vector<pair<int, int> > ab(M);
    for (int i = 0; i < M; ++i)
      cin >> ab[i].first >> ab[i].second;
    
    int ans = 0, prev = 1;
    for (int t = 0; t < M; ++t) {
      int next = -1;
      for (int i = 0; i < M; ++i) {
        if (ab[i].first <= prev)
          next = max(next, ab[i].second);
      }
      ++ans;
      prev = next+1;
      if (prev > N)
        break;
    }

    if (prev > N)
      cout << ans << endl;
    else
      cout << "Impossible" << endl;
  }
  return 0;
}
