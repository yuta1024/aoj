#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

const double EPS = 1e-10;

int main()
{
  int n;
  while (cin >> n) {
    if (n == 0)
      break;

    int bestIndex;
    double bestBMI = 1e10;
    while (n--) {
      int i, h, w;
      cin >> i >> h >> w;
      
      double bmi = w / ((h/100.0)*(h/100.0));
      if (abs(22.0-bestBMI) - abs(22.0-bmi) > EPS) {
	bestBMI = bmi;
	bestIndex = i;
      } else if (abs(22.0-bmi) - abs(22.0-bestBMI) < EPS) {
	bestIndex = min(bestIndex, i);
      }
    }
    cout << bestIndex << endl;
  }
  return 0;
}
