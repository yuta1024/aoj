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

typedef struct
{
  string name;
  int weekday, start;
  bool used;
} PROGRAM;

class LessStart
{
public:
  bool operator() (const PROGRAM& lhs, const PROGRAM& rhs)
  {
    if (lhs.weekday == rhs.weekday) {
      return lhs.start < rhs.start;
    }
    return lhs.weekday < rhs.weekday;
  }
};

int main()
{
  int N;
  while (cin >> N) {
    if (N == 0)
      break;

    vector<PROGRAM> p(N);
    for (int i = 0; i < N; ++i) {
      cin >> p[i].name >> p[i].weekday >> p[i].start;
      p[i].start = (p[i].start/100*60) + p[i].start % 100;
      p[i].used = false;
    }

    static bool sc[8][2400];
    for (int i = 0; i < 8; ++i) {
      for (int j = 0; j < 2400; ++j) {
	sc[i][j] = false;
      }
    }
    
    int P, ans = 0;
    bool dup = false;
    cin >> P;
    for (int i = 0; i < P; ++i) {
      string f;
      cin >> f;
      for (unsigned int j = 0; j < p.size(); ++j) {
	if (f == p[j].name) {
	  for (int s = p[j].start; s < 30+p[j].start; ++s) {
	    int wd = p[j].weekday + (s/1440);
	    if (sc[wd][s%1440]) {
	      dup = true;
	      break;
	    }
	    sc[wd][s%1440] = true;
	  }
	  ++ans;
	  p[j].used = true;
	  break;
	}
      }
    }
    
    if (dup) {
      cout << "-1" << endl;
      continue;
    }

    sort(p.begin(), p.end(), LessStart());
    for (unsigned int i = 0; i < p.size(); ++i) {
      if (!p[i].used) {
	int cnt = 0;
	for (int s = p[i].start; s < 30+p[i].start; ++s) {
	  int wd = p[i].weekday + (s/1440);
	  if (sc[wd][s%1440])
	    ++cnt;
	}

	if (cnt == 0) {
	  for (int s = p[i].start; s < 30+p[i].start; ++s) {
	    int wd = p[i].weekday + (s/1440);
	    sc[wd][s%1440] = true;
	  }
	  ++ans;
	}
      }
    }

    cout << ans << endl;
  }

  return 0;
}
