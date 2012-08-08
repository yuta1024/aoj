#include <iostream>
#include <cstring>
#include <vector>
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
  for (int i = MAX_PRIME-1; i >= 0; --i) {
    if (p[i])
      prime.push_back(i);
  }

  int n, x;
  while (cin >> n >> x) {
    if ((n|x) == 0)
      break;

    vector<int> foods(n);
    for (int i = 0; i < n; ++i)
      cin >> foods[i];

    vector<int> dp(x+1, 0);
    dp[0] = 1;
    for (int i = 0; i <= x; ++i) {
      if (!dp[i])
	continue;
      for (int j = 0; j < n; ++j) {
	if (i+foods[j] <= x)
	  dp[i+foods[j]] = 1;
      }
    }

    bool found = false;
    for (unsigned int i = 0; i < prime.size() && !found; ++i) {
      if (prime[i] <= x && dp[prime[i]]) {
	cout << prime[i] << endl;
	found = true;
      }
    }

    if (!found)
      cout << "NA" << endl;
  }
  return 0;
}
