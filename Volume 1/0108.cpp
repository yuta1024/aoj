#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
  int n;
  while (~scanf("%d", &n)) {
    if (n == 0)
      break;

    vector<int> S(n);
    for (int i = 0; i < n; ++i)
      scanf("%d", &S[i]);

    int cnt = 0;
    for ( ; ; ) {
      vector<int> C(n);
      map<int, int> freq;

      for (int i = 0; i < n; ++i)
	++freq[S[i]];
      for (int i = 0; i < n; ++i)
	C[i] = freq.find(S[i])->second;

      bool same = true;
      for (int i = 0; i < n; ++i) {
	if (S[i] != C[i])
	  same = false;
      }
      
      if (same)
	break;
      ++cnt;
      swap(C, S);
    }
    printf("%d\n", cnt);
    for (int i = 0; i < n-1; ++i)
      printf("%d ", S[i]);
    printf("%d\n", S[n-1]);
  }
  return 0;
}
