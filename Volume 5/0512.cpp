#include <iostream>
#include <string>
using namespace std;

const string ALPHA = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main()
{
  string s;
  while (cin >> s) {
    for (int i = 0; i < s.size(); ++i)
      s[i] = ALPHA[(s[i]-'A'-3+26)%26];
    cout << s << endl;
  }
  return 0;
}
