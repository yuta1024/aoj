#include <iostream>
#include <map>
#include <string>
using namespace std;

const string ButtonTable = "22233344455566677778889999";

string hash(const string& s)
{
  string t = "";
  for (unsigned int i = 0; i < s.size(); ++i)
    t += ButtonTable[s[i] - 'a'];
  return t;
}

void solve(multimap<string, string>& dic, string seq, string ans)
{
  for (unsigned int i = 1; i <= seq.size(); ++i) {
    string h = seq.substr(0, i), rem = seq.substr(i);
    for (multimap<string, string>::iterator it = dic.find(h); it != dic.end() && (*it).first == h; ++it) {
      if (rem.empty()) 
	cout << ans << (*it).second << "." << endl;
      else
	solve(dic, rem, ans + (*it).second + " ");
    }
  }
  return;
}

int main()
{
  int n;
  while (cin >> n) {
    if (n == 0)
      break;

    multimap<string, string> dic;
    for (int i = 0; i < n; ++i) {
      string s;
      cin >> s;
      dic.insert(multimap<string, string>::value_type(hash(s), s));
    }

    string seq;
    cin >> seq;
    solve(dic, seq, "");

    cout << "--" << endl;

  }
  return 0;
}
