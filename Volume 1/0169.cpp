#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int main()
{
  string s;
  while (getline(cin, s)) {
    if (s.find_first_of("\n") != string::npos)
      s.erase(s.end()-1);
    if (s.find_first_of("\r") != string::npos)
      s.erase(s.end()-1);

    if (s == "0")
      break;

    istringstream iss(s);
    int one = 0, sum = 0;
    while (!iss.eof()) {
      int num;
      iss >> num;

      if (num == 1)
	++one;
      else if (num >= 10)
	sum += 10;
      else
	sum += num;
    }

    int ans = 0;
    for (int i = 0; i <= one; ++i) {
      int p = i + (one-i)*11 + sum;
      if (p > 21)
	p = 0;
      ans = max(ans, p);
    }

    cout << ans << endl;
  }
  return 0;
}
