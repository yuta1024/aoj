#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
  int w;
  while (cin >> w) {
    if (w == -1)
      break;

    int price = 1150;
    w -= 10;
    if (w > 0) {
     price += 125 *  min(w, 10);
     w -= min(w, 10);
    }

    if (w > 0) {
     price += 140 *  min(w, 10);
     w -= min(w, 10);
    }

    if (w > 0)
      price += 160 * w;

    cout << 4280 - price << endl;
  }
  return 0;
}
