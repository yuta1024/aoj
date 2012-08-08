#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
  int n;
  bool first = true;
  while (cin >> n) {
    vector<string> ans(8, "");
    for (int keta = 0; keta < 5; ++keta) {
      int d = n % 10;
      
      if (d >= 5) {
	ans[0] = " " + ans[0];
	ans[1] = "*" + ans[1];
      } else {
	ans[0] = "*" + ans[0];
	ans[1] = " " + ans[1];
      }
      ans[2] += "=";

      for (int i = 0; i < 5; ++i) {
	if (i == d%5)
	  ans[i+3] = " " + ans[i+3];
	else
	  ans[i+3] = "*" + ans[i+3];
      }

      n /= 10;
    }
    if (!first)
      cout << endl;
    for (unsigned int i = 0; i < ans.size(); ++i)
      cout << ans[i] << endl;
    first = false;
  }
  return 0;
}
