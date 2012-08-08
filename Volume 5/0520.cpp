#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve(int idx, const vector<int>& p, const vector<int>& q, const vector<int>& r, const vector<int>& b)
{
  int left = 1, right = 1;
  if (r[idx] != 0)
    left = solve(r[idx], p, q, r, b);
  if (b[idx] != 0)
    right = solve(b[idx], p, q, r, b);

  int left_p = left * p[idx];
  int right_p = right * q[idx];
  int lcm = left_p / __gcd(left_p, right_p) * right_p;  
  return lcm / p[idx] + lcm / q[idx];
}

int main()
{
  int n;
  while (cin >> n) {
    if (n == 0)
      break;

    vector<int> p(n+1), q(n+1), r(n+1), b(n+1), d(n+1, 0);
    for (int i = 1; i <= n; ++i) {
      cin >> p[i] >> q[i] >> r[i] >> b[i];
      d[r[i]] = d[b[i]] = 1;
    }

    int top = 0;
    for (int i = 1; i < n+1; ++i) {
      if (!d[i])
	top = i;
    }
 
    cout << solve(top, p, q, r, b) << endl;
  }
  return 0;
}
