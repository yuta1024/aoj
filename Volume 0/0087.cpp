#include <string>
#include <iostream>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <sstream>
using namespace std;

int main()
{
  string exp;
  while (getline(cin, exp)) {
    string s;
    stack<double> stk;
    istringstream iss(exp);
    while (iss >> s) {
      if (s == "+" || s == "-" || s == "*" || s == "/") {
	double d2 = stk.top();
	stk.pop();
	double d1 = stk.top();
	stk.pop();
	if (s == "+")
	  stk.push(d1+d2);
	else if (s == "-")
	  stk.push(d1-d2);
	else if (s == "*")
	  stk.push(d1*d2);
	else if (s == "/")
	  stk.push(d1/d2);
      } else {
	stk.push(atof(s.c_str()));
      }
    }
    printf("%.6f\n", stk.top());
  }
  return 0;
}
