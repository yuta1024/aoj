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

int main()
{
  int Q;
  while (cin >> Q) {
    while (Q--) {
      long long R;
      cin >> R;
      
      int ans = 0;
      set<long long> visited;
      while (R/10 > 0 && visited.find(R) == visited.end()) {
        visited.insert(R);

        long long next = -1;
        for (int i = 10; R/i > 0; i *= 10) {
          long long a = R / i;
          long long b = R % i;
          next = max(next, a*b);
        }
        R = next;
        ++ans;
      }

      if (visited.find(R) != visited.end())
        ans = -1;
      cout << ans << endl;
    }
  }
  return 0;
}
