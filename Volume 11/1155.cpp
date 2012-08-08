#include <iostream>
#include <string>
using namespace std;

int formula(const string& s, int& p)
{
  if (s[p] == '(') {
    ++p;
    int lhs = formula(s, p);
    char op = s[p++];
    int rhs = formula(s, p);
    ++p;
    if (op == '*') {
      if (lhs == 0 || rhs == 0)
	return 0;
      else if (lhs == 2 && rhs == 2)
	return 2;
      else
	return 1;
    } else {
      if (lhs == 2 || rhs == 2)
	return 2;
      else if (lhs == 0 && rhs == 0)
	return 0;
      else
	return 1;
    }
  } else if (s[p] == '-') {
    ++p;
    return 2 - formula(s, p);
  } else {
    return s[p++] - '0';
  }
}

int main()
{
  string s;
  while (cin >> s) {
    if (s == ".")
      break;

    int ans = 0;
    for (int P = 0; P <= 2; ++P) {
      string exp1 = s;
      while (exp1.find_first_of("P") != string::npos)
	exp1[exp1.find_first_of("P")] = ('0' + P);
      for (int Q = 0; Q <= 2; ++Q) {
	string exp2 = exp1;
	while (exp2.find_first_of("Q") != string::npos)
	  exp2[exp2.find_first_of("Q")] = ('0' + Q);
	for (int R = 0; R <= 2; ++R) {
	  string exp3 = exp2;
	  while (exp3.find_first_of("R") != string::npos)
	    exp3[exp3.find_first_of("R")] = ('0' + R);
	  int p = 0;
	  if (formula(exp3, p) == 2)
	    ++ans;
	}
      }
    }
    cout << ans << endl;
  }
  return 0;
}
