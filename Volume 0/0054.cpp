#include <iostream>
using namespace std;

int main()
{
  int a, b, n;
  while (cin >> a >> b >> n) {
    int ans = 0;
    a *= 10;
    for (int i = 0; i < n; ++i, a *= 10) {
      ans += a / b % 10;
      a %= b;
    }
    cout << ans << endl;
  }
  return 0;
}
