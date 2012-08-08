#include <string>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
  string s;
  while (getline(cin, s)) {
    vector<string> ans;

    int b;
    bool cut = false;
    for (unsigned int i = 0; i < s.size(); ++i) {
      if (!cut) {
	if (s[i] != ' ' && s[i] != '.' && s[i] != ',') {
	  b = i;
	  cut = true;
	}
      } else {
	if (s[i] == ' ' || s[i] == '.' || s[i] == ',') {
	  string t = s.substr(b, i-b);
	  if (3 <= t.size() && t.size() <= 6)
	    ans.push_back(t);
	  cut = false;
	}
      }
    }

    if (cut) {
      string t = s.substr(b);
      if (3 <= t.size() && t.size() <= 6)
	ans.push_back(t);
    }

    for (int i = 0; i < static_cast<int>(ans.size())-1; ++i)
      cout << ans[i] << " ";
    if (!ans.empty())
      cout << ans[ans.size()-1] << endl;
    else
      cout << endl;
  }
  return 0;
}
