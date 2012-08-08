#include <iostream>
#include <vector>
using namespace std;

int main()
{
  const int busstop[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 5, 4, 3, 2, 1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  const int bussize = sizeof(busstop) / sizeof(int);

  int n;
  while (cin >> n) {
    while (n--) {
      int a, b;
      cin >> a >> b;

      int s = 0;
      for (; s < bussize; ++s) {
	if (busstop[s] == a)
	  break;
      }

      vector<int> ans;
      for (int i = s; i < bussize; ++i) {
	ans.push_back(busstop[i]);
	if (busstop[i] == b)
	  break;
      }

      if (1 <= a && a <= 5 && b < a) {
	vector<int> rev;
	for (int i = s; i >= 0; --i) {
	rev.push_back(busstop[i]);
	if (busstop[i] == b)
	  break;
	}
	if (rev.size() < ans.size())
	  ans = rev;
      }

      for (int i = 0; i < ans.size()-1; ++i)
	cout << ans[i] << " ";
      cout << ans.back() << endl;
    }
  }
  return 0;
}
