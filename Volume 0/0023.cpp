#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  int n;
  while (cin >> n) {
    for (int i = 0; i < n; ++i) {
      double xa, ya, ra, xb, yb, rb;
      cin >> xa >> ya >> ra >> xb >> yb >> rb;
      
      double d = sqrt((xa-xb)*(xa-xb) + (ya-yb)*(ya-yb));
      
      if (d > ra+rb)
	cout << "0" << endl;
      else if (d+ra < rb)
	cout << "-2" << endl;
      else if (d+rb < ra)
	cout << "2" << endl;
      else
	cout << "1" << endl;
    }
  }
  return 0;
}
