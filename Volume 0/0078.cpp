#include <cstdio>
#include <vector>
using namespace std;

int main()
{
  int n;
  while (~scanf("%d", &n)) {
    if (n == 0)
      break;

    int x = n/2, y = n/2+1;
    vector<vector<int > > ms(n, vector<int>(n, -1));
    for (int i = 1; i <= n*n; ++i) {
      while (x < 0 || x >= n || y >= n || ms[y][x] != -1) {
	if (x < 0)
	  x = n-1;
	if (x >= n)
	  x = 0;
	if (y >= n)
	  y = 0;

	if (ms[y][x] != -1) {
	  x -= 1;
	  y += 1;
	}
      }
      ms[y][x] = i;
      x += 1;
      y += 1;
    }

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
	printf("%4d", ms[i][j]);
      }
      puts("");
    }
  }
  return 0;
}
