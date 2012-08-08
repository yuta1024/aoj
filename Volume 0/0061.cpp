#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

class Rank
{
public:
  int index, solved, rank;
  Rank(int _index, int _solved, int _rank)
    :index(_index), solved(_solved), rank(_rank) {}
};

class OrderIndex
{
public:
  bool operator() (const Rank& lhs, const Rank& rhs) const
  {
    return lhs.index < rhs.index;
  }
};

class GreaterSolved
{
public:
  bool operator() (const Rank& lhs, const Rank& rhs) const
  {
    return lhs.solved > rhs.solved;
  }
};

int main()
{
  int index, solved;
  vector<Rank> team;
  while (~scanf("%d,%d\n", &index, &solved)) {
    if ((index|solved) == 0)
      break;
    team.push_back(Rank(index, solved, -1));
  }

  sort(team.begin(), team.end(), GreaterSolved());
  index = team[0].rank = 1;
  solved = team[0].solved;
  for (unsigned int i = 1; i < team.size(); ++i) {
    if (team[i].solved < solved) {
      solved = team[i].solved;
      team[i].rank = ++index;
    } else {
      team[i].rank = index;
    }
  }
  sort(team.begin(), team.end(), OrderIndex());

  while (~scanf("%d", &index))
    printf("%d\n", team[index-1].rank);
  return 0;
}
