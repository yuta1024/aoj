#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int n, m;
  while (cin >> n >> m) {
    vector<int> c(2*n);
    for (int i = 0; i < 2*n; ++i)
      c[i] = i+1;

    for (int i = 0; i < m; ++i) {
      int k;
      cin >> k;

      vector<int> nc(2*n);
      if (k == 0) {
	for (int j = 0; j < n; ++j) {
	  nc[j*2] = c[j];
	  nc[j*2+1] = c[n+j];
	}
      } else {
	for (int j = 0; j < k; ++j)
	  nc[2*n-k+j] = c[j];
	for (int j = 0; j < 2*n-k; ++j)
	  nc[j] = c[k+j];
      }
      c = nc;
    }

    for (int i = 0; i < 2*n; ++i)
      cout << c[i] << endl;
  }
  return 0;
}
