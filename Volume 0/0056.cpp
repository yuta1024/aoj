#include <cstdio>
#include <vector>
using namespace std;

int main()
{
  const int MAX_P = 50000;
  bool p[MAX_P];
  for (int i = 0; i < MAX_P; ++i)
    p[i] = true;
  p[0] = p[1] = false;

  for (int i = 2; i*i <= MAX_P; ++i) {
    if (p[i]) {
      for (int j = i+i; j < MAX_P; j += i)
	p[j] = false;
    }
  }

  int n;
  while (~scanf("%d", &n)) {
    if (n == 0)
      break;
    
    int ans = 0;
    for (int i = 0; 2*i <= n; ++i) {
      if (p[i] && p[n-i])
	++ans;
    }
    printf("%d\n", ans);
  }
  return 0;
}
