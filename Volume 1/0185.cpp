#include <iostream>
#include <algorithm>
#include <cstring>
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

  int n;
  while (cin >> n) {
    if (n == 0)
      break;

    int ans = 0;
    for (int i = 0; i+i <= n; ++i) {
      if (p[i] && p[n-i])
	++ans;
    }
    cout << ans << endl;
  }
  return 0;
}
