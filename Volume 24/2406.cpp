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
  int N, T, E;
  while (cin >> N >> T >> E) {
    vector<int> x(N);
    for (int i = 0; i < N; ++i)
      cin >> x[i];

    int ans = -1;
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < 2000; ++j) {
        if (T-E <= x[i]*j && x[i]*j <= T+E)
          ans = i+1;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
