#include <string>
#include <iostream>
using namespace std;

int main()
{
  int n;
  cin >> n;

  string s;
  int runner = 0, out = 0, score = 0;
  while (cin >> s) {
    if (s == "OUT") {
      ++out;
      if (out >= 3) {
	cout << score << endl;
	runner = out = score = 0;
      }
    } else if (s == "HIT") {
      ++runner;
      if (runner > 3) {
	++score;
	--runner;
      }
    } else {
      score += runner + 1;
      runner = 0;
    }
  }
  return 0;
}
