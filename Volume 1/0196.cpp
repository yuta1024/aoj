#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef struct
{
  string t;
  int id, w, l;
} Team;

class Solve
{
public:
  bool operator() (const Team& lhs, const Team& rhs) const
  {
    if (lhs.w == rhs.w) {
      if (lhs.l == rhs.l)
	return lhs.id < rhs.id;
      return lhs.l < rhs.l;
    }
    return lhs.w > rhs.w;
  }
};

int main()
{
  int n;
  while (cin >> n) {
    if (n == 0)
      break;

    vector<Team> team(n);
    for (int i = 0; i < n; ++i) {
      team[i].id = i;
      cin >> team[i].t;
      for (int j = 0; j < n-1; ++j) {
	int r;
	cin >> r;
	if (r == 0)
	  ++team[i].w;
	else if (r == 1)
	  ++team[i].l;
      }
    }
    sort(team.begin(), team.end(), Solve());

    for (int i = 0; i < n; ++i)
      cout << team[i].t << endl;

  }
  return 0;
}
