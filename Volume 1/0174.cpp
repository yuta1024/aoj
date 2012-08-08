#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
  vector<string> s(3);
  while (cin >> s[0] >> s[1] >> s[2]) {
    if (s[0] == "0")
      break;
    
    for (int i = 0; i < 3; ++i) {
      int A = 0, B = 0;
      for (unsigned int j = 1; j < s[i].size(); ++j) {
	if (s[i][j] == 'A')
	  ++A;
	else
	  ++B;
      }
      
      if (A+1-B > 2)
	cout << A+1 << " " << B << endl;
      else
	cout << A << " " << B+1 << endl;
    }
  }
  return 0;
}
