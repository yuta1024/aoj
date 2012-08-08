#include <iostream>
#include <vector>
using namespace std;

int main()
{
  vector<int> t(5);
  while (cin >> t[0] >> t[1] >> t[2] >> t[3] >> t[4]) {
    if (t[0] == 0)
      break;

    for (int i = 0; i < 5; ++i) {
      int w = 0, l = 0;
      for (int j = 0; j < 5; ++j) {
	if (i == j || t[i] == t[j])
	  continue;
	if (t[i] == 1) {
	  if (t[j] == 2)
	    ++w;
	  else
	    ++l;
	} else if (t[i] == 2) {
	  if (t[j] == 1)
	    ++l;
	  else
	    ++w;
	} else {
	  if (t[j] == 1)
	    ++w;
	  else
	    ++l;
	}
      }
      if (w > 0 && l == 0)
	cout << "1" << endl;
      else if (w == 0 && l > 0)
	cout << "2" << endl;
      else
	cout << "3" << endl;
    }
  }
  return 0;
}
