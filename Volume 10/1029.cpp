#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  int n, m;
  while (cin >> n >> m) {
    if (n == 0 && m == 0)
      break;

    vector<int> t(n+m);
    for (int i = 0; i < n+m; ++i)
      cin >> t[i];

    t.push_back(0);
    sort(t.begin(), t.end());

    int ans = 0;
    for (unsigned int i = 0; i < t.size()-1; ++i)
      ans = max(ans, t[i+1]-t[i]);

    cout << ans << endl;
  }

  return 0;
}
