#include <cstdio>
#include <vector>
using namespace std;

int main()
{
  int n;
  while (~scanf("%d", &n)) {
    vector<int> g(6, 0);
    for (int i = 0; i < n; ++i) {
      double h;
      scanf("%lf", &h);
      if (h < 165.0)
	++g[0];
      else if (h < 170.0)
	++g[1];
      else if (h < 175.0)
	++g[2];
      else if (h < 180.0)
	++g[3];
      else if (h < 185.0)
	++g[4];
      else
	++g[5];
    }

    for (int i = 0; i < 6; ++i) {
      printf("%d:", i+1);
      for (int j = 0; j < g[i]; ++j)
	printf("*");
      puts("");
    }
  }
  return 0;
}
