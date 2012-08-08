#include <cstdio>
#include <vector>
#include <string>
using namespace std;

int main()
{
  const int INF = 1 << 30;
  const int m[] = {4, 1, 4, 1, 2, 1, 2, 1};
  vector<int> p(8);
  while (~scanf("%d %d %d %d %d %d %d %d", &p[0], &p[1], &p[2], &p[3], &p[4], &p[5], &p[6], &p[7])) {
    int cnt = INF;
    string ans = "99999999";
    for (int i = 0; i < 8; ++i) {
      int tmp = 0;
      string ts = "";
      for (int j = 0; j < 8; ++j) {
	if (p[j] - m[(i+j)%8] > 0)
	  tmp += p[j] - m[(i+j)%8];
	ts += (m[(i+j)%8] + '0');
      }
      if (tmp < cnt) {
	cnt = tmp;
	ans = ts;
      } else if (tmp == cnt) {
	if (ts < ans)
	  ans = ts;
      }
    }

    for (int i = 0; i < 7; ++i)
      printf("%c ", ans[i]);
    printf("%c\n", ans[7]);
  }
  return 0;
}
