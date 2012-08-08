#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;

map<string, set<string> > memo;

set<string> solve(const pair<string, vector<string> >& base, const vector<pair<string, vector<string> > >& g)
{
  set<string> ans;
  for (int i = 0; i < base.second.size(); ++i) {
    bool found = false;
    for (int j = 0; j < g.size() && !found; ++j) {
      if (base.second[i] == g[j].first) {
	found = true;
	map<string, set<string> >::iterator it = memo.find(base.second[i]);
	if (it != memo.end()) {
	  ans.insert(it->second.begin(), it->second.end());
	} else {
	  set<string> s = solve(g[j], g);
	  memo.insert(pair<string, set<string> >(base.second[i], s));
	  ans.insert(s.begin(), s.end());
	}
      }
    }
    if (!found)
      ans.insert(base.second[i]);
  }
  return ans;
}

pair<string, vector<string> > split(const string str)
{
  int s = 0, t;
  t = str.find_first_of(":", s);
  string key = str.substr(0, t);
  s = t+1;
  
  vector<string> value;
  do {
    t = str.find_first_of(",", s);
	  value.push_back(str.substr(s, t-s));
	  s = t+1;
  } while (t != string::npos);
  
  return pair<string, vector<string> >(key, value);
}

int main()
{
  int n;
  while (cin >> n) {
    if (n == 0)
      break;
    
    memo.clear();
    
    string s;
    cin >> s;
    s.erase(s.end()-1);
    
    pair<string, vector<string> > base = split(s);
    vector<pair<string, vector<string> > > other;
    for (int i = 1; i < n; ++i) {
      cin >> s;
      s.erase(s.end()-1);
      other.push_back(split(s));
    }
    set<string> ans = solve(base, other);
    cout << ans.size() << endl;
  }
  return 0;
}
