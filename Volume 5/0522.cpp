#include <iostream>
#include <string>
using namespace std;

int main()
{
  string s;
  while (cin >> s) {
    int joi = 0, ioi = 0;
    for (int i = 2; i < s.size(); ++i) {
      if (s[i-2] == 'J' && s[i-1] == 'O' && s[i] == 'I')
	++joi;
      if (s[i-2] == 'I' && s[i-1] == 'O' && s[i] == 'I')
	++ioi;
    }

    cout << joi << endl << ioi << endl;
  }
  return 0;
}
