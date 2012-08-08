#include <iostream>
using namespace std;

int main()
{
  int b, r, g, c, s, t;
  while (cin >> b >> r >> g >> c >> s >> t) {
    if ((b|r|g|c|s|t) == 0)
      break;

    int pay = (t-b*5-r*3-s) * 3 + (b*5+r*3) * 2;
    int get = (b*6+r*4)*15 + g*7 + c*2;

    cout << 100 + get - pay << endl;
  }
  return 0;
}
