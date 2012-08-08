#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Country
{
public:
  string A;
  int B, C;
  long long int D;
  vector<string> d;
  bool operator < (const Country& c) const
  {
    return this->C > c.C;
  }
};

int solve(int idx, long long int visited, const vector<Country>& c)
{
  if (idx >= (int)c.size())
    return 0;

  int ret = 0;
  if (!((1LL << idx) & visited) && (c[idx].D - ((1LL << (idx+1))-1) <= 0)) {
    ret = solve(idx+1, visited | c[idx].D, c) + c[idx].B;
  } else {
    if (!((1LL << idx) & visited))
      ret = solve(idx+1, visited | c[idx].D, c) + c[idx].B;
    ret = max(ret, solve(idx+1, visited, c));
  }
  return ret;
}

int main()
{
  int N;
  while (cin >> N) {
    if (N == 0)
      break;

    vector<Country> c(N);
    for (int i = 0; i < N; ++i) {
      cin >> c[i].A >> c[i].B >> c[i].C;
      for (int j = 0; j < c[i].C; ++j) {
        string dij;
        cin >> dij;
        c[i].d.push_back(dij);
      }
    }

    sort(c.begin()+1, c.end());
    for (int i = 0; i < N; ++i) {
      c[i].D = 1LL << i;
      for (unsigned int j = 0; j < c[i].d.size(); ++j) {
        for (int k = 0; k < N; ++k) {
          if (c[i].d[j] == c[k].A) {
            c[i].D |= 1LL << k;
            break;
          }
        }
      }
    }

    cout << solve(1, c[0].D, c)+c[0].B << endl;
  }
  return 0;
}
