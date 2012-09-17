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

int e[12][12][12][12][12][11];

int main()
{
  int N;
  cin >> N;
  vector<string> a(N);
  for (int i = 0; i < N; ++i)
    cin >> a[i];

  memset(e, sizeof(e), 0);
  vector<int> log(5, 0);
  for (int i = 0; i < 1000; ++i) {
    int v = -INF;
    for (int i = 0; i < N; ++i)
      v = max(v, e[log[0]][log[1]][log[2]][log[3]][log[4]][i]);
    vector<int> r;
    for (int i = 0; i < N; ++i) {
      if (e[log[0]][log[1]][log[2]][log[3]][log[4]][i] == v)
        r.push_back(i);
    }

    int hand = r[rand()%r.size()];
    printf("%d\n", hand+1);
    fflush(stdout);

    int opp;
    scanf("%d", &opp);
    --opp;

    for (int i = 0; i < N; ++i) {
      if (a[i][opp] == 'o')
        e[log[0]][log[1]][log[2]][log[3]][log[4]][i] += 3;
      else if (a[i][opp] == '-')
        e[log[0]][log[1]][log[2]][log[3]][log[4]][i] += 1;
    }

    log.push_back(opp+1);
    log.erase(log.begin());
  }

  return 0;
}
