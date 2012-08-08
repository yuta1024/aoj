#include <string>
#include <iostream>
#include <cctype>
using namespace std;

int exp(const string& s, int& p);
int term(const string& s, int& p);
int fact(const string& s, int& p);
int number(const string& s, int& p);

int main()
{
  int n;
  while (cin >> n) {
    for (int i = 0; i < n; ++i) {
      string s;
      cin >> s;
      s.erase(s.end()-1);
      int p = 0;
      cout << exp(s, p) << endl;
    }
  }
  return 0;
}

int exp(const string& s, int& p)
{
  int ret = term(s, p);
  for ( ; ; ) {
    if (s[p] == '+')
      ret += term(s, ++p);
    else if (s[p] == '-')
      ret -= term(s, ++p);
    else
      break;
  }
  return ret;
}

int term(const string& s, int& p)
{
  int ret = fact(s, p);
  for ( ; ; ) {
    if (s[p] == '*')
      ret *= fact(s, ++p);
    else if (s[p] == '/')
      ret /= fact(s, ++p);
    else
      break;
  }
  return ret;
}

int fact(const string& s, int& p)
{
  int ret = 0;
  if (s[p] == '(') {
    ret = exp(s, ++p);
    ++p;
  } else {
    ret = number(s, p);
  }
  return ret;
}

int number(const string&s, int& p)
{
  int ret = 0;
  while (isdigit(s[p])) {
    ret *= 10;
    ret += s[p] - '0';
    ++p;
  }
  return ret;
}
