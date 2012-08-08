#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int getMax(int k, const vector<int>& c)
{
  int ret = 0;
  for (int i = 0; i <= (int)c.size()-k; ++i) {
    int p = 1;
    for (int j = 0; j < k; ++j)
      p *= c[i+j];
    ret = max(ret, p);
  }
  return ret;
}

int main()
{
  int n, k;
  while (cin >> n >> k) {
    if ((n|k) == 0)
      break;

    vector<int> c(n);
    for (int i = 0; i < n; ++i)
      cin >> c[i];

    int t = getMax(k, c), s = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = i+1; j < n; ++j) {
	swap(c[i], c[j]);
	s = max(s, getMax(k, c));
	swap(c[j], c[i]);
      }
    }

    if (t > s)
      cout << "NO GAME" << endl;
    else
      cout << s - t << endl;
  }
  return 0;
}
