#include <iostream>
#include <string>
using namespace std;

int main()
{
  string s;
  while (getline(cin, s)) {
    if (s == "END OF INPUT")
      break;
    s += " ";
    
    int cnt = 0;
    bool flag = true;
    for (unsigned int i = 0; i < s.size(); ++i) {
      if (s[i] == ' ') {
	cout << cnt;
	if (flag) {
	  cnt = 0;
	  flag = false;
	}
      } else {
	++cnt;
	flag  = true;
      }
    }
    cout << endl;
  }
  return 0;
}
