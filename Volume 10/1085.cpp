#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  int n, S;
  while (cin >> n >> S) {
    if ((n|S) == 0)
      break;

    vector<int> r(n);
    for (int i = 0; i < n; ++i)
      cin >> r[i];
    sort(r.begin(), r.end());

    int ans = 0;
    for (int i = 0; i < n; ++i)
      ans += r.end() - upper_bound(r.begin()+i+1, r.end(), S-r[i]);

    cout << ans << endl;
  }
  return 0;
}
