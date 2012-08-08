#include <iostream>
using namespace std;

int n, s;

int solve(int i, int m, int t)
{
  if (m == n) {
    if (t == s)
      return 1;
    else
      return 0;
  }

  return solve(i+1, m, t) + solve(i+1, m+1, t+i);
}

int main()
{
  while (cin >> n >> s) {
    if (n == 0 && s == 0)
      break;
    cout << solve(0, 0, 0) << endl;
  }
  return 0;
}
