#include <iostream>
#include <vector>
using namespace std;

int main()
{
  for ( ; ; ) {
    int a, b;
    vector<int> g(101, 0);
    while (cin >> a >> b) {
      if ((a|b) == 0)
	break;
      ++g[a];
      ++g[b];
    }
    
    if (cin.eof())
      break;

    bool valid = true;
    for (int i = 3; i < g.size(); ++i) {
      if (g[i] & 1)
	valid = false;
    }
    
    if ((g[1] & 1) && (g[2] & 1) && valid)
      cout << "OK" << endl;
    else
      cout << "NG" << endl;
  }
  return 0;
}
