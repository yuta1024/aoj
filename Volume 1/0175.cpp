#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int n;
  while (cin >> n) {
    if (n == -1)
      break;

    if (n == 0) {
      cout << n << endl;
      continue;
    }

    vector<int> ans;
    while (n) {
      ans.push_back(n%4);
      n /= 4;
    }

    for (int i = ans.size()-1; i >= 0; --i)
      cout << ans[i];
    cout << endl;
  }
  return 0;
}
