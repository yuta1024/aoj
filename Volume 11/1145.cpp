#include <iostream>
#include <string>
#include <cctype>
using namespace std;

const int MAX_STRING = 1000000+1;

string s;

string p_expr(int &p);

int p_number(int &p)
{
  int res = 0;
  while (isdigit(s[p])) {
    res *= 10;
    res += s[p++] - '0';
  }
  return res;
}

string p_character(int &p)
{
  string res = "";
  while (isalpha(s[p]))
    res += s[p++];
  return res;
}

string p_term(int &p)
{
  if (isalpha(s[p])) {
    return p_character(p);
  } else {
    int num = p_number(p);
    string t = "";
    if (s[p] == '(') {
      ++p;
      t = p_expr(p);
      ++p;
    } else {
      t = p_character(p);
    }
    string res = "";
    for (int i = 0; i < num && res.size() < MAX_STRING; ++i)
      res += t;
    return res;
  }
}

string p_expr(int &p)
{
  string res = p_term(p);
  while (p < s.size() && s[p] != ')')
    res += p_term(p);
  return res;
}

int main()
{
  int i;
  while (cin >> s >> i) {
    if (s == "0" && i == 0)
      break;

    int p = 0;
    string ans = p_expr(p);
    if (i < ans.size())
      cout << ans[i] << endl;
    else
      cout << "0" << endl;
  }
  return 0;
}
