#include <iostream>
using namespace std;

int main()
{
  int L;
  while (cin >> L) {
    if (L == 0)
      break;

    int money = 0, ans = -1;
    for (int i = 0; i < 12; ++i) {
      int M, N;
      cin >> M >> N;
      money += M - N;
      if (money >= L && ans == -1)
	ans = i+1;
    }

    if (ans == -1)
      cout << "NA" << endl;
    else
      cout << ans << endl;
  }
  return 0;
}
