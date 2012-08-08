#include <iostream>
using namespace std;

int main()
{
  int n;
  while (cin >> n) {
    if (n == 0)
      break;

    int ans = 0;
    for (int i = 0; i < n/4; ++i) {
      int t;
      cin >> t;
      ans += t;
    }

    cout << ans << endl;
  }
  return 0;
}


