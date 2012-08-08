#include <iostream>
#include <string>
using namespace std;

int main()
{
  int n;
  while (cin >> n) {
    for (int dataset = 0; dataset < n; ++dataset) {
      string s;
      cin >> s;
      
      string ans = "";
      int index = 0;
      for (int i = 0; i < s.size(); i += 3) {
	if (index == (int)ans.size()) {
	  ans += s[i];
	} else if (index < 0) {
	  ans = s[i] + ans;
	  index = 0;
	}
	if (i+2 < s.size() && s[i+1] == '-' && s[i+2] == '>')
	  ++index;
	else if (i+2 < s.size())
	  --index;
      }
      cout << ans << endl;
    }
  }
  return 0;
}
