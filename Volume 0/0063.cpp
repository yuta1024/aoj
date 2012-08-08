#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
  int cnt = 0;
  string s, t;
  while (cin >> s) {
    t = s;
    reverse(t.begin(), t.end());
    if (s == t)
      ++cnt;
  }
  cout << cnt << endl;
  return 0;
}
