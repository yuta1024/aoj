#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int n;
  while (cin >> n) {
    if (n == 0)
      break;

    vector<int> cnt(7, 0);
    while (n--) {
      int age;
      cin >> age;

      if (age >= 60)
	++cnt[6];
      else
	++cnt[age/10];
    }

    for (int i = 0; i < 7; ++i)
      cout << cnt[i] << endl;
  }
  return 0;
}
