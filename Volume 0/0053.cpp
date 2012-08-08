#include <cstdio>
#include <vector>
using namespace std;

int main()
{
  const int MAX = 200000;
  bool p[MAX];
  for (int i = 0; i < MAX; ++i)
    p[i] = true;
  p[0] = p[1] = false;

  for (int i = 2; i*i <= MAX; ++i) {
    if (p[i]) {
      for (int j = i+i; j < MAX; j += i)
	p[j] = false;
    }
  }

  vector<int> prime;
  for (int i = 0; i < MAX; ++i) {
    if (p[i])
      prime.push_back(i);
  }

  for (unsigned int i = 1; i < prime.size(); ++i)
    prime[i] += prime[i-1];

  int n;
  while (~scanf("%d", &n)) {
    if (n == 0)
      break;
    printf("%d\n", prime[n-1]);
  }
  return 0;
}
