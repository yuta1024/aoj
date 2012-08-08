#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
  int a, b, c;
  while (cin >> a >> b >> c) {
    if ((a|b|c) == 0)
      break;

    if (c == 0) {
      if (a != 1)
	printf("%d %d %d %d\n", a, b, 1, 0);
      else
	printf("%d %d %d %d\n", 1, max(0, b), 1, min(0, b));
      continue;
    }

    bool found = false;
    for (int p = 1; p*p <= a && !found; ++p) {
      if (a%p != 0)
	continue;

      int r = a / p;
      for (int q = -abs(c); q <= abs(c) && !found; ++q) {
	if (q == 0 || c%q != 0)
	  continue;

	int s = c / q;
	if (r*s + q*p == b) {
	  found = true;
	  if (p == r)
	    printf("%d %d %d %d\n", max(p, r), max(q, s), min(p, r), min(q, s));
	  else
	    printf("%d %d %d %d\n", max(p, r), q, min(p, r), s);
	  break;
	}
      }
    }

    if (!found)
      puts("Impossible");
  }
  return 0;
}
