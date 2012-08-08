#include <cstdio>
#include <vector>

int main()
{
  const int cof[] = {10, 50, 100, 500};
  bool first = true;

  int pay;
  while (~scanf("%d",&pay)) {
    if (pay == 0)
      break;

    if (!first)
      puts("");
    first = false;

    int sum = 0;
    std::vector<int> c(4);
    for (int i = 0; i < 4; ++i) {
      scanf("%d", &c[i]);
      sum += c[i] * cof[i];
    }

    sum -= pay;
    for (int i = 3; i >= 0; --i) {
      int n = sum / cof[i];
      if (n > 0) {
	c[i] -= n;
	sum -= cof[i]*n;
      }
    }

    for (int i = 0; i < 4; ++i) {
      if (c[i] > 0)
	printf("%d %d\n", cof[i], c[i]);
    }
  }
  return 0;
}
