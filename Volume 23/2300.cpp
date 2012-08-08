#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstdio>
using namespace std;

const double EPS = 1e-9;

typedef struct
{
  double L, a, b;
} LCS;

int main()
{
  int N, M;
  while (cin >> N >> M) {
    vector<LCS> lcs(N);
    for (int i = 0; i < N; ++i)
      cin >> lcs[i].L >> lcs[i].a >> lcs[i].b;

    double ans = 0.0;
    for (int i = 0; i < (1 << N); ++i) {
      if (__builtin_popcount(i) == M) {
	vector<int> idx;
	for (int j = 0; j < N; ++j) {
	  if (i & (1 << j))
	    idx.push_back(j);
	}

	double tmp = 0.0;
	for (unsigned int j = 0; j < idx.size(); ++j) {
	  for (unsigned int k = j+1; k < idx.size(); ++k) {
	    tmp += (lcs[idx[j]].L-lcs[idx[k]].L)*(lcs[idx[j]].L-lcs[idx[k]].L)
	      + (lcs[idx[j]].a-lcs[idx[k]].a)*(lcs[idx[j]].a-lcs[idx[k]].a)
	      + (lcs[idx[j]].b-lcs[idx[k]].b)*(lcs[idx[j]].b-lcs[idx[k]].b);
	  }
	}

	ans = max(ans, tmp);
      }
    }
    printf("%.20f\n", ans);
  }
  return 0;
}
