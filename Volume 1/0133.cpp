#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
  vector<string> pattern(8), ans(8);
  for (int i = 0; i < 8; ++i) {
    cin >> pattern[i];
    ans[i] = pattern[i];
  }

  for (int r = 90; r <= 270; r += 90) {
    for (int i = 0; i < 8; ++i) {
      for (int j = 0; j < 8; ++j) 
	ans[j][7-i] = pattern[i][j];
    }

    cout << r << endl;
    for (int i = 0; i < 8; ++i)
      cout << ans[i] << endl;
    pattern = ans;
  }

  return 0;
}
