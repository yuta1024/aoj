#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Harvest
{
public:
  string L;
  int P, A, B, C, D, E, F, S, M;
  double eff;
};

class GreaterEff
{
public:
  bool operator() (const Harvest& lhs, const Harvest& rhs)
  {
    if (lhs.eff == rhs.eff)
      return lhs.L < rhs.L;
    return lhs.eff > rhs.eff;
  }
};

int main()
{
  int N;
  while (cin >> N) {
    if (N == 0)
      break;

    vector<Harvest> h(N);
    for (int i = 0; i < N; ++i) {
      cin >> h[i].L >> h[i].P >> h[i].A >> h[i].B >> h[i].C 
	  >> h[i].D >> h[i].E >> h[i].F >> h[i].S >> h[i].M;
    }

    for (int i = 0; i < N; ++i) {
      int p = h[i].F * h[i].S * h[i].M - h[i].P;
      int t = h[i].A + h[i].B + h[i].C + h[i].M * (h[i].D + h[i].E);
      h[i].eff = p / static_cast<double>(t);
    }

    sort(h.begin(), h.end(), GreaterEff());
    for (int i = 0; i < N; ++i)
      cout << h[i].L << endl;
    cout << "#" << endl;
  }
  return 0;
}
