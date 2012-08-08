#include <iostream>
#include <string>
using namespace std;

int main()
{
  string r, a;
  while (cin >> r >> a) {
    if (r == "0" && a == "0")
      break;

    int hit = 0;
    for (int i = 0; i < 4; ++i) {
      if (r[i] == a[i])
	++hit;
    }

    int blow = 0;
    for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 4; ++j) {
	if (i == j)
	  continue;
	if (r[i] == a[j])
	  ++blow;
      }
    }

    cout << hit << " " << blow << endl;
  }
  return 0;
}
