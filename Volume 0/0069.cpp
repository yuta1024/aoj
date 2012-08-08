#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
  int n;
  while (cin >> n) {
    if (n == 0)
      break;

    int m, p, d;
    cin >> m >> p >> d;
    vector<string> draw(d);
    for (int i = 0; i < d; ++i)
      cin >> draw[i];

    int pos = m;
    for (int i = 0; i < d; ++i) {
      if (pos-2 >= 0 && draw[i][pos-2] == '1')
	--pos;
      else if (pos-1 < n-1 && draw[i][pos-1] == '1')
	++pos;
    }

    if (pos == p) {
      cout << "0" << endl;
      continue;
    }

    bool reach = false;
    for (int i = 0; i < d && !reach; ++i) {
      for (int j = 0; j < n-1 && !reach; ++j) {
	if (draw[i][j] != '0')
	  continue;

	if ((j-1 < 0 || draw[i][j-1] == '0') &&
	    (j+1 >= n-1 || draw[i][j+1] == '0')) {
	  draw[i][j] = '1';

	  pos = m;
	  for (int k = 0; k < d; ++k) {
	    if (pos-2 >= 0 && draw[k][pos-2] == '1')
	      --pos;
	    else if (pos-1 < n-1 && draw[k][pos-1] == '1')
	      ++pos;
	  }
	  
	  if (pos == p) {
	    cout << i+1 << " " << j+1 << endl;
	    reach = true;
	  }
	  draw[i][j] = '0';
	}
      }
    }

    if (!reach)
      cout << "1" << endl;
  }
  return 0;
}
