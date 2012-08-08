#include <cstdio>
#include <vector>
using namespace std;

int main()
{
  int n;
  while (~scanf("%d", &n)) {
    if (n == 0)
      break;

    vector<vector<int> > table(n+1, vector<int>(n+1));
    for (int i = 0; i < n; ++i) {
      int sum = 0;
      for (int j = 0; j < n; ++j) {
	scanf("%d", &table[i][j]);
	sum += table[i][j];
      }
      table[i][n] = sum;
    }

    for (int i = 0; i < n+1; ++i) {
      int sum = 0;
      for (int j = 0; j < n; ++j)
	sum += table[j][i];
      table[n][i] = sum;
    }

    for (int i = 0; i < n+1; ++i) {
      for (int j = 0; j < n+1; ++j)
	printf("%5d", table[i][j]);
      puts("");
    }
  }
  return 0;
}
