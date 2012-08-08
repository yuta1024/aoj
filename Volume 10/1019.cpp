#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int N, K;
  while (cin >> N >> K) {
    if ((N|K) == 0)
      break;

    vector<int> S(K), B(K, 0);
    for (int i = 0; i < K; ++i)
      cin >> S[i];

    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < K; ++j) {
	int tmp;
	cin >> tmp;
	B[j] += tmp;
      }
    }

    bool valid = true;
    for (int i = 0; i < K && valid; ++i) {
      if (S[i] < B[i])
	valid = false;
    }

    if (valid)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
  return 0;
}
