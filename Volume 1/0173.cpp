#include <iostream>
#include <string>
using namespace std;

int main()
{
  int a, p;
  string c;
  while (cin >> c >> a >> p)
    cout << c << " " << a+p << " " << a*200 + p*300 << endl;
  return 0;
}
