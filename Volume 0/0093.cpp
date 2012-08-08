#include <cstdio>

int main()
{
  int a, b;
  bool first = true;
  while (~scanf("%d %d", &a, &b)) {
    if ((a|b) == 0)
      break;

    if (!first)
      puts("");

    bool found = false;
    for (int i = a; i <= b; ++i) {
      if (i % 4 == 0 && (i % 100 != 0 || i % 400 == 0)) {
	printf("%d\n", i);
	found = true;
      }
    }

    if (!found)
      puts("NA");
    first = false;
  }
  return 0;
}
