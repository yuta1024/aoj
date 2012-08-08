#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int N;
  while (cin >> N) {
    if (N == 0)
      break;

    vector<vector<int> > p(N);
    for (int i = 0; i < N; ++i) {
      int M;
      cin >> M;
      for (int j = 0; j < M; ++j) {
	int pij;
	cin >> pij;
	p[i].push_back(pij);
      }
    }

    int K;
    cin >> K;
    vector<int> l(K);
    for (int i = 0; i < K; ++i)
      cin >> l[i];

    int ans = 0;
    for (int i = 0; i < N; ++i) {
      int cnt = 0;
      for (int j = 0; j < K; ++j) {
	for (unsigned int k = 0; k < p[i].size(); ++k) {
	  if (l[j] == p[i][k])
	    ++cnt;
	}
      }
      if (cnt == K) {
	if (ans == 0)
	  ans = i+1;
	else
	  ans = -1;
      }
    }

    if (ans == 0)
      ans = -1;
    cout << ans << endl;
  }
  return 0;
}
