#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
  string line;
  while (getline(cin, line)) {
    if (line.find_first_of("\n") != string::npos)
      line.erase(line.end()-1);
    if (line.find_first_of("\r") != string::npos)
      line.erase(line.end()-1);

    if (line == ".")
      break;

    bool yes = true;
    stack<char> stk;
    for (unsigned int i = 0; i < line.size() && yes; ++i) {
      if (line[i] == '(') {
	stk.push('(');
      } else if (line[i] == ')') {
	if (stk.empty() || stk.top() != '(')
	  yes = false;
	else
	  stk.pop();
      } else if (line[i] == '[') {
	stk.push('[');
      } else if (line[i] == ']') {
	if (stk.empty() || stk.top() != '[')
	  yes = false;
	else
	  stk.pop();
      }
    }

    if (yes && stk.empty())
      cout << "yes" << endl;
    else
      cout << "no" << endl;
  }
  return 0;
}
