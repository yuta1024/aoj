#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int K;

int solve(const vector<int>& A, const vector<int>& B, vector<int> C, int i, int k, int borrow)
{
  int ret = 0;
  if (i >= C.size()) {
    reverse(C.begin(), C.end());
    for (i = 0; i < 10; ++i) {
      ret *= 10;
      ret += C[i];
    }
    return ret;
  }

  if (A[i] - borrow >= B[i]) {
    C[i] = A[i] - borrow - B[i];
    ret = max(ret, solve(A, B, C, i+1, k, 0));
  } else {
    C[i] = A[i] - borrow + 10 - B[i];
    if (k < K)
      ret = max(ret, solve(A, B, C, i+1, k+1, 0));
    ret = max(ret, solve(A, B, C, i+1, k, 1));
  }
  return ret;
}

int main()
{
  string A, B;
  while (cin >> A >> B >> K) {
    vector<int> AA(10, 0), BB(10, 0), C(10, 0);
    for (int i = 0; i < A.size(); ++i)
      AA[i] = A[A.size()-i-1] - '0';
    for (int i = 0; i < B.size(); ++i)
      BB[i] = B[B.size()-i-1] - '0';

    cout << solve(AA, BB, C, 0, 0, 0) << endl;
  }
  return 0;
}
