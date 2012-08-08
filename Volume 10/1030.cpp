#include <cstdio>
#include <set>
using namespace std;

int main()
{
  int n, h;
  while (~scanf("%d %d\n", &n, &h)) {
    if (n == 0 && h == 0)
      break;
    char c1, c2;
    int a, b;
    pair<pair<int, int>, int> p;
    set<pair<pair<int, int>, int> > cnt;
    for (int i = 0; i < h; ++i) {
      scanf("%c%c %d %d\n", &c1, &c2, &a, &b);
      if (c1 == 'x') {
	if (c2 == 'y') {
	  p.first.first = a;
	  p.first.second = b;
	  for (int j = 1; j <= n; ++j) {
	    p.second = j;
	    cnt.insert(p);
	  }
	} else {
	  p.first.first = a;
	  p.second = b;
	  for (int j = 1; j <= n; ++j) {
	    p.first.second = j;
	    cnt.insert(p);
	  }
	}
      } else {
	  p.first.second = a;
	  p.second = b;
	  for (int j = 1; j <= n; ++j) {
	    p.first.first = j;
	    cnt.insert(p);
	  }
      }
    }

    printf("%d\n", n*n*n-cnt.size());
  }
  return 0;
}
