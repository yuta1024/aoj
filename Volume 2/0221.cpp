#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;

int main()
{
  int m, n;
  while (cin >> m >> n) {
    if ((m|n) == 0)
      break;

    vector<int> p;
    for (int i = 1; i <= m; ++i)
      p.push_back(i);

    int index = 0, mm = m;
    for (int i = 1; i <= n; ++i) {
      string s;
      cin >> s;

      if (mm == 1)
	continue;

      if (s == "FizzBuzz" && i % 15 == 0 ||
	  s == "Fizz" && i % 3 == 0 ||
	  s == "Buzz" && i % 5 == 0 ||
	  (i % 3 != 0 && i % 5 != 0 && atoi(s.c_str()) == i)) {


      } else {
	if (mm > 0) {
	  p[index] = -1;
	  --mm;
	}
      }

      if (mm > 0) {
	++index;
	if (index >= m)
	  index -= m;
	while (p[index] == -1) {
	  ++index;
	  if (index >= m)
	    index -= m;
	}
      }
    }

    vector<int> ans;
    for (unsigned int i = 0; i < p.size(); ++i) {
      if (p[i] != -1)
	ans.push_back(p[i]);
    }

    if (!ans.empty()) {
      for (int i = 0; i < ans.size()-1; ++i)
	cout << ans[i] << " ";
      cout << ans.back();
    }
    cout << endl;
  }
  return 0;
}
