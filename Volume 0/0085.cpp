#include <cstdio>
#include <list>
using namespace std;

int main()
{
  int n, m;
  while (~scanf("%d %d", &n, &m)) {
    if ((n|m) == 0)
      break;

    list<int> p;
    for (int i = 1; i <= n; ++i)
      p.push_back(i);

    int cnt = 1;
    list<int>::iterator it = p.begin();
    while (p.size() > 1) {
      if (cnt%m == 0) {
	it = p.erase(it);
	cnt = 0;
      } else {
	++it;
      }
      ++cnt;
      if (it == p.end())
	it = p.begin();
    }
    printf("%d\n", *p.begin());
  }
  return 0;
}
