#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
  long long int z;
  while (cin >> z) {
    if (z == 0LL)
      break;

    long long int x3y3 = 0LL;
    for (long long int x = 1LL; x*x*x <= z*z*z; ++x) {
      for (long long int y = 1LL; x*x*x+y*y*y <= z*z*z; ++y)
	x3y3 = max(x3y3, x*x*x+y*y*y);
    }

    cout << z*z*z - x3y3 << endl;
  }
  return 0;
}
