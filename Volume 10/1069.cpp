#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
  int n;
  while (cin >> n) {
    if (n == 0)
      break;

    vector<long long int> even, odd;
    for (int i = 0; i < n*(n+1)/2; ++i) {
      long long int b;
      cin >> b;
      if (b & 1LL)
	odd.push_back(b);
      else
	even.push_back(b);
    }
    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end());

    long long int a0 = static_cast<long long int>(sqrt(even[0] / __gcd(even[0], odd[0]) * (even[1] / (odd[0] / __gcd(even[0], odd[0])))));


    cout << a0 << endl;
    for (int i = 0; i < (int)even.size()-1; ++i)
      cout << even[i]/a0 << " ";
    cout << even.back()/a0 << endl;
  }
  return 0;
}

