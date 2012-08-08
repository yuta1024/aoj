#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

const double EPS = 1e-10;
double b[] = {0.0625, 0.125, 0.25, 0.5};

int main()
{
  double n;
  while (cin >> n) {
    if (n < 0.0)
      break;

    vector<int> digit;
    int d = static_cast<int>(n);
    int dd = d;
    while (dd > 0) {
      digit.push_back(dd%2);
      dd /= 2;
    }
    while (digit.size() < 8)
      digit.push_back(0);

    if (digit.size() > 8) {
      cout << "NA" << endl;
      continue;
    }
    reverse(digit.begin(), digit.end());

    bool found = false;
    for (int i = 0; i < (1 << 4) && !found; ++i) {
      double r = 0.0;
      for (int j = 0; j < 4; ++j) {
	if (i & (1 << j))
	  r += b[j];
      }

      if (abs(d + r - n) < EPS) {
	for (int j = 0; j < 8; ++j)
	  cout << digit[j];
	cout << ".";
	for (int j = 0; j < 4; ++j) {
	  if (i & (1 << (3-j)))
	    cout << "1";
	  else
	    cout << "0";
	}
	cout << endl;
	found = true;
      }
    }

    if (!found)
      cout << "NA" << endl;
  }
  return 0;
}
