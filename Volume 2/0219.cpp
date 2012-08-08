#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int n;
  while (cin >> n) {
    if (n == 0)
      break;

    vector<int> hyouka(10, 0);
    for (int i = 0; i < n; ++i) {
      int k;
      cin >> k;
      ++hyouka[k];
    }

    for (int i = 0; i < 10; ++i) {
      for (int j = 0; j < hyouka[i]; ++j)
	cout << "*";
      if (hyouka[i] == 0)
	cout << "-";
      cout << endl;
    }

  }
  return 0;
}
