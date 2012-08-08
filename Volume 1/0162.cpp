#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  const long long int MAX = 1000000LL;
  vector<long long int> hamming;

  long long int num = 1LL;
  for (int i = 0; ; ++i) {
    long long int five = num;
    for (int j = 0; j < i; ++j)
      five *= 5LL;

    if (five > MAX)
      break;

    for (int j = 0; ; ++j) {
      long long int three = five;
      for (int k = 0; k < j; ++k)
	three *= 3LL;

      if (three > MAX)
	break;

      for (int k = 0; ; ++k) {
	long long int two = three;
	for (int l = 0; l < k; ++l)
	  two *= 2;

	if (two > MAX)
	  break;
	hamming.push_back(two);
      }
    }
  }
  sort(hamming.begin(), hamming.end());

  long long int m, n;
  while (cin >> m >> n)
    cout << upper_bound(hamming.begin(), hamming.end(), n)
      - lower_bound(hamming.begin(), hamming.end(), m) << endl;
  return 0;
}
