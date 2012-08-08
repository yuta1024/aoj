#include <iostream>
#include <vector>
using namespace std;

int main()
{
  vector<int> s(10);
  while (cin >> s[0] >> s[1]) {
    if ((s[0]|s[1]) == 0)
      break;

    for (int i = 2; i < 10; ++i)
      cin >> s[i];

    int minIndex = 0;
    for (int i = 2; i < 10; i += 2) {
      if (s[i]+s[i+1] > s[2*minIndex]+s[2*minIndex+1])
	minIndex = i/2;
    }

    cout << static_cast<char>('A'+minIndex) << " " << s[2*minIndex]+s[2*minIndex+1] << endl;
  }
  return 0;
}
