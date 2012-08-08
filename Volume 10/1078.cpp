#include <iostream>
#include <string>
#include <set>
using namespace std;

bool clause(const string& s, int& p)
{
  set<char> v, nv;
  while (s[p] != ')') {
    if (s[p] == '&') {
      ++p;
    }else if (s[p] == '~') {
      ++p;
      nv.insert(s[p++]);
    } else {
      v.insert(s[p++]);
    }
  }

  bool ret = true;
  for (set<char>::iterator it = v.begin(); it != v.end() && ret; ++it) {
    if (nv.find(*it) != nv.end())
      ret = false;
  }
  return ret;
}

bool exp(const string& s, int& p)
{
  bool ret = false;
  while (p < (int)s.size()) {
    if (s[p] == '(') {
      ++p;
      ret |= clause(s, p);
    } else {
      ++p;
    }
  }
  return ret;
}

int main()
{
  string s;
  while (cin >> s) {
    if (s == "#")
      break;

    int p = 0;
    if (exp(s, p))
      cout << "yes" << endl;
    else
      cout << "no" << endl;
  }
  return 0;
}
