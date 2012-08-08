#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  vector<int> l(10);
  int v1, v2;
  while (scanf("%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d",
	       &l[0], &l[1], &l[2], &l[3], &l[4], &l[5], &l[6], &l[7], &l[8], &l[9], &v1, &v2) != EOF) {
    vector<double> ll(10);
    ll[0] = l[0];
    for (int i = 1; i < 10; ++i)
      ll[i] = ll[i-1] + l[i];

    double t = ll.back() / static_cast<double>(v1+v2);
    double d = t * v1;
    for (int i = 0; i < ll.size(); ++i) {
      if (d <= ll[i]) {
	printf("%d\n", i+1);
	break;
      }
    }
  }
  return 0;
}
