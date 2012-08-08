#include <cstdio>
#include <vector>
#include <numeric>
using namespace std;

int main()
{
  int K;
  while (~scanf("%d", &K)) {
    if (K == 0)
      break;

    vector<int> c(K*(K-1)/2);
    for (int i = 0; i < K*(K-1)/2; ++i)
      scanf("%d", &c[i]);

    printf("%d\n", accumulate(c.begin(), c.end(), 0) / (K-1));
  }
  return 0;
}
