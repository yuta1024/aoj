#include <iostream>
using namespace std;

int main()
{
  int h1, m1, s1, h2, m2, s2;
  for (int i = 0; i < 3; ++i) {
    cin >> h1 >> m1 >> s1 >> h2 >> m2 >> s2;
    int sec = (h2 - h1)*3600 + (m2 - m1)*60 + (s2 - s1);
    cout << sec/3600 << " " << (sec%3600)/ 60 << " " << sec%60 << endl;
  }
  return 0;
}
