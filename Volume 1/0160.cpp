#include <iostream>
#include <vector>
using namespace std;

int main()
{
  const long long int price[] = {600LL, 800LL, 1000LL, 1200LL, 1400LL, 1600LL};

  int n;
  while (cin >> n) {
    if (n == 0)
      break;

    vector<long long int> item(6, 0);
    while (n--) {
      int x, y, h, w;
      cin >> x >> y >> h >> w;

      int s = x+y+h;
      if (s <= 60 && w <= 2)
	++item[0];
      else if (s <= 80 && w <= 5)
	++item[1];
      else if (s <= 100 && w <= 10)
	++item[2];
      else if (s <= 120 && w <= 15)
	++item[3];
      else if (s <= 140 && w <= 20)
	++item[4];
      else if (s <= 160 && w <= 25)
	++item[5];
    }

    long long int ans = 0;
    for (unsigned int i = 0; i < item.size(); ++i)
      ans += item[i] * price[i];

    cout << ans << endl;
  }
  return 0;
}
