#include <string>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
  int n;
  while (cin >> n) {
    for (int t = 0; t < n; ++t) {
      string s;
      cin >> s;
      int maxN = atoi(s.c_str()), minN = atoi(s.c_str());
      sort(s.begin(), s.end());
      do {
	int tmp = atoi(s.c_str());
	if (maxN < tmp)
	  maxN = tmp;
	if (minN > tmp)
	  minN = tmp;
      } while (next_permutation(s.begin(), s.end()));
      cout << maxN - minN << endl;
    }
  }
  return 0;
}
