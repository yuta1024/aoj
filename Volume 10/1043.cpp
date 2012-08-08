#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct
{
  int I, U, A, P;
} Team;

class solve
{
public:
  bool operator()(const Team& lhs, const Team& rhs)
  {
    if (lhs.A == rhs.A) {
      if (lhs.P == rhs.P)
	return lhs.I < rhs.I;
      return lhs.P < rhs.P;
    }
    return lhs.A > rhs.A;
  }
};

int main()
{
  int n;
  while (cin >> n) {
    if (n == 0)
      break;

    vector<Team> team(n);
    for (int i = 0; i < n; ++i)
      cin >> team[i].I >> team[i].U >> team[i].A >> team[i].P;
    sort(team.begin(), team.end(), solve());

    int advance = 0;
    vector<int> univ(1000, 0);
    for (int i = 0; i < n; ++i) {
      if (advance < 10) {
	if (univ[team[i].U-1] < 3) {
	  cout << team[i].I << endl;
	  ++univ[team[i].U-1];
	  ++advance;
	}
      } else if (advance < 20) {
	if (univ[team[i].U-1] < 2) {
	  cout << team[i].I << endl;
	  ++univ[team[i].U-1];
	  ++advance;
	}
      } else if (advance < 26) {
	if (univ[team[i].U-1] < 1) {
	  cout << team[i].I << endl;
	  ++univ[team[i].U-1];
	  ++advance;
	}
      }
    }

  }
  return 0;
}
