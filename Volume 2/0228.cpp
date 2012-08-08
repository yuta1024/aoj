#include <iostream>
#include <string>
using namespace std;

const string seg[] = {"0111111", "0000110",
		      "1011011", "1001111",
		      "1100110", "1101101",
		      "1111101", "0100111",
		      "1111111", "1101111"};

int main()
{
  int n;
  while (cin >> n) {
    if (n == -1)
      break;

    string s = "0000000";
    while (n--) {
      int d;
      cin >> d;
      for (int i = 0; i < 7; ++i) {
	if (s[i] == seg[d][i])
	  cout << "0";
	else
	  cout << "1";
      }
      cout << endl;
      s = seg[d];
    }
  }
  return 0;
}
