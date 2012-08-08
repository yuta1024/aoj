#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;

int main()
{
  long long int ans = 0;
  string s;
  while (cin >> s) {
    long long int tmp = 0;
    bool digit = false;
    for (unsigned int i = 0; i < s.size(); ++i) {
      if (isdigit(s[i])) {
	digit = true;
	tmp *= 10;
	tmp += (s[i] - '0');
      } else {
	if (digit) {
	  ans += tmp;
	  digit = false;
	  tmp = 0;
	}
      }
    }
    if (digit)
      ans += tmp;
  }
  cout << ans << endl;
  return 0;
}
