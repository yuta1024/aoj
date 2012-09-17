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
  int N, K;
  while (cin >> N >> K) {
    vector<int> bunny(N);
    for (int i = 0; i < K; ++i) {
      int m;
      cin >> m;
      for (int j = 0; j < m; ++j) {
        int b;
        cin >> b;
        bunny[b-1] = i;
      }
    }

    int R;
    cin >> R;
    vector<int> ans(N, 0);
    for (int i = 0; i < R; ++i) {
      int p, q;
      cin >> p >> q;
      --p;
      --q;
      if (bunny[p] == bunny[q]) {
        ans[p] = ans[q] = 1;
      }
    }

    cout << count(ans.begin(), ans.end(), 1) << endl;
  }
  return 0;
}
