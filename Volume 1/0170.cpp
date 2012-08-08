#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const double EPS = 1e-10;

typedef struct
{
  string f;
  int w, s;
} Food;

int main()
{
  int n;
  while (cin >> n) {
    if (n == 0)
      break;

    vector<Food> foods(n);
    for (int i = 0; i < n; ++i)
      cin >> foods[i].f >> foods[i].w >> foods[i].s;

    vector<int> index(n);
    for (int i = 0; i < n; ++i)
      index[i] = i;

    double bestG = 1e10;
    vector<string> ans(n);
    do {
      int w = 0, kw = 0;
      bool valid = true;
      for (int i = 0; i < n && valid; ++i) {
	if (foods[index[i]].s < w)
	  valid = false;
	w += foods[index[i]].w;
	kw += (n-i) * foods[index[i]].w;
      }

      if (valid) {
	double G = kw * 1.0 / w;
	if (bestG - G > EPS) {
	  bestG = G;
	  for (int i = 0; i < n; ++i)
	    ans[i] = foods[index[i]].f;
	}
      }
    } while (next_permutation(index.begin(), index.end()));

    reverse(ans.begin(), ans.end());
    for (int i = 0; i < n; ++i)
      cout << ans[i] << endl;
  }
  return 0;
}
