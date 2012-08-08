#include <iostream>
#include <string>
using namespace std;

const string alpha = "abcdefghijklmnopqrstuvwxyz";

int main()
{
  string s;
  while (getline(cin, s)) {

    for (int i = 0; i < 26; ++i) {
      for (unsigned int j = 0; j < s.size(); ++j) {
	if (isalpha(s[j]))
	  s[j] = alpha[(s[j]-'a'+1)%alpha.size()];
      }
      if (s.find("the", 0) != string::npos ||
	  s.find("this", 0) != string::npos ||
	  s.find("that", 0) != string::npos)
	break;
    }

    cout << s << endl;

  }
  return 0;
}
