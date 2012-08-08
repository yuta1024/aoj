#include <cstdio>

int main()
{
  const int MAX_NUM = 123456*2+1;
  bool prime[MAX_NUM];
  for (int i = 0; i < MAX_NUM; ++i)
    prime[i] = true;
  prime[0] = prime[1] = false;

  for (int i = 2; i*i <= MAX_NUM; ++i) {
    if (prime[i]) {
      for (int j = i+i; j < MAX_NUM; j += i)
	prime[j] = false;
    }
  }

  int n;
  while (~scanf("%d", &n)) {
    if (n == 0)
      break;

    int ans = 0;
    for (int i = n+1; i <= 2*n; ++i) {
      if (prime[i])
	++ans;
    }

    printf("%d\n", ans);
  }
  return 0;
}
