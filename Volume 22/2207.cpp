#include <cstdio>
#include <map>
#include <string>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef struct
{
  string s, t;
  int c;
} Unit;

int main()
{
  const int INF = 1 << 29;

  int N;
  while (~scanf("%d", &N)) {
    if (N == 0)
      break;

    map<string, int> toIndex;
    vector<Unit> unit(N);
    for (int i = 0; i < N; ++i) {
      string s, t, c;
      cin >> t >> t >> c >> c >> s;
      int cc = atoi(c.substr(c.find_first_of("^")+1).c_str());
      unit[i].s = s;
      unit[i].t = t;
      unit[i].c = cc;
      if (toIndex.find(s) == toIndex.end())
	toIndex[s] = toIndex.size()-1;
      if (toIndex.find(t) == toIndex.end())
	toIndex[t] = toIndex.size()-1;
    }

    vector<vector<int> > cost(toIndex.size(), vector<int>(toIndex.size(), INF));
    for (int i = 0; i < cost.size(); ++i)
      cost[i][i] = 0;

    for (int i = 0; i < N; ++i) {
      int s = toIndex.find(unit[i].s)->second;
      int t = toIndex.find(unit[i].t)->second;
      cost[s][t] = unit[i].c;
      cost[t][s] = -unit[i].c;
    }

    for (unsigned int k = 0; k < cost.size(); ++k) {
      for (unsigned int i = 0; i < cost.size(); ++i) {
	for (unsigned int j = 0; j < cost.size(); ++j)
	  cost[i][j] = min(cost[i][j], cost[i][k]+cost[k][j]);
      }
    }

    bool yes = true;
    for (unsigned int i = 0; i < cost.size() && true; ++i) {
      for (unsigned int j = i+1; j < cost.size() && true; ++j) {
	if (cost[i][j] >= 100000000 || cost[j][i] >= 100000000)
	  continue;
	if (cost[i][j] != -cost[j][i])
	  yes = false;
      }
    }

    if (yes)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
  return 0;
}
