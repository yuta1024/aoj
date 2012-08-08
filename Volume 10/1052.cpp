#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct
{
  int v, w;
} Island;

class LessWeight
{
public:
  bool operator() (const Island& lhs, const Island& rhs) const
  {
    if (lhs.w == rhs.w)
      return lhs.v < rhs.v;
    return lhs.w < rhs.w;
  }
};

int main()
{
  int n;
  while (cin >> n) {
    if (n == 0)
      break;

    vector<Island> is(n);
    for (int i = 0; i < n; ++i)
      cin >> is[i].v >> is[i].w;
    sort(is.begin(), is.end(), LessWeight());

    int weight = 0;
    bool yes = true;
    for (int i = 0; i < n && yes; ++i) {
      weight += is[i].v;
      if (weight > is[i].w)
	yes = false;
    }

    if (yes)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
  return 0;
}
