#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  int i;
  while (cin >> i) {
    if (i == 0)
      break;

    vector<int> a(i);
    for (int j = 0; j < i; ++j)
      cin >> a[j];

    int num = 32, cnt = 0;
    while (num != 0) {
      num = num - (num-1)%5;
      cout << num << endl;

      num = num - min(num, a[cnt++%i]);
      cout << num << endl;
    }
  }
  return 0;
}
