#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main()
{
  int n;
  while (cin >> n) {
    if (n == 0)
      break;

    vector<pair<int, int> > pa(n);
    for (int i = 0; i < n; ++i) {
      int p, d1, d2;
      cin >> p >> d1 >> d2;
      pa[i].first = d1 + d2;
      pa[i].second = p;
    }
    sort(pa.begin(), pa.end(), greater<pair<int, int> >());
    cout << pa[0].second << " " << pa[0].first << endl;
  }
  return 0;
}
