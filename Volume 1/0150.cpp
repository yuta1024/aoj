#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int main()
{
  const int MAX_PRIME = 10000+1;

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

    for (int i = prime.size()-1; i > 0; --i) {
      if (prime[i]-2 == prime[i-1] && prime[i] <= n) {
	cout << prime[i-1] << " " << prime[i] << endl;
	break;
      }
    }
  }
  return 0;
}
