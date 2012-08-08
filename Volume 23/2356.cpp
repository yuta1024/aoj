#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  string s;
  while (cin >> s) {
    vector<int> cnt(26, 0);
    for (unsigned int i = 0; i < s.size(); ++i)
      ++cnt[s[i]-'a'];

    int odd = 0;
    for (unsigned int i = 0; i < cnt.size(); ++i) {
      if (cnt[i] & 1)
	++odd;
    }

    long long int ans = 1LL;
    for (int i = 2; i <= s.size()/2; ++i)
      ans *= i;

    for (unsigned int i = 0; i < cnt.size(); ++i) {
      long long int fact = 1LL;
      for (int j = 2; j <= cnt[i]/2; ++j)
	fact *= j;
      ans /= fact;
    }

    if (odd > 1)
      ans = 0LL;
    cout << ans << endl;
  }
  return 0;
}
