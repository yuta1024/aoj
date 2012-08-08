#include <iostream>
using namespace std;

const double EPS = 1e-10;

int main()
{
  int C1, C2, C3;
  while (cin >> C1 >> C2 >> C3) {
    int cnt = 0;
    for (int i = 1; i <= 10; ++i) {
      if (i == C1 || i == C2 || i == C3)
	continue;
      if (C1+C2+i <= 20)
	++cnt;
    }

    if (cnt / 7.0 >= 0.5+EPS)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
