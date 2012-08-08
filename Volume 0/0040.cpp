#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;

int gcd(int a, int b)
{
  if (b == 0)
    return a;
  return gcd(b, a%b);
}

string solve(string cipher)
{
  for ( ; ; ) {
    for (int a = 1; ; ++a) {
      if (gcd(a, 26) != 1)
	continue;
      bool decrypt = false;
      for (int b = 0; b < 26; ++b) {
	string plain = cipher;
	for (unsigned int i = 0; i < plain.size(); ++i) {
	  if (isalpha(plain[i]))
	    plain[i] = ('a' + ((a * (plain[i]-'a') + b) % 26));
	}
	if (plain.find("that") != string::npos || plain.find("this") != string::npos)
	  return plain;
      }
    }
  }
}

int main()
{
  int n;
  cin >> n;
  string cipher;
  getline(cin, cipher);
  for (int i = 0; i < n; ++i) {
    getline(cin, cipher);
    if (cipher.find_first_of("\n") != string::npos)
      cipher.erase(cipher.end()-1);
    if (cipher.find_first_of("\r") != string::npos)
      cipher.erase(cipher.end()-1);
    cout << solve(cipher) << endl;
  }
  return 0;
}
