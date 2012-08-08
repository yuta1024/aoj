#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  const int MAX_P = 60000;
  bool p[MAX_P];
  for (int i = 0; i < MAX_P; ++i)
    p[i] = true;
  p[0] = p[1] = false;

  for (int i = 2; i*i <= MAX_P; ++i) {
    if (p[i]) {
      for (int j = i+i; j < MAX_P; j += i)
	p[j] = false;
    }
  }

  vector<int> prime;
  for (int i = 0; i < MAX_P; ++i) {
    if (p[i])
      prime.push_back(i);
  }

  int n;
  while (~scanf("%d", &n)) {
    printf("%d %d\n", *(lower_bound(prime.begin(), prime.end(), n)-1),
	   *upper_bound(prime.begin(), prime.end(), n));
  }
  return 0;
}
