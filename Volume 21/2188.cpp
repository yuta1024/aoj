#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <cstdlib>
using namespace std;

int main()
{
  map<string, int> unit;
  unit["yotta"] = 24;
  unit["zetta"] = 21;
  unit["exa"] = 18;
  unit["peta"] = 15;
  unit["tera"] = 12;
  unit["giga"] = 9;
  unit["mega"] = 6;
  unit["kilo"] = 3;
  unit["hecto"] = 2;
  unit["deca"] = 1;
  unit["deci"] = -1;
  unit["centi"] = -2;
  unit["milli"] = -3;
  unit["micro"] = -6;
  unit["nano"] = -9;
  unit["pico"] = -12;
  unit["femto"] = -15;
  unit["ato"] = -18;
  unit["zepto"] = -21;
  unit["yocto"] = -24;

  string s;
  getline(cin, s);
  int n = atoi(s.c_str());
  while (n--) {
    getline(cin, s);
    int e = 0;
    string num = s.substr(0, s.find_first_of(" "));
    s = s.substr(s.find_first_of(" ")+1);

    string::size_type dot = num.find_first_of(".");
    if (num[0] == '0') {
      string::size_type nonzero = num.find_first_of("123456789");
      e -= nonzero-dot;
      num = num.substr(nonzero);
    } else {
      if (dot == string::npos) {
	e += num.size()-1;
      } else {
	e += dot-1;
	num.erase(dot, 1);
      }
    }

    if (num.size() >= 2)
      num.insert(1, ".");

    if (s.find_first_of(" ") != string::npos) {
      e += unit[s.substr(0, s.find_first_of(" "))];
      s = s.substr(s.find_first_of(" ")+1);
    }

    cout << num << " * 10^" << e << " " << s << endl;
  }
  return 0;
}
