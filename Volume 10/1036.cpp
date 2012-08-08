#include <iostream>
#include <string>
using namespace std;

int main()
{
  string red, green, down, ans;
  while (cin >> red) {
    if (red == "-")
      break;
    cin >> green >> down;
    ans = "";

    bool left = true;
    unsigned int rr = 0, gg = 0, dd = 0;

    while (rr < red.size() || gg < green.size() || dd < down.size()) {
      if (left) {
	if (green[gg] == down[dd]) {
	  ++gg;
	  ++dd;
	  left = false;
	} else {
	  ans += green[gg];
	  ++gg;
	}
      } else {
	if (red[rr] == down[dd]) {
	  ++rr;
	  ++dd;
	} else {
	  ans += red[rr];
	  ++rr;
	  left = true;
	}
      }
    }
    cout << ans << endl;
  }
  return 0;
}
