#include <iostream>
using namespace std;

int main()
{
  int r, c;
  while (cin >> r >> c) {
    if (r == 0 && c == 0)
      break;

    if ((r*c)%2 == 0)
      cout << "yes" << endl;
    else
      cout << "no" << endl;
  }

  return 0;
}
