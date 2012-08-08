#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
  int a, b, c, d, e, f;
  while (cin >> a >> b>> c >> d >> e >> f) {
    if ((a|b|c|d|e|f) == 0)
      break;
    int ans = 0;
    for (int i = 0; i < 3; ++i) {
      if (a+d >= i && b+e >= i && c+f >=i)
	ans = max(ans, (a+d-i)/3+(b+e-i)/3+(c+f-i)/3+i);
    }
    cout << ans << endl;
  }
  return 0;
}
