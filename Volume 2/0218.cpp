#include <iostream>
using namespace std;

int main()
{
  int n;
  while (cin >> n) {
    if (n == 0)
      break;

    while (n--) {
      int pm, pe, pj;
      cin >> pm >> pe >> pj;
      if (pm == 100 || pe == 100 || pj == 100 || pm+pe >= 180 || pm+pe+pj >= 240)
	cout << "A" << endl;
      else if (pm+pe+pj >= 210 || (pm+pe+pj >= 150 && (pm >= 80 || pe >= 80)))
	cout << "B" << endl;
      else
	cout << "C" << endl;
    }
  }
  return 0;
}
