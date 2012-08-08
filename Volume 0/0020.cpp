#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;

int main()
{
  string s;
  while (getline(cin, s)) {
    for (unsigned int i = 0; i < s.size(); ++i)
      s[i] = toupper(s[i]);
    cout << s << endl;
  }
  return 0;
}
