#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  int N, M;
  while (cin >> N >> M) {
    if ((N|M) == 0)
      break;

    vector<int> P(N+1, 0);
    for (int i = 0; i < N; ++i)
      cin >> P[i];

    vector<int> PP;
    for (int i = 0; i < N+1; ++i) {
      for (int j = 0; j < N+1; ++j)
	PP.push_back(P[i]+P[j]);
    }
    sort(PP.begin(), PP.end());

    int ans = 0;
    for (int i = 0; i < PP.size(); ++i) {
      int tar = M - PP[i];
      vector<int>::iterator it = upper_bound(PP.begin(), PP.end(), tar);
      if (it != PP.begin())
	ans = max(ans, PP[i] + *(it-1));
    }
    cout << ans << endl;
  }
  return 0;
}
