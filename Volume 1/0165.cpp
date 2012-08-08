#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
  const int MAX_PRIME = 1000000+1;

  bool p[MAX_PRIME];
  memset(p, true, sizeof(p));
  p[0] = p[1] = false;
  for (int i = 2; i*i <= MAX_PRIME; ++i) {
    if (p[i]) {
      for (int j = i+i; j < MAX_PRIME; j += i)
	p[j] = false;
    }
  }

  vector<int> prime;
  for (int i = 0; i < MAX_PRIME; ++i) {
    if (p[i])
      prime.push_back(i);
  }

  int n;
  while (cin >> n) {
    if (n == 0)
      break;

    int ans = 0;
    while (n--) {
      int p, m;
      cin >> p >> m;
      int X = upper_bound(prime.begin(), prime.end(), p+m) - lower_bound(prime.begin(), prime.end(), p-m);
      ans += X - 1;
    }

    cout << max(0, ans) << endl;
  }
  return 0;
}
