#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  int p, q;
  while (cin >> p >> q) {
    int loop = -1;
    vector<int> rem;
    rem.push_back(p%q);
    while (p != 0) {
      p *= 10;
      int tmp = p / q;
      p %= q;
      cout << tmp;
      if (find(rem.begin(), rem.end(), p) != rem.end()) {
	loop = find(rem.begin(), rem.end(), p) - rem.begin();
	break;
      }
      rem.push_back(p);
    }
    cout << endl;

    if (loop != -1) {
      for (int i = 0; i < loop; ++i)
	cout << " ";
      for (int i = loop; i < rem.size(); ++i)
	cout << "^";
      cout << endl;
    }
  }
  return 0;
}
