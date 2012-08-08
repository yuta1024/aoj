#include <iostream>
using namespace std;

int main()
{
  int n;
  while (cin >> n) {
    if (n == 0)
      break;

    int ans = 0;
    for (; n != 1; ++ans) {
      if (n&1)
	n = n * 3 + 1;
      else
	n /= 2;
    }
    cout << ans << endl;
  }
  return 0;
}
