#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct
{
  string name;
  int point, index;
} Team;

class GreaterPoint
{
public:
  bool operator() (const Team& lhs, const Team& rhs)
  {
    if (lhs.point == rhs.point)
      return lhs.index < rhs.index;
    return lhs.point > rhs.point;
  }
};

int main()
{
  int n;
  bool first = true;
  while (cin >> n) {
    if (n == 0)
      break;

    if (!first)
      cout << endl;

    vector<Team> team(n);
    for (int i = 0; i < n; ++i) {
      int win, draw;
      cin >> team[i].name >> win >> draw >> draw;
      team[i].point = win*3+draw;
      team[i].index = i;
    }

    sort(team.begin(), team.end(), GreaterPoint());
    for (int i = 0; i < n; ++i)
      cout << team[i].name << "," << team[i].point << endl;
    first = false;
  }
  return 0;
}
