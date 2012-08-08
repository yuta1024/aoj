#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
  int X, Y;
  while (cin >> X >> Y) {
    if ((X|Y) == 0)
      break;

    int cnt = 0;
    if (X < Y)
      swap(X, Y);

    do {
      X = X % Y;
      swap(X, Y);
      ++cnt;
    } while (Y != 0);

    cout << X << " " << cnt << endl;
  }
  return 0;
}
