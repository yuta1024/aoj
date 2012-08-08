#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
  char s1, s2;
  bool boll[3];
  boll[0] = true;
  boll[1] = boll[2] = false;
  while (~scanf("%c,%c\n", &s1, &s2))
    swap(boll[s1-'A'], boll[s2-'A']);

  int ans = 0;
  for (int i = 0; i < 3; ++i) {
    if (boll[i])
      ans = i;
  }
  printf("%c\n", ans+'A');
  return 0;
}
