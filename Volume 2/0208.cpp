#include <iostream>
#include <vector>
using namespace std;

const int d2o[] = {0, 1, 2, 3, 5, 7, 8, 9};

int main()
{
  int n;
  while (cin >> n) {
    if (n == 0)
      break;

    vector<int> ans;
    while (n > 0) {
      ans.push_back(d2o[n%8]);
      n /= 8;
    }

    for (int i = ans.size()-1; i >= 0; --i)
      cout << ans[i];
    cout << endl;
  }
  return 0;
}
