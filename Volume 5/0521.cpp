#include <iostream>
using namespace std;

const int c[] = {500, 100, 50, 10, 5, 1};

int main()
{
  int n;
  while (cin >> n) {
    if (n == 0)
      break;

    n = 1000 - n;
    int ans = 0;
    for (int i = 0; i < 6; ++i) {
      ans += n / c[i];
      n %= c[i];
    }

    cout << ans << endl;
  }
  return 0;
}
