#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>
using namespace std;

void escape(string& s)
{
  if (s.find_first_of("\n") != string::npos)
    s.erase(s.end()-1);
  if (s.find_first_of("\r") != string::npos)
    s.erase(s.end()-1);
}

int main()
{
  string s, t;
  getline(cin, t);

  int T = atoi(t.c_str());
  for (int dataset = 0; dataset < T; ++dataset) {
    getline(cin, s);
    escape(s);
    getline(cin, t);

    int M = atoi(t.c_str()), cur = 0;
    for (int i = 0; i < M; ++i) {
      getline(cin, t);
      escape(t);

      if (t == "forward char") {
	if (cur < s.size())
	  ++cur;
      } else if (t == "forward word") {
	while (cur < s.size() && s[cur] == ' ')
	  ++cur;
	while (cur < s.size() && s[cur] != ' ') {
	  ++cur;
	}
      } else if (t == "backward char") {
	if (cur > 0)
	  --cur;
      } else if (t == "backward word") {
	if (cur != 0) {
	  while (cur > 0 && s[cur-1] == ' ')
	    --cur;
	  while (cur > 0 && s[cur-1] != ' ')
	    --cur;
	}
      } else if (t == "delete char") {
	if (cur < s.size())
	  s.erase(cur, 1);
      } else if (t == "delete word") {
	if (cur < s.size()) {
	  int end = cur;
	  while (end < s.size() && s[end] == ' ')
	    ++end;
	  if (end < s.size()) {
	    while (end < s.size() && s[end] != ' ')
	      ++end;
	    s.erase(cur, end-cur);
	  }
	}
      } else {
	string ins = t.substr(t.find_first_of("\"")+1);
	ins.erase(ins.end()-1);
	s.insert(cur, ins);
	cur += ins.size();
      }
    }
    for (unsigned int i = 0; i <= s.size(); ++i) {
      if (i == cur)
	cout << "^";
      if (i < s.size())
	cout << s[i];
    }
    cout << endl;
  }
  return 0;
}
