#include <iostream>
#include <string>
using namespace std;

const string day[] = {"Wednesday", "Thursday", "Friday", "Saturday", "Sunday", "Monday", "Tuesday"};

int dd[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main()
{
  int m, d;
  while (cin >> m >> d) {
    if (m == 0 && d == 0)
      break;
    for (int i = 1; i < m; ++i)
      d += dd[i-1];
    cout << day[d%7] << endl;
  }
  return 0;
}
