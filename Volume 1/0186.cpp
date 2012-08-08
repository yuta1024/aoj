#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
  long long int q1, b, c1, c2, q2;
  while (cin >> q1 >> b >> c1 >> c2 >> q2) {
    if (q1 == 0)
      break;

    long long int aizu = min(b/c1, q2);
    b -= aizu * c1;
    long long int chicken = b / c2;
    b -= chicken * c2;

    if (aizu+chicken < q1 && c1 > c2) {
      while (aizu > 0 && aizu+chicken < q1) {
	--aizu;
	b += c1;
	long long int new_chicken = b / c2;
	b -= new_chicken * c2;
	chicken += new_chicken;
      }
    }

    if (aizu <= 0LL || aizu+chicken < q1)
      cout << "NA" << endl;
    else
      cout << aizu << " " << chicken << endl;
  }
  return 0;
}
