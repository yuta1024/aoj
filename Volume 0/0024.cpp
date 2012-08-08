#include <iostream>
using namespace std;

int main()
{
  double v;
  while (cin >> v) {
    double t = v / 9.8;
    double y = 4.9 * t * t;

    int ans = 1;
    while (5*ans-5 < y)
      ++ans;

    cout << ans << endl;
  }
  return 0;
}
