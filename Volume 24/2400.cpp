#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Team
{
public:
  int tID, solved, penalty;
  Team(int _tID, int _solved, int _penalty)
    :tID(_tID), solved(_solved), penalty(_penalty) {}
  bool operator <(const Team& obj) const
  {
    if (this->solved == obj.solved) {
      if (this->penalty == obj.penalty)
	return this->tID < obj.tID;
      return this->penalty < obj.penalty;
    }
    return this->solved > obj.solved;
  }
};

int main()
{
  int T, P, R;
  while (cin >> T >> P >> R) {
    if ((T|P|R) == 0)
      break;

    vector<Team> team;
    for (int i = 0; i < T; ++i)
      team.push_back(Team(i, 0, 0));

    vector<vector<int> > log(T, vector<int>(P, 0));
    for (int i = 0; i < R; ++i) {
      int tID, pID, time;
      string message;
      cin >> tID >> pID >> time >> message;
      --tID;
      --pID;
      if (log[tID][pID] == -1)
	continue;

      if (message == "WRONG") {
	++log[tID][pID];
      } else {
	++team[tID].solved;
	team[tID].penalty += time + log[tID][pID]*1200;
	log[tID][pID] = -1;
      }
    }
    sort(team.begin(), team.end());

    for (int i = 0; i < T; ++i)
      cout << team[i].tID+1 << " " << team[i].solved << " " << team[i].penalty << endl;
  }
  return 0;
}
