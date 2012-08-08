#include <iostream>
#include <string>
using namespace std;

const string table[] = {"0", "1abcde", "2fghij", "3klmno", "4pqrst", "5uvwxy", "6z.?! "};

int main()
{
  string s;
  while (cin >> s) {
    bool valid = true;
    if (s.size() & 1)
      valid = false;

    string ans = "";
    for (unsigned int i = 0; i < s.size() && valid; i += 2) {
      int row = s[i] - '0', col = s[i+1] - '0';
      if (0 < row && row <= 6 && 0 < col && col <= 5)
	ans += table[row][col];
      else
	valid = false;
    }

    if (valid)
      cout << ans << endl;
    else
      cout << "NA" << endl;
  }
  return 0;
}
