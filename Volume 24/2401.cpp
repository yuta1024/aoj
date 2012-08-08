#include <iostream>
#include <string>
using namespace std;

bool formula(string& s, unsigned int& p)
{
  if (s[p] == 'T') {
    ++p;
    return true;
  } else if (s[p] == 'F') {
    ++p;
    return false;
  } else if (s[p] == '-') {
    ++p;
    return !formula(s, p);
  } else if (s[p] == '(') {
    ++p;
    bool lhs = formula(s, p);
    if (s[p] == '*') {
      ++p;
      bool rhs = formula(s, p);
      ++p;
      return lhs && rhs;
    } else if (s[p] == '+') {
      ++p;
      bool rhs = formula(s, p);
      ++p;
      return lhs || rhs;
    } else {
      p += 2;
      bool rhs = formula(s, p);
      ++p;
      if (lhs && !rhs)
	return false;
      return true;
    }
  }
}

bool equation(string& s, unsigned int& p)
{
  bool lhs = formula(s, p);
  ++p;
  bool rhs = formula(s, p);
  if (lhs == rhs)
    return true;
  return false;
}

int main()
{
  string s;
  while (cin >> s) {
    if (s == "#")
      break;

    bool ans = true;
    for (int S = 0; S < (1 << 11); ++S) {
      string t = s;
      for (unsigned int j = 0; j < t.size(); ++j) {
	if ('a' <= t[j] && t[j] <= 'k') {
	  if (S & (1 << (t[j] - 'a')))
	    t[j] = 'T';
	  else
	    t[j] = 'F';
	}
      }
      
      unsigned int p = 0;
      if (!equation(t, p))
	ans = false;
    }

    if (ans)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
