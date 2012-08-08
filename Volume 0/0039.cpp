#include <string>
#include <iostream>
using namespace std;

int roman2int(const char c)
{
  if (c == 'I')
    return 1;
  else if (c == 'V')
    return 5;
  else if (c == 'X')
    return 10;
  else if (c == 'L')
    return 50;
  else if (c == 'C')
    return 100;
  else if (c == 'D')
    return 500;
  else
    return 1000;
}

int main()
{
  string s;
  while (cin >> s) {
    int ans = 0;
    for (unsigned int i = 0; i < s.size()-1; ++i) {
      if (roman2int(s[i]) < roman2int(s[i+1]))
	ans -= roman2int(s[i]);
      else
	ans += roman2int(s[i]);
    }
    cout << ans+roman2int(s[s.size()-1]) << endl;
  }
  return 0;
}
