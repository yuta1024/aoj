#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct
{
  int n;
  double t;
} Runner;

class LessTime
{
public:
  bool operator() (const Runner& lhs, const Runner& rhs) const
  {
    return lhs.t < rhs.t;
  }
};

int main()
{
  vector<vector<Runner> > p(3, vector<Runner>(8));
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 8; ++j)
      scanf("%d %lf", &p[i][j].n, &p[i][j].t);
    sort(p[i].begin(), p[i].end(), LessTime());

    for (int j = 0; j < 2; ++j) {
      printf("%d %.2lf\n", p[i][0].n, p[i][0].t);
      p[i].erase(p[i].begin());
    }
  }

  vector<Runner> pp;
  for (int i = 0; i < 3; ++i)
    copy(p[i].begin(), p[i].end(), back_inserter(pp));
  sort(pp.begin(), pp.end(), LessTime());

  for (int i = 0; i < 2; ++i) {
    printf("%d %.2lf\n", pp[0].n, pp[0].t);
    pp.erase(pp.begin());
  }
  return 0;
}
