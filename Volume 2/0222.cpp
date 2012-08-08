#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
  const int MAX_PRIME = 10000000+1;

  static bool p[MAX_PRIME];
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

  vector<int> ans;
  for (unsigned int i = 3; i < prime.size(); ++i) {
    if (prime[i-3]+8 == prime[i] &&
	prime[i-2]+6 == prime[i] &&
	prime[i-1]+2 == prime[i])
      ans.push_back(prime[i]);
  }

  int n;
  while (cin >> n) {
    if (n == 0)
      break;
    cout << *(upper_bound(ans.begin(), ans.end(), n)-1) << endl;
  }
  return 0;
}
