#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main()
{
  int n, m;
  while (cin >> n >> m) {
    if ((n|m) == 0)
      break;

    vector<int> v(n);
    for (int i = 0; i < n; ++i)
      cin >> v[i];
    while (v.size() % m != 0)
      v.push_back(0);
    sort(v.begin(), v.end(), greater<int>());

    int ans = 0;
    for (unsigned int i = 0; i < v.size(); i += m) {
      for (int j = 0; j < m-1; ++j)
	ans += v[i+j];
    }

    cout << ans << endl;
  }
  return 0;
}
