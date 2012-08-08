#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <queue>
using namespace std;

int main()
{
  string s;
  while (cin >> s) {
    if (s == "0")
      break;

    queue<pair<int, string> > que;
    que.push(make_pair(0, s));
    set<string> memo;
    int ans = -1;
    while (!que.empty()) {
      const pair<int, string> p = que.front();
      que.pop();

      if (p.second.find_first_of("rg") == string::npos ||
	  p.second.find_first_of("rb") == string::npos ||
	  p.second.find_first_of("gb") == string::npos) {
	ans = p.first;
	break;
      }

      if (memo.find(p.second) != memo.end())
	continue;
      memo.insert(p.second);

      for (int i = 0; i < p.second.size()-1; ++i) {
	if (p.second[i] != p.second[i+1]) {
	  s = p.second;
	  if (s[i] == 'r' && s[i+1] == 'g' || s[i] == 'g' && s[i+1] == 'r')
	    s[i] = s[i+1] = 'b';
	  else if (s[i] == 'r' && s[i+1] == 'b' || s[i] == 'b' && s[i+1] == 'r')
	    s[i] = s[i+1] = 'g';
	  else if (s[i] == 'g' && s[i+1] == 'b' || s[i] == 'b' && s[i+1] == 'g')
	    s[i] = s[i+1] = 'r';

	  if (memo.find(s) == memo.end())
	    que.push(make_pair(p.first+1, s));
	}
      }

    }

    if (ans == -1)
      cout << "NA" << endl;
    else
      cout << ans << endl;
  }
  return 0;
}
